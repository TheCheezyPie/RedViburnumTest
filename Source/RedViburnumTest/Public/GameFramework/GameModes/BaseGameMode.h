// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BaseGameMode.generated.h"

/**
 * 
 */
UCLASS()
class REDVIBURNUMTEST_API ABaseGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
//  Functions

public:
	void PawnKilled(class ABasePawn* KilledPawn);

protected:
	virtual void BeginPlay() override;

	void HandleGameStart();
	void GetEnemiesCount();

	void HandleGameOver(bool bPlayerWon);

private:

//  Variables

public:

protected:
	UPROPERTY()
	TObjectPtr<class APlayerPawn> Player;

	int32 SpawnedEnemies = 0;

	UPROPERTY(VisibleAnywhere)
	int32 EnemiesLeft = 0;

private:
};
