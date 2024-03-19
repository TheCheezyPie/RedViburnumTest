// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Tasks/BTT_Shoot.h"
#include "AIController.h"
#include "Pawns/EnemyPawn.h"

UBTT_Shoot::UBTT_Shoot()
{
	NodeName = TEXT("Shoot");
}

EBTNodeResult::Type UBTT_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	APawn* Pawn = OwnerComp.GetAIOwner()->GetPawn();

	if (Pawn)
	{
		AEnemyPawn* EnemyPawn = Cast<AEnemyPawn>(Pawn);
		if (EnemyPawn)
		{
			UE_LOG(LogTemp, Warning, TEXT("Enemy Pawn is shooting"));
			EnemyPawn->Shoot();
			return EBTNodeResult::Succeeded;
		}
	}

	return EBTNodeResult::Failed;
}
