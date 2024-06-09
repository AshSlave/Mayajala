// Copyright AshSlave


#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/MayajalaAttributeSet.h"
#include "AbilitySystem/MayajalaAbilitySystemComponent.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
    const UMayajalaAttributeSet* MayajalaAttributeSet = CastChecked<UMayajalaAttributeSet>(AttributeSet);
    OnAttentionChanged.Broadcast(MayajalaAttributeSet->GetAttention());
    OnAdrenalineChanged.Broadcast(MayajalaAttributeSet->GetAdrenaline());
    OnMaxAdrenalineChanged.Broadcast(MayajalaAttributeSet->GetMaxAdrenaline());
    OnDistractionChanged.Broadcast(MayajalaAttributeSet->GetDistraction());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
    const UMayajalaAttributeSet* MayajalaAttributeSet = CastChecked<UMayajalaAttributeSet>(AttributeSet);

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(MayajalaAttributeSet->GetAttentionAttribute()).AddLambda(
        [this](const FOnAttributeChangeData& Data)
        {
            OnAttentionChanged.Broadcast(Data.NewValue);
        }
    );

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(MayajalaAttributeSet->GetAdrenalineAttribute()).AddLambda(
        [this](const FOnAttributeChangeData& Data)
        {
            OnAdrenalineChanged.Broadcast(Data.NewValue);
        }
    );

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(MayajalaAttributeSet->GetMaxAdrenalineAttribute()).AddLambda(
        [this](const FOnAttributeChangeData& Data)
        {
            OnMaxAdrenalineChanged.Broadcast(Data.NewValue);
        }
    );

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(MayajalaAttributeSet->GetDistractionAttribute()).AddLambda(
        [this](const FOnAttributeChangeData& Data)
        {
            OnDistractionChanged.Broadcast(Data.NewValue);
        }
    );

    Cast<UMayajalaAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
        [this](const FGameplayTagContainer& AssetTags)
        {
            for (const FGameplayTag& Tag : AssetTags)
            {
                FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
                if (Tag.MatchesTag(MessageTag))
                {
                    const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
                    MessageWidgetRowDelegate.Broadcast(*Row);
                }
            }
        }
    );
}