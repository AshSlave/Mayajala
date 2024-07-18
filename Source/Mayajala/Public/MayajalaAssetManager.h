// Copyright AshSlave

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "MayajalaAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class MAYAJALA_API UMayajalaAssetManager : public UAssetManager
{
	GENERATED_BODY()
public:

	static UMayajalaAssetManager& Get();

protected:

    virtual void StartInitialLoading() override;
};
