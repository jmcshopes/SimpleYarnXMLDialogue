// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "SimpleDialogueGameMode.h"
#include "SimpleDialoguePlayerController.h"
#include "SimpleDialogueCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASimpleDialogueGameMode::ASimpleDialogueGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ASimpleDialoguePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}