// Copyright AshSlave


#include "AbilitySystem/MayajalaAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/MayajalaGameplayAbility.h"
#include "MayajalaGameplayTags.h"

void UMayajalaAbilitySystemComponent::AbilityActorInfoSet()
{
    OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UMayajalaAbilitySystemComponent::ClientEffectApplied);
}

void UMayajalaAbilitySystemComponent::AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>> &StartupAbilities)
{
    for (TSubclassOf<UGameplayAbility> AbilityClass : StartupAbilities)
    {
        FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);
        if (const UMayajalaGameplayAbility* MayajalaAbility = Cast<UMayajalaGameplayAbility>(AbilitySpec.Ability))
        {
            AbilitySpec.DynamicAbilityTags.AddTag(MayajalaAbility->StartupInputTag);
            GiveAbility(AbilitySpec);
        }
    }
}

void UMayajalaAbilitySystemComponent::AbilityInputTagHeld(const FGameplayTag &InputTag)
{
    if (!InputTag.IsValid()) return;

    for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
    {
        if (AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag))
        {
            AbilitySpecInputPressed(AbilitySpec);
            if (!AbilitySpec.IsActive())
            {
                TryActivateAbility(AbilitySpec.Handle);
            }
        }
    }
}

void UMayajalaAbilitySystemComponent::AbilityInputTagReleased(const FGameplayTag &InputTag)
{
    if (!InputTag.IsValid()) return;

    for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
    {
        if (AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag))
        {
            AbilitySpecInputReleased(AbilitySpec);
        }
    }
}

void UMayajalaAbilitySystemComponent::ClientEffectApplied_Implementation(UAbilitySystemComponent * AbilitySystemComponent, const FGameplayEffectSpec & EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
    FGameplayTagContainer TagContainer;
    EffectSpec.GetAllAssetTags(TagContainer);

    EffectAssetTags.Broadcast(TagContainer);
}