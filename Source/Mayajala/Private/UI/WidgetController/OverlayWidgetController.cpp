// Copyright AshSlave


#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/MayajalaAttributeSet.h"
#include "AbilitySystem/MayajalaAbilitySystemComponent.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
    const UMayajalaAttributeSet* MayajalaAttributeSet = CastChecked<UMayajalaAttributeSet>(AttributeSet);
    OnAttentionChanged.Broadcast(MayajalaAttributeSet->GetAttention());
    OnMaxAttentionChanged.Broadcast(MayajalaAttributeSet->GetMaxAttention());
    OnAdrenalineChanged.Broadcast(MayajalaAttributeSet->GetAdrenaline());
    OnMaxAdrenalineChanged.Broadcast(MayajalaAttributeSet->GetMaxAdrenaline());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
    const UMayajalaAttributeSet* MayajalaAttributeSet = CastChecked<UMayajalaAttributeSet>(AttributeSet);

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate( MayajalaAttributeSet->GetAttentionAttribute()).AddLambda(
        [this](const FOnAttributeChangeData& Data)
        {
            OnAttentionChanged.Broadcast(Data.NewValue);
        }
    );

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate( MayajalaAttributeSet->GetMaxAttentionAttribute()).AddLambda(
        [this](const FOnAttributeChangeData& Data)
        {
            OnMaxAttentionChanged.Broadcast(Data.NewValue);
        }
    );

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate( MayajalaAttributeSet->GetAdrenalineAttribute()).AddLambda(
        [this](const FOnAttributeChangeData& Data)
        {
            OnAdrenalineChanged.Broadcast(Data.NewValue);
        }
    );

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate( MayajalaAttributeSet->GetMaxAdrenalineAttribute()).AddLambda(
        [this](const FOnAttributeChangeData& Data)
        {
            OnMaxAdrenalineChanged.Broadcast(Data.NewValue);
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