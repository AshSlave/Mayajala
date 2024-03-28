// Copyright AshSlave

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "MayajalaAttributeSet.generated.h"
 
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()

	FEffectProperties(){}

	FGameplayEffectContextHandle EffectContextHandle;

	UPROPERTY()
	UAbilitySystemComponent* SourceAbilitySystemComponent = nullptr;
	UPROPERTY()
	AActor* SourceAvatarActor = nullptr;
	UPROPERTY()
	AController* SourceController = nullptr;
	UPROPERTY()
	ACharacter* SourceCharacter = nullptr;

	UPROPERTY()
	UAbilitySystemComponent* TargetAbilitySystemComponent = nullptr;
	UPROPERTY()
	AActor* TargetAvatarActor = nullptr;
	UPROPERTY()
	AController* TargetController = nullptr;
	UPROPERTY()
	ACharacter* TargetCharacter = nullptr;
};

/**
 * 
 */
UCLASS()
class MAYAJALA_API UMayajalaAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	public:
	UMayajalaAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Attention, Category = "Core Attributes")
	FGameplayAttributeData Attention;
	ATTRIBUTE_ACCESSORS(UMayajalaAttributeSet, Attention);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxAttention, Category = "Core Attributes")
	FGameplayAttributeData MaxAttention;
	ATTRIBUTE_ACCESSORS(UMayajalaAttributeSet, MaxAttention);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Adrenaline, Category = "Core Attributes")
	FGameplayAttributeData Adrenaline;
	ATTRIBUTE_ACCESSORS(UMayajalaAttributeSet, Adrenaline);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxAdrenaline, Category = "Core Attributes")
	FGameplayAttributeData MaxAdrenaline;
	ATTRIBUTE_ACCESSORS(UMayajalaAttributeSet, MaxAdrenaline);

	UFUNCTION()
	void OnRep_Attention(const FGameplayAttributeData OldAttention) const;

	UFUNCTION()
	void OnRep_MaxAttention(const FGameplayAttributeData OldMaxAttention) const;

	UFUNCTION()
	void OnRep_Adrenaline(const FGameplayAttributeData OldAdrenaline) const;

	UFUNCTION()
	void OnRep_MaxAdrenaline(const FGameplayAttributeData OldMaxAdrenaline) const;

private:

	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;
};
