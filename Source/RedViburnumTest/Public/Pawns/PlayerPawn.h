// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "InputActionValue.h"

#include "PlayerPawn.generated.h"

/**
 * 
 */
UCLASS()
class REDVIBURNUMTEST_API APlayerPawn : public ABasePawn
{
	GENERATED_BODY()

public:
	APlayerPawn();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

//  Functions

public:

protected:
	void Move(const FInputActionValue& Value);
	void LookAround(const FInputActionValue& Value);

	virtual void InitializeComponents() override;

	virtual void HealthChanged(float NewPercent) override;
	void AmmoChanged(int32 NewAmmo);

private:

//  Variables

public:

protected:
	UPROPERTY()
	TWeakObjectPtr<class AMainPlayerController> MainPlayerController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerPawn")
	TObjectPtr<class USpringArmComponent> CameraBoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerPawn")
	TObjectPtr<class UCameraComponent> Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerPawn")
	TObjectPtr<class UFloatingPawnMovement> MovementComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<class UInputMappingContext> DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<class UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<class UInputAction> MouseMoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<class UInputAction> ShootAction;

private:
};

