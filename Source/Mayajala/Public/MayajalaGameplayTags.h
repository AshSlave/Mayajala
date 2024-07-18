// Copyright AshSlave

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * MayajalaGameplayTags
 * 
 * Singleton containing native Gameplay Tags
 */

struct FMayajalaGameplayTags
{
public:
	static const FMayajalaGameplayTags& Get() { return GameplayTags; }
	static void InitializeNativeGameplayTags();

    FGameplayTag Attributes_Primary_Physique;
    FGameplayTag Attributes_Primary_Intelligence;
    FGameplayTag Attributes_Primary_Resilience;
    FGameplayTag Attributes_Primary_Motorics;

    FGameplayTag Attributes_Secondary_Endurance;
    FGameplayTag Attributes_Secondary_Willpower;
    FGameplayTag Attributes_Secondary_Dexterity;
    FGameplayTag Attributes_Secondary_Perception;
    FGameplayTag Attributes_Secondary_Beauty;
    FGameplayTag Attributes_Secondary_Charisma;
    FGameplayTag Attributes_Secondary_Dodge;
    FGameplayTag Attributes_Secondary_Melee;
    FGameplayTag Attributes_Secondary_Throwing;
    FGameplayTag Attributes_Secondary_PickPocket;
    FGameplayTag Attributes_Secondary_Prowling;
    FGameplayTag Attributes_Secondary_Gambling;
    FGameplayTag Attributes_Secondary_Haggle;
    FGameplayTag Attributes_Secondary_Medicine;
    FGameplayTag Attributes_Secondary_Persuasion;
    FGameplayTag Attributes_Secondary_Repair;
    FGameplayTag Attributes_Secondary_Firearms;
    FGameplayTag Attributes_Secondary_PickLocks;
    FGameplayTag Attributes_Secondary_ThrillThreshold;
protected:

private:
	static FMayajalaGameplayTags GameplayTags;
};