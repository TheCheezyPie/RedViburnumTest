// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ArrowComponent.h"
#include "ShootingComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnAmmoChangedSignature, int /* RemainingAmmo */);

UCLASS()
class REDVIBURNUMTEST_API UShootingComponent : public UArrowComponent
{
	GENERATED_BODY()

//  Functions

public:
	UShootingComponent();

	void Shoot();
	// @return false if the Ammo is already full
	bool AddAmmo(int32 Ammo);

	void Initialize();

protected:
	bool CanShoot() const;

private:

//  Variables

public:
	FOnAmmoChangedSignature OnAmmoChanged;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shooting")
	float ShootDelay = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shooting")
	bool bHasInfiniteAmmo = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shooting")
	int32 MaxAmmo = 16;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shooting")
	int32 CurrentAmmo = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shooting")
	TSubclassOf<class ABaseProjectile> ProjectileClass;

private:
	FTimerHandle ShootTimer;
};
