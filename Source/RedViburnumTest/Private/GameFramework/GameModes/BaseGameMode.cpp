// Fill out your copyright notice in the Description page of Project Settings.


#include "GameFramework/GameModes/BaseGameMode.h"
#include "Pawns/EnemyPawn.h"
#include "Pawns/BasePawn.h"
#include "Kismet/GameplayStatics.h"
#include "Pawns/PlayerPawn.h"
#include "EngineUtils.h"

void ABaseGameMode::PawnKilled(ABasePawn* KilledPawn)
{
	if (KilledPawn)
	{
		if (KilledPawn->ActorHasTag("Player"))
		{
			HandleGameOver(false);
			KilledPawn->Destroy();
		}
		else if (KilledPawn->ActorHasTag("Enemy"))
		{
			EnemiesLeft--;
			if (EnemiesLeft == 0)
			{
				HandleGameOver(true);
			}
			KilledPawn->Destroy();
		}
	}
}

void ABaseGameMode::BeginPlay()
{
	Super::BeginPlay();

	HandleGameStart();
}

void ABaseGameMode::HandleGameStart()
{
	Player = Cast<APlayerPawn>(UGameplayStatics::GetPlayerPawn(this, 0));

	GetEnemiesCount();
}

void ABaseGameMode::GetEnemiesCount()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(this, AEnemyPawn::StaticClass(), FoundActors);

	SpawnedEnemies = FoundActors.Num();
	EnemiesLeft = SpawnedEnemies;
}

void ABaseGameMode::HandleGameOver(bool bPlayerWon)
{
	UE_LOG(LogTemp, Warning, TEXT("Game Over! %s won!"), bPlayerWon ? TEXT("Player") : TEXT("Enemy"));
	for (AController* Controller : TActorRange<AController>(GetWorld()))
	{
		bool bIsWinner = Controller->IsPlayerController() == bPlayerWon;
		Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
	}
}
