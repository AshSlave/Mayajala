// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MayajalaCharacterBase.generated.h"

UCLASS()
class MAYAJALA_API AMayajalaCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AMayajalaCharacterBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

};
