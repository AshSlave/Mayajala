// Copyright AshSlave

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "UI/WidgetController/MayajalaWidgetController.h"
#include "OverlayWidgetController.generated.h"

 DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttentionChangedSignature, float, NewAttention);
 DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxAttentionChangedSignature, float, NewMaxAttention);
 DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAdrenalineChangedSignature, float, NewAdrenaline);
 DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxAdrenalineChangedSignature, float, NewMaxAdrenaline);
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class MAYAJALA_API UOverlayWidgetController : public UMayajalaWidgetController
{
	GENERATED_BODY()
public:
	virtual void BroadcastInitialValues() override;
	virtual void BindCallbacksToDependencies() override;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnAttentionChangedSignature OnAttentionChanged;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnMaxAttentionChangedSignature OnMaxAttentionChanged;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnAdrenalineChangedSignature OnAdrenalineChanged;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnMaxAdrenalineChangedSignature OnMaxAdrenalineChanged;

protected:
	void AttentionChanged(const FOnAttributeChangeData& Data) const;
	void MaxAttentionChanged(const FOnAttributeChangeData& Data) const;
	void AdrenalineChanged(const FOnAttributeChangeData& Data) const;
	void MaxAdrenalineChanged(const FOnAttributeChangeData& Data) const;
};
