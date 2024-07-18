// Copyright AshSlave


#include "AbilitySystem/MayajalaAbilitySystemComponent.h"
#include "MayajalaGameplayTags.h"

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