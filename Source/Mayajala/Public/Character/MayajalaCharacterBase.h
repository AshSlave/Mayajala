// Copyright AshSlave

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "MayajalaCharacterBase.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

UCLASS()
class MAYAJALA_API AMayajalaCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AMayajalaCharacterBase();
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;
	
	UPROPERTY();
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY();
	TObjectPtr<UAttributeSet> AttributeSet;

};
