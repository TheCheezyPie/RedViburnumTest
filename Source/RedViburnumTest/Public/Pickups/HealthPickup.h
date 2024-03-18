// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickups/BasePickup.h"
#include "HealthPickup.generated.h"

/**
 * 
 */
UCLASS()
class REDVIBURNUMTEST_API AHealthPickup : public ABasePickup
{
	GENERATED_BODY()

//  Functions

public:
	virtual void Pickup(AActor* Interactor) override;

protected:

private:

//  Variables

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float HealAmount = 50.0f;

protected:

private:
};
