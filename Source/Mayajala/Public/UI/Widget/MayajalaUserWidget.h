// Copyright AshSlave

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MayajalaUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class MAYAJALA_API UMayajalaUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;
protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
