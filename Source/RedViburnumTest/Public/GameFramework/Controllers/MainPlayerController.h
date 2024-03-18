// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class REDVIBURNUMTEST_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()

//  Functions

public:
	void UpdateHealth(float NewPercent);
	void UpdateAmmo(int32 NewAmmo);

	virtual void GameHasEnded(AActor* EndGameFocus = nullptr, bool bIsWinner = false) override;

protected:
	virtual void BeginPlay() override;

	void SpawnGameOverWidget(bool bIsWinner);

private:
	void CreateMainWidget();

//  Variables

public:
	TObjectPtr<class APlayerPawn> Player;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UGameOverWidget> GameOverWidgetClass;

	UPROPERTY()
	TObjectPtr<class UGameOverWidget> GameOverWidget;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UMainWidget> MainWidgetClass;

	UPROPERTY()
	TObjectPtr<class UMainWidget> MainWidget;

private:
};
