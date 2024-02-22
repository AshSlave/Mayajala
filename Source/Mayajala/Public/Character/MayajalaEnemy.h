// Copyright AshSlave

#pragma once

#include "CoreMinimal.h"
#include "MayajalaCharacterBase.h"
#include "Interaction/TargetInterface.h"
#include "MayajalaEnemy.generated.h"

/**
 * 
 */
UCLASS()
class MAYAJALA_API AMayajalaEnemy : public AMayajalaCharacterBase, public ITargetInterface
{
	GENERATED_BODY()
public:
	AMayajalaEnemy();

	//~ Begin Enemy Interface
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	//~ End Enemy Interface
protected:
	virtual void BeginPlay() override;
};
