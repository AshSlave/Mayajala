// Copyright AshSlave


#include "Player/MayajalaPlayerState.h"
#include "AbilitySystem/MayajalaAbilitySystemComponent.h"
#include "AbilitySystem/MayajalaAttributeSet.h"

AMayajalaPlayerState::AMayajalaPlayerState()
{
    AbilitySystemComponent = CreateDefaultSubobject<UMayajalaAbilitySystemComponent>("AbilitySystemComponent");
    AbilitySystemComponent->SetIsReplicated(true);
    AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

    AttributeSet = CreateDefaultSubobject<UMayajalaAttributeSet>("AttributeSet");

    NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* AMayajalaPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
