// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"
UCLASS()
class HANGMAN_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	AMyPlayerController();
private:
	bool won = false;	
	void ChooseWord();
	void CheckWin();
	void CheckGameOver();
public:
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> MainWidget;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> WinWidget;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> GameOverWidget;
	UUserWidget* MyWidget;
	UUserWidget* WonWidget;
	UUserWidget* OverWidget;
	UPROPERTY(EditAnywhere, Category = "Words")
		TArray<FString> Words;
		FString Word;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Words")
		FString WordView;
	UPROPERTY(EditAnywhere,Category ="Candles") 
	AActor *Candle1; // reference to candle
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	int lost;
	UFUNCTION(BlueprintCallable)
	void CheckLetter(FString let); 	
protected:
	virtual void BeginPlay() override;
};
