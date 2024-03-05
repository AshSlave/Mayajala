// Copyright AshSlave


#include "AbilitySystem/MayajalaAttributeSet.h"
#include "Net/UnrealNetwork.h"

UMayajalaAttributeSet::UMayajalaAttributeSet()
{
    InitAttention(0.5f);
    InitMaxAttention(1.f);
    InitAdrenaline(100.f);
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
