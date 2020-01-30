// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameModeBase.h"
#include "MyPlayerController.h"
#include "ConstructorHelpers.h"

AMyGameModeBase::AMyGameModeBase()
{
	ConstructorHelpers::FClassFinder<AMyPlayerController> PlayerController(TEXT("/Game/Blueprints/MyPlayerControllerBP"));
	PlayerControllerClass = PlayerController.Class;
}
