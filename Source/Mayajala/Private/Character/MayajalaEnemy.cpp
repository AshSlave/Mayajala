// Copyright AshSlave


#include "Character/MayajalaEnemy.h"
#include "AbilitySystem/MayajalaAbilitySystemComponent.h"
#include "AbilitySystem/MayajalaAttributeSet.h"
#include "UI/Widget/MayajalaUserWidget.h"
#include "Components/WidgetComponent.h"
#include "Mayajala/Mayajala.h"

AMayajalaEnemy::AMayajalaEnemy()
{
    GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
    
    AbilitySystemComponent = CreateDefaultSubobject<UMayajalaAbilitySystemComponent>("AbilitySystemComponent");
    AbilitySystemComponent->SetIsReplicated(true);
    AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

    AttributeSet = CreateDefaultSubobject<UMayajalaAttributeSet>("AttributeSet");

    AttentionBar = CreateDefaultSubobject<UWidgetComponent>("AttentionBar");
    AttentionBar->SetupAttachment(GetRootComponent());
}

void AMayajalaEnemy::BeginPlay()
{
    Super::BeginPlay();
    InitAbilityActorInfo();

    if (UMayajalaUserWidget* MayajalaUserWidget = Cast<UMayajalaUserWidget>(AttentionBar->GetUserWidgetObject()))
    {
        MayajalaUserWidget->SetWidgetController(this);
    }

    if (const UMayajalaAttributeSet* MayajalaAS = Cast<UMayajalaAttributeSet>(AttributeSet))
    {
        AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(MayajalaAS->GetAttentionAttribute()).AddLambda(
            [this](const FOnAttributeChangeData& Data)
            {
                OnAttentionChanged.Broadcast(Data.NewValue);
            }
        );

        OnAttentionChanged.Broadcast(MayajalaAS->GetAttention());
    }
}

void AMayajalaEnemy::HighlightActor()
{
    GetMesh()->SetRenderCustomDepth(true);
    Weapon->SetRenderCustomDepth(true);
    GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_PURPLE);
    Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_PURPLE);
}

void AMayajalaEnemy::UnHighlightActor()
{
    GetMesh()->SetRenderCustomDepth(false);
    Weapon->SetRenderCustomDepth(false);
}

void AMayajalaEnemy::InitAbilityActorInfo()
{
    AbilitySystemComponent->InitAbilityActorInfo(this, this);
    Cast<UMayajalaAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();

    InitializeDefaultAttributes();
}