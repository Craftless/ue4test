// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameJamIdea1GameMode.h"
#include "GameJamIdea1HUD.h"
#include "GameJamIdea1Character.h"
#include "UObject/ConstructorHelpers.h"

AGameJamIdea1GameMode::AGameJamIdea1GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AGameJamIdea1HUD::StaticClass();
}
