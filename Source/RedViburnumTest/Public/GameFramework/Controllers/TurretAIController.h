// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TurretAIController.generated.h"

/**
 * 
 */
UCLASS()
class REDVIBURNUMTEST_API ATurretAIController : public AAIController
{
	GENERATED_BODY()
	
//  Functions

public:
	ATurretAIController();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

	void HandleSightSense(AActor* Actor, FAIStimulus Stimulus);

	bool IsViableTarget(AActor* Actor) const;

private:

//  Variables

public:

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	TObjectPtr<class UBehaviorTree> BehaviorTree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	TObjectPtr<class UAIPerceptionComponent> AIPerceptionComponent;

private:
};
