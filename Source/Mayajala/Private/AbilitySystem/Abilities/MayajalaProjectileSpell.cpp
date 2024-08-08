// Copyright AshSlave


#include "AbilitySystem/Abilities/MayajalaProjectileSpell.h"
#include "Actor/MayajalaProjectile.h"
#include "Interaction/ActionInterface.h"

void UMayajalaProjectileSpell::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo *ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData *TriggerEventData)
{
    Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

    const bool bIsServer = HasAuthority(&ActivationInfo);
    if (!bIsServer) return;

    IActionInterface* ActionInterface = Cast<IActionInterface>(GetAvatarActorFromActorInfo());
    if (ActionInterface)
    {
        const FVector SocketLocation = ActionInterface->GetCombatSocketLocation();

        FTransform SpawnTransform;
        SpawnTransform.SetLocation(SocketLocation);
        //TODO: Set the Projectile Rotation

        AMayajalaProjectile* Projectile = GetWorld()->SpawnActorDeferred<AMayajalaProjectile>(ProjectileClass, SpawnTransform, GetOwningActorFromActorInfo(), Cast<APawn>(GetOwningActorFromActorInfo()), ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

        //TODO: Give the Projectile a Gameplay Effect Spec for causing Damage.
        Projectile->FinishSpawning(SpawnTransform);
    }
}