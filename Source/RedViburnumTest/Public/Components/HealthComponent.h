// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float /* New Percentage */);
DECLARE_MULTICAST_DELEGATE(FOnDeathSignature);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class REDVIBURNUMTEST_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

//  Functions

public:
	UHealthComponent();

	void Initialize();

	// @return false if the HP is already full
	bool Heal(float HealAmount);

protected:
	UFUNCTION()
	void HandleTakeAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	void HandleDeath(AActor* Killer);

private:

//  Variables

public:
	FOnHealthChangedSignature OnHealthChanged;
	FOnDeathSignature OnDeath;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float MaxHealth = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float CurrentHealth = 50.f;

private:
};
