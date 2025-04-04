// Copyright AshSlave


#include "Character/MayajalaCharacterBase.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/MayajalaAbilitySystemComponent.h"
#include "Components/CapsuleComponent.h"
#include "Mayajala/Mayajala.h"

AMayajalaCharacterBase::AMayajalaCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	GetCapsuleComponent()->SetGenerateOverlapEvents(false);
	GetMesh()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	GetMesh()->SetCollisionResponseToChannel(ECC_Projectile, ECR_Overlap);
	GetMesh()->SetGenerateOverlapEvents(true);

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

FVector AMayajalaCharacterBase::GetCombatSocketLocation()
{
	check(Weapon);
    return Weapon->GetSocketLocation(WeaponTipSocketName);
}

void AMayajalaCharacterBase::InitAbilityActorInfo()
{
}

void AMayajalaCharacterBase::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(GameplayEffectClass);
	FGameplayEffectContextHandle ContextHandle = AbilitySystemComponent->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass, Level, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

void AMayajalaCharacterBase::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultPrimaryAttributes, 1);
	ApplyEffectToSelf(DefaultSecondaryAttributes, 1);
	ApplyEffectToSelf(DefaultCoreAttributes, 1);
}

void AMayajalaCharacterBase::AddCharacterAbilities()
{
	UMayajalaAbilitySystemComponent* MayajalaASC = CastChecked<UMayajalaAbilitySystemComponent>(AbilitySystemComponent);
	if (!HasAuthority()) return;

	MayajalaASC->AddCharacterAbilities(StartupAbilities);
}