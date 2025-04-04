// Copyright AshSlave

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ActionInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType)
class UActionInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MAYAJALA_API IActionInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual FVector GetCombatSocketLocation();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateFacingTarget(const FVector& Target);
};
