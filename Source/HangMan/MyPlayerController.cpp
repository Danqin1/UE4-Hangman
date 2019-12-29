// Fill out your copyright notice in the Description page of Project Settings.

#define print(text) \
	if (GEngine)    \
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, text);

#include "MyPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "ConstructorHelpers.h"
#include <Runtime\Engine\Classes\Engine\Selection.h>
#include <Array.h>

AMyPlayerController::AMyPlayerController()
{
	Words.Add(TEXT("DADA"));
	Words.Add(TEXT("MAKARENA"));
	Words.Add(TEXT("MAMA"));
	lost = 0;
}

void AMyPlayerController::BeginPlay()
{
	ChooseWord();
	if (MainWidget)
	{
		MyWidget = CreateWidget<UUserWidget>(this, MainWidget);
		if (MyWidget)
		{
			MyWidget->AddToViewport();
		}
	}
	if (WinWidget)
		{
			WonWidget = CreateWidget<UUserWidget>(this, WinWidget);
		}
	APlayerController::bShowMouseCursor = true;
}
void AMyPlayerController::Tick()
{
}
void AMyPlayerController::CheckLetter(FString let)
{
	bool found = false;
	print(let);
	for (int i = 0; i < Word.Len(); i++)
	{
		if (FString::Chr(Word[i]) == let)
		{
			found = true;
			//print("Succes");
			WordView[i] = Word[i];
		}
	}
	if (found == false)
	{
		lost++;
		if (lost >= 3)
			print("YOU LOOSE");
	}
	CheckWin();
}
void AMyPlayerController::ChooseWord()
{
	int RandomNummer = FMath::RandRange(0, Words.Num() - 1);
	print(Words[RandomNummer]);
	if (RandomNummer >= 0)
	{
		Word = Words[RandomNummer];
	}
	for (int i = 0; i < Word.Len(); i++)
	{
		WordView += "-";
	}
}

void AMyPlayerController::CheckWin()
{
	int win = 0;
	for (int j = 0; j < WordView.Len(); j++)
	{
		if (WordView[j] != '-')
		{
			win++;
		}
	}
	if (win == WordView.Len())
	{
		MyWidget->RemoveFromViewport();
		WonWidget->AddToViewport();
		APlayerController::bShowMouseCursor = true;
	}
}
