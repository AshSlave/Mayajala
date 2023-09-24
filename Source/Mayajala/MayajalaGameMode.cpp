// Copyright Epic Games, Inc. All Rights Reserved.

#include "MayajalaGameMode.h"
#include "Character/MayajalaCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMayajalaGameMode::AMayajalaGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
