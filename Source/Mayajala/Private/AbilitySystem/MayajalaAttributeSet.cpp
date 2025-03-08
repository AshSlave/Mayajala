// Copyright AshSlave


#include "AbilitySystem/MayajalaAttributeSet.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "GameFramework/Character.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"
#include "MayajalaGameplayTags.h"

UMayajalaAttributeSet::UMayajalaAttributeSet()
{
    const FMayajalaGameplayTags& GameplayTags = FMayajalaGameplayTags::Get();

    /* Primary Attributes */
    TagsToAttributes.Add(GameplayTags.Attributes_Primary_Physique, GetPhysiqueAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Primary_Intelligence, GetIntelligenceAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Primary_Resilience, GetResilienceAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Primary_Motorics, GetMotoricsAttribute);

    /* Secondary Attributes */
    TagsToAttributes.Add(GameplayTags.Attributes_Secondary_Endurance, GetEnduranceAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Secondary_Willpower, GetWillpowerAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Secondary_Dexterity, GetDexterityAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Secondary_Perception, GetPerceptionAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Secondary_Beauty, GetBeautyAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Secondary_Charisma, GetCharismaAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Secondary_Dodge, GetDodgeAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Secondary_Melee, GetMeleeAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Secondary_Throwing, GetThrowingAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Secondary_PickPocket, GetPickPocketAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Secondary_Prowling, GetProwlingAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Secondary_Haggle, GetHaggleAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Secondary_Medicine, GetMedicineAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Secondary_Persuasion, GetPersuasionAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Secondary_Repair, GetRepairAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Secondary_Firearms, GetFirearmsAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Secondary_PickLocks, GetPickLocksAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Secondary_ThrillThreshold, GetEnduranceAttribute);
}

void UMayajalaAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    // Primary Attributes

    DOREPLIFETIME_CONDITION_NOTIFY(UMayajalaAttributeSet, Physique, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UMayajalaAttributeSet, Intelligence, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UMayajalaAttributeSet, Resilience, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UMayajalaAttributeSet, Motorics, COND_None, REPNOTIFY_Always);

    // Secondary Attributes

    DOREPLIFETIME_CONDITION_NOTIFY(UMayajalaAttributeSet, Endurance, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UMayajalaAttributeSet, Willpower, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UMayajalaAttributeSet, Dexterity, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UMayajalaAttributeSet, Perception, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UMayajalaAttributeSet, Beauty, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UMayajalaAttributeSet, Charisma, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UMayajalaAttributeSet, Dodge, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UMayajalaAttributeSet, Melee, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UMayajalaAttributeSet, Throwing, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UMayajalaAttributeSet, PickPocket, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UMayajalaAttributeSet, Prowling, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UMayajalaAttributeSet, Haggle, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UMayajalaAttributeSet, Medicine, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UMayajalaAttributeSet, Persuasion, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UMayajalaAttributeSet, Repair, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UMayajalaAttributeSet, Firearms, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UMayajalaAttributeSet, PickLocks, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UMayajalaAttributeSet, MaxAdrenaline, COND_None, REPNOTIFY_Always);

    // Core Attributes

    DOREPLIFETIME_CONDITION_NOTIFY(UMayajalaAttributeSet, Attention, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UMayajalaAttributeSet, Distraction, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UMayajalaAttributeSet, Energy, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UMayajalaAttributeSet, Adrenaline, COND_None, REPNOTIFY_Always);
}

void UMayajalaAttributeSet::PreAttributeChange(const FGameplayAttribute & Attribute, float & NewValue)
{
    Super::PreAttributeChange(Attribute, NewValue);

    if (Attribute == GetAttentionAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.f, 1 - GetDistraction());
    }
    if (Attribute == GetAdrenalineAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.f, GetMaxAdrenaline());
    }
}

void UMayajalaAttributeSet::SetEffectProperties(const FGameplayEffectModCallbackData & Data, FEffectProperties & Props) const
{
    Props.EffectContextHandle = Data.EffectSpec.GetContext();
    Props.SourceAbilitySystemComponent = Props.EffectContextHandle.GetOriginalInstigatorAbilitySystemComponent();

    if (IsValid(Props.SourceAbilitySystemComponent) && Props.SourceAbilitySystemComponent->AbilityActorInfo.IsValid() && Props.SourceAbilitySystemComponent->AbilityActorInfo->AvatarActor.IsValid())
    {
        Props.SourceAvatarActor = Props.SourceAbilitySystemComponent->AbilityActorInfo->AvatarActor.Get();
        Props.SourceController = Props.SourceAbilitySystemComponent->AbilityActorInfo->PlayerController.Get();
        if (Props.SourceController == nullptr && Props.SourceAvatarActor != nullptr)
        {
            if (const APawn* Pawn = Cast<APawn>(Props.SourceAvatarActor))
            {
                Props.SourceController = Pawn->GetController();
            }
        }
        if (Props.SourceController)
        {
            Props.SourceCharacter = Cast<ACharacter>(Props.SourceController->GetPawn());
        }
    }

    if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
    {
        Props.TargetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
        Props.TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
        Props.TargetCharacter = Cast<ACharacter>(Props.TargetAvatarActor);
        Props.TargetAbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Props.TargetAvatarActor);
    }
}

void UMayajalaAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData & Data)
{
    Super::PostGameplayEffectExecute(Data);

    FEffectProperties Props;
    SetEffectProperties(Data, Props);

    if (Data.EvaluatedData.Attribute == GetAttentionAttribute())
    {
        SetAttention(FMath::Clamp(GetAttention(), 0.f, 1 - GetDistraction()));
        UE_LOG(LogTemp, Warning, TEXT("Changed Attention on %s, Attention: %f"), *Props.TargetAvatarActor->GetName(), GetAttention());
    }
    if (Data.EvaluatedData.Attribute == GetAdrenalineAttribute())
    {
        SetAdrenaline(FMath::Clamp(GetAdrenaline(), 0.f, GetMaxAdrenaline()));
    }
}

void UMayajalaAttributeSet::OnRep_Attention(const FGameplayAttributeData OldAttention) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMayajalaAttributeSet, Attention, OldAttention);
}

void UMayajalaAttributeSet::OnRep_Adrenaline(const FGameplayAttributeData OldAdrenaline) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMayajalaAttributeSet, Adrenaline, OldAdrenaline);
}

void UMayajalaAttributeSet::OnRep_Distraction(const FGameplayAttributeData OldDistraction) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMayajalaAttributeSet, Distraction, OldDistraction);
}

void UMayajalaAttributeSet::OnRep_Energy(const FGameplayAttributeData OldEnergy) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMayajalaAttributeSet, Energy, OldEnergy);
}

void UMayajalaAttributeSet::OnRep_Physique(const FGameplayAttributeData OldPhysique) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMayajalaAttributeSet, Physique, OldPhysique);
}

void UMayajalaAttributeSet::OnRep_Intelligence(const FGameplayAttributeData OldIntelligence) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMayajalaAttributeSet, Intelligence, OldIntelligence);
}

void UMayajalaAttributeSet::OnRep_Resilience(const FGameplayAttributeData OldResilience) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMayajalaAttributeSet, Resilience, OldResilience);
}

void UMayajalaAttributeSet::OnRep_Motorics(const FGameplayAttributeData OldMotorics) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMayajalaAttributeSet, Motorics, OldMotorics);
}

void UMayajalaAttributeSet::OnRep_Endurance(const FGameplayAttributeData OldEndurance) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMayajalaAttributeSet, Endurance, OldEndurance);
}

void UMayajalaAttributeSet::OnRep_Willpower(const FGameplayAttributeData OldWillpower) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMayajalaAttributeSet, Willpower, OldWillpower);
}

void UMayajalaAttributeSet::OnRep_Dexterity(const FGameplayAttributeData OldDexterity) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMayajalaAttributeSet, Dexterity, OldDexterity);
}

void UMayajalaAttributeSet::OnRep_Perception(const FGameplayAttributeData OldPerception) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMayajalaAttributeSet, Perception, OldPerception);
}

void UMayajalaAttributeSet::OnRep_Beauty(const FGameplayAttributeData OldBeauty) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMayajalaAttributeSet, Beauty, OldBeauty);
}

void UMayajalaAttributeSet::OnRep_Charisma(const FGameplayAttributeData OldCharisma) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMayajalaAttributeSet, Charisma, OldCharisma);
}

void UMayajalaAttributeSet::OnRep_Melee(const FGameplayAttributeData OldMelee) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMayajalaAttributeSet, Melee, OldMelee);
}

void UMayajalaAttributeSet::OnRep_Dodge(const FGameplayAttributeData OldDodge) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMayajalaAttributeSet, Dodge, OldDodge);
}

void UMayajalaAttributeSet::OnRep_Throwing(const FGameplayAttributeData OldThrowing) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMayajalaAttributeSet, Throwing, OldThrowing);
}

void UMayajalaAttributeSet::OnRep_PickPocket(const FGameplayAttributeData OldPickPocket) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMayajalaAttributeSet, PickPocket, OldPickPocket);
}

void UMayajalaAttributeSet::OnRep_Prowling(const FGameplayAttributeData OldProwling) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMayajalaAttributeSet, Prowling, OldProwling);
}

void UMayajalaAttributeSet::OnRep_Haggle(const FGameplayAttributeData OldHaggle) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMayajalaAttributeSet, Haggle, OldHaggle);
}

void UMayajalaAttributeSet::OnRep_Medicine(const FGameplayAttributeData OldMedicine) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMayajalaAttributeSet, Medicine, OldMedicine);
}

void UMayajalaAttributeSet::OnRep_Persuasion(const FGameplayAttributeData OldPersuasion) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMayajalaAttributeSet, Persuasion, OldPersuasion);
}

void UMayajalaAttributeSet::OnRep_Repair(const FGameplayAttributeData OldRepair) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMayajalaAttributeSet, Repair, OldRepair);
}

void UMayajalaAttributeSet::OnRep_Firearms(const FGameplayAttributeData OldFirearms) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMayajalaAttributeSet, Firearms, OldFirearms);
}

void UMayajalaAttributeSet::OnRep_PickLocks(const FGameplayAttributeData OldPickLocks) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMayajalaAttributeSet, PickLocks, OldPickLocks);
}

void UMayajalaAttributeSet::OnRep_MaxAdrenaline(const FGameplayAttributeData OldMaxAdrenaline) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMayajalaAttributeSet, MaxAdrenaline, OldMaxAdrenaline);
}