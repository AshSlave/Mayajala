// Copyright AshSlave

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MayajalaPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class ITargetInterface;

/**
 * 
 */
UCLASS()
class MAYAJALA_API AMayajalaPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AMayajalaPlayerController();
	virtual void PlayerTick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> MayajalaContext;
	
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const FInputActionValue& InputActionValue);

	void CursorTrace();
	ITargetInterface* LastActor;
	ITargetInterface* ThisActor;
};
