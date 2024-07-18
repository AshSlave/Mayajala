// Copyright AshSlave


#include "UI/WidgetController/AttributeMenuWidgetController.h"
#include "AbilitySystem/MayajalaAttributeSet.h"
#include "AbilitySystem/Data/AttributeInfo.h"

void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
    UMayajalaAttributeSet* AS = CastChecked<UMayajalaAttributeSet>(AttributeSet);
    check(AttributeInfo);
    for (auto& Pair : AS->TagsToAttributes)
    {
        AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Value()).AddLambda(
            [this, Pair](const FOnAttributeChangeData& Data)
            {
                BroadcastAttributeInfo(Pair.Key, Pair.Value());
            }
        );
    }
}

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
    UMayajalaAttributeSet* AS = CastChecked<UMayajalaAttributeSet>(AttributeSet);
    check(AttributeInfo);
    
    for (auto& Pair : AS->TagsToAttributes)
    {
        BroadcastAttributeInfo(Pair.Key, Pair.Value());
    }
}

void UAttributeMenuWidgetController::BroadcastAttributeInfo(const FGameplayTag &AttributeTag, const FGameplayAttribute &Attribute) const
{
    FMayajalaAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(AttributeTag);
    Info.AttributeValue = Attribute.GetNumericValue(AttributeSet);
    AttributeInfoDelegate.Broadcast(Info);
}