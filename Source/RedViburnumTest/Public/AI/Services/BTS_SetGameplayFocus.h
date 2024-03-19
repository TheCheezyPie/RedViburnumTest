// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree\Services\BTService_BlackboardBase.h"
#include "BTS_SetGameplayFocus.generated.h"

/**
 * 
 */
UCLASS()
class REDVIBURNUMTEST_API UBTS_SetGameplayFocus : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
//  Functions

public:
	UBTS_SetGameplayFocus();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	virtual void OnCeaseRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);

private:

//  Variables

public:

protected:

private:
};
