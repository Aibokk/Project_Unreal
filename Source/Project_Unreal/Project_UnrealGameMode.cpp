// Copyright Epic Games, Inc. All Rights Reserved.

#include "Project_UnrealGameMode.h"
#include "Project_UnrealCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProject_UnrealGameMode::AProject_UnrealGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
