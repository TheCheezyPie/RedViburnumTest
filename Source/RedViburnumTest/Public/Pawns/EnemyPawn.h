// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pawns/BasePawn.h"
#include "EnemyPawn.generated.h"

/**
 * 
 */
UCLASS()
class REDVIBURNUMTEST_API AEnemyPawn : public ABasePawn
{
	GENERATED_BODY()

public:
	AEnemyPawn();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

//  Functions

public:
	UFUNCTION(BlueprintPure, Category = "AI")
	bool DoneRotating() const;

protected:

private:

//  Variables

public:

protected:

private:
	FRotator StartControlRotation;
};
