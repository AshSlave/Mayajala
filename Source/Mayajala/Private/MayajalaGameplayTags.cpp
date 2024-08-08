// Copyright AshSlave


#include "MayajalaGameplayTags.h"
#include "GameplayTagsManager.h"

FMayajalaGameplayTags FMayajalaGameplayTags::GameplayTags;

void FMayajalaGameplayTags::InitializeNativeGameplayTags()
{
    /**
     * Primary Attributes
     */
    GameplayTags.Attributes_Primary_Physique = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Physique"), FString("General physical capability"));
    GameplayTags.Attributes_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Intelligence"), FString("General aptitude for intellectual tasks and learning"));
    GameplayTags.Attributes_Primary_Resilience = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Resilience"), FString("General ability to recover or adjust"));
    GameplayTags.Attributes_Primary_Motorics = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Motorics"), FString("General ability to sense and move"));

    /**
     * Secondary Attributes
     */
    GameplayTags.Attributes_Secondary_Endurance = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Endurance"), FString("Ability to endure physical hardships"));
    GameplayTags.Attributes_Secondary_Willpower = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Willpower"), FString("Ability to power through psychological hardships"));
    GameplayTags.Attributes_Secondary_Dexterity = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Dexterity"), FString("Fine motorics"));
    GameplayTags.Attributes_Secondary_Perception = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Perception"), FString("Awareness of the surroundings"));
    GameplayTags.Attributes_Secondary_Beauty = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Beauty"), FString("Physical beauty and understanding of how to keep it"));
    GameplayTags.Attributes_Secondary_Charisma = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Charisma"), FString("Ability to behave in a likeable manner"));
    GameplayTags.Attributes_Secondary_Dodge = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Dodge"), FString("Dodging skill"));
    GameplayTags.Attributes_Secondary_Melee = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Melee"), FString("General close combat skill"));
    GameplayTags.Attributes_Secondary_Throwing = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Throwing"), FString("Ability to throw objects"));
    GameplayTags.Attributes_Secondary_PickPocket = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.PickPocket"), FString("Skill of accessing other's pockets without notice"));
    GameplayTags.Attributes_Secondary_Prowling = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Prowling"), FString("Skill of hiding"));
    GameplayTags.Attributes_Secondary_Haggle = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Haggle"), FString("Skill of negotiating prices"));
    GameplayTags.Attributes_Secondary_Medicine = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Medicine"), FString("Ability to treat wounds"));
    GameplayTags.Attributes_Secondary_Persuasion = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Persuasion"), FString("Ability to convince"));
    GameplayTags.Attributes_Secondary_Repair = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Repair"), FString("Skill of repairing damaged items"));
    GameplayTags.Attributes_Secondary_Firearms = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Firearms"), FString("Understanding of usage and operation of firearms"));
    GameplayTags.Attributes_Secondary_PickLocks = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.PickLocks"), FString("Knowledge of locks and how to unlock them"));
    GameplayTags.Attributes_Secondary_ThrillThreshold = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.ThrillThreshold"), FString("Ability to utilizy fear and excitement"));

    /**
     * Input Tags
     */
    GameplayTags.InputTag_LMB = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.LMB"), FString("Input Tag for Left Mouse Button"));
    GameplayTags.InputTag_RMB = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.RMB"), FString("Input Tag for Right Mouse Button"));
    GameplayTags.InputTag_1 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.1"), FString("Input Tag for 1 key"));
    GameplayTags.InputTag_2 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.2"), FString("Input Tag for 2 key"));
    GameplayTags.InputTag_3 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.3"), FString("Input Tag for 3 key"));
    GameplayTags.InputTag_4 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("InputTag.4"), FString("Input Tag for 4 key"));
}