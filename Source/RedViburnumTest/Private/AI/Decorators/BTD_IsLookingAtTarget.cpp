// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Decorators/BTD_IsLookingAtTarget.h"
#include "AIController.h"
#include "Pawns/EnemyPawn.h"

UBTD_IsLookingAtTarget::UBTD_IsLookingAtTarget()
{
	NodeName = "Is Looking At Target";
}

bool UBTD_IsLookingAtTarget::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	APawn* Pawn = OwnerComp.GetAIOwner()->GetPawn();
	AEnemyPawn* EnemyPawn = Cast<AEnemyPawn>(Pawn);

	if (EnemyPawn)
	{
		return EnemyPawn->DoneRotating();
	}

	return false;
}
