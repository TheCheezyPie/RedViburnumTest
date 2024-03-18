
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class REDVIBURNUMTEST_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	ABasePawn();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

//  Functions

public:
	UFUNCTION(BlueprintCallable)
	void Shoot();

protected:
	UFUNCTION()
	virtual void HealthChanged(float NewPercent);

	UFUNCTION()
	virtual void HandleDeath();

	virtual void InitializeComponents();

private:
	void SpawnDeathEffects();

	void SpawnDeathSound();
	void SpawnDeathParticle();


//  Variables

public:

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerPawn")
	TObjectPtr<class UBoxComponent> BoxCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerPawn")
	TObjectPtr<class USoundBase> DeathSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerPawn")
	TObjectPtr<class UParticleSystem> DeathFX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerPawn")
	TObjectPtr<class UStaticMeshComponent> BaseMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerPawn")
	TObjectPtr<class UStaticMeshComponent> TurretMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerPawn")
	TObjectPtr<class UShootingComponent> ShootingComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerPawn")
	TObjectPtr<class UHealthComponent> HealthComponent;

private:
};
