// Copyright Epic Games, Inc. All Rights Reserved.

#include "duckGameMode.h"
#include "duckCharacter.h"
#include "UObject/ConstructorHelpers.h"

AduckGameMode::AduckGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
