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

template<class T>
using TStaticFuncPtr = typename TBaseStaticDelegateInstance<T, FDefaultDelegateUserPolicy>::FFuncPtr;

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

	TMap<FGameplayTag, TStaticFuncPtr<FGameplayAttribute()>> TagsToAttributes;

	/**
	 * Primary Attributes
	*/

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Physique, Category = "Primary Attributes")
	FGameplayAttributeData Physique;
	ATTRIBUTE_ACCESSORS(UMayajalaAttributeSet, Physique);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Intelligence, Category = "Primary Attributes")
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UMayajalaAttributeSet, Intelligence);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Resilience, Category = "Primary Attributes")
	FGameplayAttributeData Resilience;
	ATTRIBUTE_ACCESSORS(UMayajalaAttributeSet, Resilience);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Motorics, Category = "Primary Attributes")
	FGameplayAttributeData Motorics;
	ATTRIBUTE_ACCESSORS(UMayajalaAttributeSet, Motorics);

	/**
	 * Secondary Attributes
	*/

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Endurance, Category = "Secondary Attributes")
	FGameplayAttributeData Endurance;
	ATTRIBUTE_ACCESSORS(UMayajalaAttributeSet, Endurance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Willpower, Category = "Secondary Attributes")
	FGameplayAttributeData Willpower;
	ATTRIBUTE_ACCESSORS(UMayajalaAttributeSet, Willpower);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Dexterity, Category = "Secondary Attributes")
	FGameplayAttributeData Dexterity;
	ATTRIBUTE_ACCESSORS(UMayajalaAttributeSet, Dexterity);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Perception, Category = "Secondary Attributes")
	FGameplayAttributeData Perception;
	ATTRIBUTE_ACCESSORS(UMayajalaAttributeSet, Perception);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Beauty, Category = "Secondary Attributes")
	FGameplayAttributeData Beauty;
	ATTRIBUTE_ACCESSORS(UMayajalaAttributeSet, Beauty);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Charisma, Category = "Secondary Attributes")
	FGameplayAttributeData Charisma;
	ATTRIBUTE_ACCESSORS(UMayajalaAttributeSet, Charisma);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Dodge, Category = "Secondary Attributes")
	FGameplayAttributeData Dodge;
	ATTRIBUTE_ACCESSORS(UMayajalaAttributeSet, Dodge);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Melee, Category = "Secondary Attributes")
	FGameplayAttributeData Melee;
	ATTRIBUTE_ACCESSORS(UMayajalaAttributeSet, Melee);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Throwing, Category = "Secondary Attributes")
	FGameplayAttributeData Throwing;
	ATTRIBUTE_ACCESSORS(UMayajalaAttributeSet, Throwing);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_PickPocket, Category = "Secondary Attributes")
	FGameplayAttributeData PickPocket;
	ATTRIBUTE_ACCESSORS(UMayajalaAttributeSet, PickPocket);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Prowling, Category = "Secondary Attributes")
	FGameplayAttributeData Prowling;
	ATTRIBUTE_ACCESSORS(UMayajalaAttributeSet, Prowling);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Haggle, Category = "Secondary Attributes")
	FGameplayAttributeData Haggle;
	ATTRIBUTE_ACCESSORS(UMayajalaAttributeSet, Haggle);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Medicine, Category = "Secondary Attributes")
	FGameplayAttributeData Medicine;
	ATTRIBUTE_ACCESSORS(UMayajalaAttributeSet, Medicine);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Persuasion, Category = "Secondary Attributes")
	FGameplayAttributeData Persuasion;
	ATTRIBUTE_ACCESSORS(UMayajalaAttributeSet, Persuasion);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Repair, Category = "Secondary Attributes")
	FGameplayAttributeData Repair;
	ATTRIBUTE_ACCESSORS(UMayajalaAttributeSet, Repair);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Firearms, Category = "Secondary Attributes")
	FGameplayAttributeData Firearms;
	ATTRIBUTE_ACCESSORS(UMayajalaAttributeSet, Firearms);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_PickLocks, Category = "Secondary Attributes")
	FGameplayAttributeData PickLocks;
	ATTRIBUTE_ACCESSORS(UMayajalaAttributeSet, PickLocks);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxAdrenaline, Category = "Secondary Attributes")
	FGameplayAttributeData MaxAdrenaline;
	ATTRIBUTE_ACCESSORS(UMayajalaAttributeSet, MaxAdrenaline);

	/**
	 * Core Attributes
	*/

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Attention, Category = "Core Attributes")
	FGameplayAttributeData Attention;
	ATTRIBUTE_ACCESSORS(UMayajalaAttributeSet, Attention);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Adrenaline, Category = "Core Attributes")
	FGameplayAttributeData Adrenaline;
	ATTRIBUTE_ACCESSORS(UMayajalaAttributeSet, Adrenaline);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Distraction, Category = "Core Attributes")
	FGameplayAttributeData Distraction;
	ATTRIBUTE_ACCESSORS(UMayajalaAttributeSet, Distraction);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Energy, Category = "Core Attributes")
	FGameplayAttributeData Energy;
	ATTRIBUTE_ACCESSORS(UMayajalaAttributeSet, Energy);

	UFUNCTION()
	void OnRep_Attention(const FGameplayAttributeData OldAttention) const;

	UFUNCTION()
	void OnRep_Adrenaline(const FGameplayAttributeData OldAdrenaline) const;

	UFUNCTION()
	void OnRep_Distraction(const FGameplayAttributeData OldDistraction) const;

	UFUNCTION()
	void OnRep_Energy(const FGameplayAttributeData OldEnergy) const;

	UFUNCTION()
	void OnRep_Physique(const FGameplayAttributeData OldPhysique) const;

	UFUNCTION()
	void OnRep_Intelligence(const FGameplayAttributeData OldIntelligence) const;

	UFUNCTION()
	void OnRep_Resilience(const FGameplayAttributeData OldResilience) const;

	UFUNCTION()
	void OnRep_Motorics(const FGameplayAttributeData OldMotorics) const;

	UFUNCTION()
	void OnRep_Endurance(const FGameplayAttributeData OldEndurance) const;

	UFUNCTION()
	void OnRep_Willpower(const FGameplayAttributeData OldWillpower) const;

	UFUNCTION()
	void OnRep_Dexterity(const FGameplayAttributeData OldDexterity) const;

	UFUNCTION()
	void OnRep_Perception(const FGameplayAttributeData OldPerception) const;

	UFUNCTION()
	void OnRep_Beauty(const FGameplayAttributeData OldBeauty) const;

	UFUNCTION()
	void OnRep_Charisma(const FGameplayAttributeData OldCharisma) const;

	UFUNCTION()
	void OnRep_Dodge(const FGameplayAttributeData OldDodge) const;

	UFUNCTION()
	void OnRep_Melee(const FGameplayAttributeData OldMelee) const;

	UFUNCTION()
	void OnRep_Throwing(const FGameplayAttributeData OldThrowing) const;

	UFUNCTION()
	void OnRep_PickPocket(const FGameplayAttributeData OldPickPocket) const;

	UFUNCTION()
	void OnRep_Prowling(const FGameplayAttributeData OldProwling) const;

	UFUNCTION()
	void OnRep_Haggle(const FGameplayAttributeData OldHaggle) const;

	UFUNCTION()
	void OnRep_Medicine(const FGameplayAttributeData OldMedicine) const;

	UFUNCTION()
	void OnRep_Persuasion(const FGameplayAttributeData OldPersuasion) const;

	UFUNCTION()
	void OnRep_Repair(const FGameplayAttributeData OldRepair) const;

	UFUNCTION()
	void OnRep_Firearms(const FGameplayAttributeData OldFirearms) const;

	UFUNCTION()
	void OnRep_PickLocks(const FGameplayAttributeData OldPickLocks) const;

	UFUNCTION()
	void OnRep_MaxAdrenaline(const FGameplayAttributeData OldMaxAdrenaline) const;

private:

	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;
};
