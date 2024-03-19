// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTD_IsLookingAtTarget.generated.h"

/**
 * 
 */
UCLASS()
class REDVIBURNUMTEST_API UBTD_IsLookingAtTarget : public UBTDecorator
{
	GENERATED_BODY()
	
//  Functions

public:
	UBTD_IsLookingAtTarget();

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const;

private:

//  Variables

public:

protected:

private:
};
