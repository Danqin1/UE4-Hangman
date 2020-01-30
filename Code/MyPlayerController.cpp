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
	
	Words.Add(TEXT("ADAM"));
	Words.Add(TEXT("BARTEK"));
	Words.Add(TEXT("CEZARY"));
	Words.Add(TEXT("DAMIAN"));
	Words.Add(TEXT("ERYK"));
	Words.Add(TEXT("FABIAN"));
	Words.Add(TEXT("HUBERT"));
	Words.Add(TEXT("IGNACY"));
	Words.Add(TEXT("JACEK"));
	Words.Add(TEXT("KAMIL"));
	Words.Add(TEXT("LEON"));
	Words.Add(TEXT("MARIUSZ"));
	Words.Add(TEXT("NORBERT"));
	Words.Add(TEXT("OLGIERT"));
	Words.Add(TEXT("PATRYK"));
	Words.Add(TEXT("ROBERT"));
	Words.Add(TEXT("SEBASTIAN"));
	Words.Add(TEXT("TOMEK"));
	Words.Add(TEXT("ZENEK"));
	lost = 5;
}

void AMyPlayerController::BeginPlay()
{
	ChooseWord();
	APlayerController::bShowMouseCursor = true;
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
	if (GameOverWidget)
	{
		OverWidget = CreateWidget<UUserWidget>(this, GameOverWidget);
	}
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
		CheckGameOver();
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
void AMyPlayerController::CheckGameOver()
{
	lost--;
	if (lost == 0)
	{
		MyWidget->RemoveFromViewport();
		OverWidget->AddToViewport();
	}
}
