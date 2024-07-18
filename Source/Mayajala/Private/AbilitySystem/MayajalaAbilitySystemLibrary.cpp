// Copyright AshSlave


#include "AbilitySystem/MayajalaAbilitySystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "UI/WidgetController/MayajalaWidgetController.h"
#include "Player/MayajalaPlayerState.h"
#include "UI/HUD/MayajalaHUD.h"

UOverlayWidgetController *UMayajalaAbilitySystemLibrary::GetOverlayWidgetController(const UObject *WorldContextObject)
{
    if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
    {
        if (AMayajalaHUD* MayajalaHUD = Cast<AMayajalaHUD>(PC->GetHUD()))
        {
            AMayajalaPlayerState* PS = PC->GetPlayerState<AMayajalaPlayerState>();
            UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
            UAttributeSet* AS = PS->GetAttributeSet();
            const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
            return MayajalaHUD->GetOverlayWidgetController(WidgetControllerParams);
        }
    }
    return nullptr;
}

UAttributeMenuWidgetController *UMayajalaAbilitySystemLibrary::GetAttributeMenuWidgetController(const UObject *WorldContextObject)
{
    if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
    {
        if (AMayajalaHUD* MayajalaHUD = Cast<AMayajalaHUD>(PC->GetHUD()))
        {
            AMayajalaPlayerState* PS = PC->GetPlayerState<AMayajalaPlayerState>();
            UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
            UAttributeSet* AS = PS->GetAttributeSet();
            const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
            return MayajalaHUD->GetAttributeMenuWidgetController(WidgetControllerParams);
        }
    }
    return nullptr;
}