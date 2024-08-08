// Copyright AshSlave

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "MayajalaGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class MAYAJALA_API UMayajalaGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
public:

	UPROPERTY(EditDefaultsOnly, Category="Input")
	FGameplayTag StartupInputTag;
};
