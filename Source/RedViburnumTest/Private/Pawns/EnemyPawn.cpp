// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/EnemyPawn.h"
#include "Pawns/PlayerPawn.h"
#include "AIController.h"
#include "UsefulMacros.h"

AEnemyPawn::AEnemyPawn() : Super()
{
	TurretMesh->SetupAttachment(BaseMesh);

	Tags.Add("Enemy");
}

void AEnemyPawn::BeginPlay()
{
	Super::BeginPlay();

	StartControlRotation = GetController()->GetControlRotation();
}

void AEnemyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (GetController())
	{
		FRotator NewRotation = FMath::RInterpConstantTo(TurretMesh->GetComponentRotation(), GetController()->GetControlRotation(), DeltaTime, 100.0f);
		TurretMesh->SetWorldRotation(NewRotation);
	}
}

bool AEnemyPawn::DoneRotating() const
{
	return GetController()->GetControlRotation() != StartControlRotation && TurretMesh->GetComponentRotation().Equals(GetController()->GetControlRotation(), 1.0);
}
