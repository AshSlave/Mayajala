// Copyright AshSlave


#include "AbilitySystem/MayajalaAbilitySystemComponent.h"

void UMayajalaAbilitySystemComponent::AbilityActorInfoSet()
{
    OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UMayajalaAbilitySystemComponent::EffectApplied);
}

void UMayajalaAbilitySystemComponent::EffectApplied(UAbilitySystemComponent * AbilitySystemComponent, const FGameplayEffectSpec & EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
    FGameplayTagContainer TagContainer;
    EffectSpec.GetAllAssetTags(TagContainer);

    EffectAssetTags.Broadcast(TagContainer);
}