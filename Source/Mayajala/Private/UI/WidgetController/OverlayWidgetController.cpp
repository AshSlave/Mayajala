// Copyright AshSlave


#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/MayajalaAttributeSet.h"

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

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
        MayajalaAttributeSet->GetAttentionAttribute()).AddUObject(this, &UOverlayWidgetController::AttentionChanged);

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
        MayajalaAttributeSet->GetMaxAttentionAttribute()).AddUObject(this, &UOverlayWidgetController::MaxAttentionChanged);

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
        MayajalaAttributeSet->GetAdrenalineAttribute()).AddUObject(this, &UOverlayWidgetController::AdrenalineChanged);

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
        MayajalaAttributeSet->GetMaxAdrenalineAttribute()).AddUObject(this, &UOverlayWidgetController::MaxAdrenalineChanged);
}

void UOverlayWidgetController::AttentionChanged(const FOnAttributeChangeData & Data) const
{
    OnAttentionChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxAttentionChanged(const FOnAttributeChangeData & Data) const
{
    OnMaxAttentionChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::AdrenalineChanged(const FOnAttributeChangeData & Data) const
{
    OnAdrenalineChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxAdrenalineChanged(const FOnAttributeChangeData & Data) const
{
    OnMaxAdrenalineChanged.Broadcast(Data.NewValue);
}