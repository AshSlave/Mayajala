// Copyright AshSlave


#include "Player/MayajalaPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Input/MayajalaInputComponent.h"
#include "Interaction/TargetInterface.h"
#include "AbilitySystem/MayajalaAbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Components/SplineComponent.h"
#include "MayajalaGameplayTags.h"
#include "NavigationSystem.h"
#include "NavigationPath.h"

AMayajalaPlayerController::AMayajalaPlayerController()
{
    bReplicates = true;
    Spline = CreateDefaultSubobject<USplineComponent>("Spline");
}

void AMayajalaPlayerController::PlayerTick(float DeltaTime)
{
    Super::PlayerTick(DeltaTime);
    CursorTrace();
    AutoRun();
}

void AMayajalaPlayerController::AutoRun()
{
    if (!bAutoRunning) return;
    if (APawn* ControlledPawn = GetPawn())
    {
        const FVector LocationOnSpline = Spline->FindLocationClosestToWorldLocation(ControlledPawn->GetActorLocation(), ESplineCoordinateSpace::World);
        const FVector Direction = Spline->FindDirectionClosestToWorldLocation(LocationOnSpline, ESplineCoordinateSpace::World);
        ControlledPawn->AddMovementInput(Direction);

        const float DistanceToDestination = (LocationOnSpline - CachedDestination).Length();
        if (DistanceToDestination <= AutoRunAcceptanceRadius)
        {
            bAutoRunning = false;
        }
    }
}

void AMayajalaPlayerController::CursorTrace()
{
    GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
    if (!CursorHit.bBlockingHit) return;

    LastActor = ThisActor;
    ThisActor = Cast<ITargetInterface>(CursorHit.GetActor());
    
    if (LastActor != ThisActor)
    {
        if (LastActor) LastActor->UnHighlightActor();
        if (ThisActor) ThisActor->HighlightActor();
    }
}

void AMayajalaPlayerController::AbilityInputTagPressed(FGameplayTag InputTag)
{
    if (InputTag.MatchesTagExact(FMayajalaGameplayTags::Get().InputTag_LMB))
    {
        bTargeting = ThisActor ? true : false;
        bAutoRunning = false;
    }
}

void AMayajalaPlayerController::AbilityInputTagReleased(FGameplayTag InputTag)
{
    if (!InputTag.MatchesTagExact(FMayajalaGameplayTags::Get().InputTag_LMB) || bTargeting)
    {
        if (GetASC()) GetASC()->AbilityInputTagReleased(InputTag);
    }
    else
    {
        const APawn* ControlledPawn = GetPawn();
        if (FollowTime <= ShortPressThreshold && ControlledPawn)
        {
            if (UNavigationPath* NavPath = UNavigationSystemV1::FindPathToLocationSynchronously(this, ControlledPawn->GetActorLocation(), CachedDestination))
            {
                Spline->ClearSplinePoints();
                for (const FVector& PointLoc : NavPath->PathPoints)
                {
                    Spline->AddSplinePoint(PointLoc, ESplineCoordinateSpace::World);
                }
                CachedDestination = NavPath->PathPoints[NavPath->PathPoints.Num() -1];
                bAutoRunning = true;
            }
        }
        FollowTime = 0.f;
        bTargeting = false;
    }
}

void AMayajalaPlayerController::AbilityInputTagHeld(FGameplayTag InputTag)
{
    if (!InputTag.MatchesTagExact(FMayajalaGameplayTags::Get().InputTag_LMB) || bTargeting)
    {
        if (GetASC()) GetASC()->AbilityInputTagHeld(InputTag);
    }
    else
    {
        FollowTime += GetWorld()->GetDeltaSeconds();
        if (CursorHit.bBlockingHit) CachedDestination = CursorHit.ImpactPoint;

        if (APawn* ControlledPawn = GetPawn())
        {
            const FVector WorldDirection = (CachedDestination - ControlledPawn->GetActorLocation()).GetSafeNormal();
            ControlledPawn->AddMovementInput(WorldDirection);
        }
    }
}

UMayajalaAbilitySystemComponent *AMayajalaPlayerController::GetASC()
{
    if (MayajalaAbilitySystemComponent == nullptr)
    {
        MayajalaAbilitySystemComponent = Cast<UMayajalaAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn<APawn>()));
    }
    return MayajalaAbilitySystemComponent;
}

void AMayajalaPlayerController::BeginPlay()
{
    Super::BeginPlay();
    check(MayajalaContext);

    UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
    if (Subsystem)
    {
        Subsystem->AddMappingContext(MayajalaContext, 0);
    }

    bShowMouseCursor = true;
    DefaultMouseCursor = EMouseCursor::Default;

    FInputModeGameAndUI InputModeData;
    InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
    InputModeData.SetHideCursorDuringCapture(false);
    SetInputMode(InputModeData);
}

void AMayajalaPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    UMayajalaInputComponent* MayajalaInputComponent = CastChecked<UMayajalaInputComponent>(InputComponent);
    MayajalaInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMayajalaPlayerController::Move);
    MayajalaInputComponent->BindAbilityActions(InputConfig, this, &ThisClass::AbilityInputTagPressed, &ThisClass::AbilityInputTagReleased, &ThisClass::AbilityInputTagHeld);
}

void AMayajalaPlayerController::Move(const FInputActionValue &InputActionValue)
{
    const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
    const FRotator YawRotation(0.f, GetControlRotation().Yaw, 0.f);

    const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
    const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

    if (APawn* ControlledPawn = GetPawn<APawn>())
    {
        ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
        ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
    }
}
