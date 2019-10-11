// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class HANGMAN_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	AMyPlayerController();
public:
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> MainWidget;
	UUserWidget* MyWidget;
	UPROPERTY(EditAnywhere)
	USceneComponent* Skeleton;
	UPROPERTY(EditAnywhere, Category = "Words")
		TArray<FString> Words;
		FString Word;
	
	UPROPERTY(VisibleAnywhere)
	int lost;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Words")
		FString WordView; 
	UFUNCTION(BlueprintCallable, Category = "Functions")
		void CheckLetter(FString let);
	void ChooseWord();
	void CheckWin();
protected:
	virtual void BeginPlay() override;
};
