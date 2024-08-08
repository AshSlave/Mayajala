// Copyright AshSlave

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/MayajalaGameplayAbility.h"
#include "MayajalaProjectileSpell.generated.h"

class AMayajalaProjectile;
/**
 * 
 */
UCLASS()
class MAYAJALA_API UMayajalaProjectileSpell : public UMayajalaGameplayAbility
{
	GENERATED_BODY()

protected:

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AMayajalaProjectile> ProjectileClass;
};
