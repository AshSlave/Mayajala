// Copyright AshSlave


#include "MayajalaAssetManager.h"
#include "MayajalaGameplayTags.h"

UMayajalaAssetManager &UMayajalaAssetManager::Get()
{
    check(GEngine);

    UMayajalaAssetManager* MayajalaAssetManager = Cast<UMayajalaAssetManager>(GEngine->AssetManager);
    return *MayajalaAssetManager;
}

void UMayajalaAssetManager::StartInitialLoading()
{
    Super::StartInitialLoading();

    FMayajalaGameplayTags::InitializeNativeGameplayTags();
}
