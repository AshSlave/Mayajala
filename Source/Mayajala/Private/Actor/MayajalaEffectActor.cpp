// Copyright AshSlave


#include "Actor/MayajalaEffectActor.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/MayajalaAttributeSet.h"
#include "Components/SphereComponent.h"

AMayajalaEffectActor::AMayajalaEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
}

//TODO: Change this to apply a Gameplay Effect. For now, using const_cast as a hack!
void AMayajalaEffectActor::OnOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UMayajalaAttributeSet* MayajalaAttributeSet = Cast<UMayajalaAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UMayajalaAttributeSet::StaticClass()));

		UMayajalaAttributeSet* MutableMayajalaAttributeSet = const_cast<UMayajalaAttributeSet*>(MayajalaAttributeSet);
		MutableMayajalaAttributeSet->SetAttention(MayajalaAttributeSet->GetAttention() + 0.25f);
		MutableMayajalaAttributeSet->SetAdrenaline(MayajalaAttributeSet->GetAdrenaline() - 25.f);
		Destroy();
	}
}

void AMayajalaEffectActor::EndOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
}

void AMayajalaEffectActor::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AMayajalaEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AMayajalaEffectActor::EndOverlap);	
}

