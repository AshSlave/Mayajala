// Copyright AshSlave

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MayajalaProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

UCLASS()
class MAYAJALA_API AMayajalaProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AMayajalaProjectile();

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UProjectileMovementComponent> ProjectileMovement;

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnSphereOverlap(UPrimitiveComponent* OverlapComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
private:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> Sphere;
};
