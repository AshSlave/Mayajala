// Copyright AshSlave


#include "AbilitySystem/MayajalaAttributeSet.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "GameFramework/Character.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UMayajalaAttributeSet::UMayajalaAttributeSet()
{
    InitAttention(0.5f);
    InitMaxAttention(1.f);
    InitAdrenaline(10.f);
    InitMaxAdrenaline(100.f);
}

void UMayajalaAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME_CONDITION_NOTIFY(UMayajalaAttributeSet, Attention, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UMayajalaAttributeSet, MaxAttention, COND_None, REPNOTIFY_Always);

    DOREPLIFETIME_CONDITION_NOTIFY(UMayajalaAttributeSet, Adrenaline, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UMayajalaAttributeSet, MaxAdrenaline, COND_None, REPNOTIFY_Always);
}

void UMayajalaAttributeSet::PreAttributeChange(const FGameplayAttribute & Attribute, float & NewValue)
{
    Super::PreAttributeChange(Attribute, NewValue);

    if (Attribute == GetAttentionAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.f, GetMaxAttention());
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
}

void UMayajalaAttributeSet::OnRep_Attention(const FGameplayAttributeData OldAttention) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMayajalaAttributeSet, Attention, OldAttention);
}

void UMayajalaAttributeSet::OnRep_MaxAttention(const FGameplayAttributeData OldMaxAttention) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMayajalaAttributeSet, MaxAttention, OldMaxAttention);
}

void UMayajalaAttributeSet::OnRep_Adrenaline(const FGameplayAttributeData OldAdrenaline) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMayajalaAttributeSet, Adrenaline, OldAdrenaline);
}

void UMayajalaAttributeSet::OnRep_MaxAdrenaline(const FGameplayAttributeData OldMaxAdrenaline) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UMayajalaAttributeSet, MaxAdrenaline, OldMaxAdrenaline);
}
