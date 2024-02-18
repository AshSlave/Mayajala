// Copyright AshSlave


#include "Character/MayajalaCharacterBase.h"

// Sets default values
AMayajalaCharacterBase::AMayajalaCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

void AMayajalaCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}
