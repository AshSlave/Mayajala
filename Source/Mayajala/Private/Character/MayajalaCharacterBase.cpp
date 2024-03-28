// Copyright AshSlave


#include "Character/MayajalaCharacterBase.h"

AMayajalaCharacterBase::AMayajalaCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

UAbilitySystemComponent* AMayajalaCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AMayajalaCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}
