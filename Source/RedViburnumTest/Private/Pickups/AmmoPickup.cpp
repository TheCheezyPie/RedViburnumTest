// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickups/AmmoPickup.h"
#include "Weapons/ShootingComponent.h"

void AAmmoPickup::Pickup(AActor* Interactor)
{
	Super::Pickup(Interactor);

	UShootingComponent* ShootingComponent = Interactor->FindComponentByClass<UShootingComponent>();
	if (ShootingComponent)
	{
		if (ShootingComponent->AddAmmo(AmmoAmount))
		{
			Destroy();
		}
	}
}
