// Copyright AshSlave


#include "Character/MayajalaEnemy.h"
#include "AbilitySystem/MayajalaAbilitySystemComponent.h"
#include "AbilitySystem/MayajalaAttributeSet.h"
#include "Mayajala/Mayajala.h"

AMayajalaEnemy::AMayajalaEnemy()
{
    GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
    
    AbilitySystemComponent = CreateDefaultSubobject<UMayajalaAbilitySystemComponent>("AbilitySystemComponent");
    AbilitySystemComponent->SetIsReplicated(true);
    AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

    AttributeSet = CreateDefaultSubobject<UMayajalaAttributeSet>("AttributeSet");
}

void AMayajalaEnemy::BeginPlay()
{
    Super::BeginPlay();
    AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

void AMayajalaEnemy::HighlightActor()
{
    GetMesh()->SetRenderCustomDepth(true);
    Weapon->SetRenderCustomDepth(true);
    GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_PURPLE);
    Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_PURPLE);
}

void AMayajalaEnemy::UnHighlightActor()
{
    GetMesh()->SetRenderCustomDepth(false);
    Weapon->SetRenderCustomDepth(false);
}
