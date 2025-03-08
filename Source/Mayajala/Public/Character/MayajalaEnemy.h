// Copyright AshSlave

#pragma once

#include "CoreMinimal.h"
#include "MayajalaCharacterBase.h"
#include "Interaction/TargetInterface.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "MayajalaEnemy.generated.h"

class UWidgetComponent;
/**
 * 
 */
UCLASS()
class MAYAJALA_API AMayajalaEnemy : public AMayajalaCharacterBase, public ITargetInterface
{
	GENERATED_BODY()
public:
	AMayajalaEnemy();

	//~ Begin Enemy Interface
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	//~ End Enemy Interface

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnAttentionChanged;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnMaxAttentionChanged;

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UWidgetComponent> AttentionBar;
};
