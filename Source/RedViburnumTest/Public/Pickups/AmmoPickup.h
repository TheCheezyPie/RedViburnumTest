// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickups/BasePickup.h"
#include "AmmoPickup.generated.h"

/**
 * 
 */
UCLASS()
class REDVIBURNUMTEST_API AAmmoPickup : public ABasePickup
{
	GENERATED_BODY()

//  Functions

public:
	virtual void Pickup(AActor* Interactor) override;

protected:

private:

//  Variables

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
	int32 AmmoAmount = 5;

protected:

private:
};
