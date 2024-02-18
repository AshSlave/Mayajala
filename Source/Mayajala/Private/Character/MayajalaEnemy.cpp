// Copyright AshSlave


#include "Character/MayajalaEnemy.h"
#include "Mayajala/Mayajala.h"

AMayajalaEnemy::AMayajalaEnemy()
{
    GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
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
