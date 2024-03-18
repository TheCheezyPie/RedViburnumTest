// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/ShootingComponent.h"
#include "Weapons/BaseProjectile.h"
#include "Components/BoxComponent.h"

UShootingComponent::UShootingComponent()
{
}

void UShootingComponent::Shoot()
{
	if (CanShoot())
	{
		FVector SpawnLocation = GetComponentLocation();
		FRotator SpawnRotation = GetComponentRotation();

		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = GetOwner();
		SpawnParams.Instigator = Cast<APawn>(GetOwner());

		ABaseProjectile* SpawnedProjectile = GetWorld()->SpawnActor<ABaseProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, SpawnParams);
		if (SpawnedProjectile)
		{
			UBoxComponent* BoxComponent = Cast<UBoxComponent>(GetOwner()->GetRootComponent());
			BoxComponent->IgnoreActorWhenMoving(SpawnedProjectile, true);

			GetWorld()->GetTimerManager().SetTimer(ShootTimer, ShootDelay, false);
			
			if (!bHasInfiniteAmmo)
			{
				CurrentAmmo--;
				OnAmmoChanged.Broadcast(CurrentAmmo);
			}
		}
	}
}

bool UShootingComponent::AddAmmo(int32 Ammo)
{
	if (CurrentAmmo == MaxAmmo)
	{
		return false;
	}
	else
	{
		CurrentAmmo = FMath::Clamp(CurrentAmmo + Ammo, 0, MaxAmmo);
		OnAmmoChanged.Broadcast(CurrentAmmo);
		return true;
	}
}

void UShootingComponent::Initialize()
{
	CurrentAmmo = CurrentAmmo > 0 ? CurrentAmmo : MaxAmmo;
	OnAmmoChanged.Broadcast(CurrentAmmo);
}

bool UShootingComponent::CanShoot() const
{
	return 
		ProjectileClass 
		&& GetWorld() 
		&& !GetWorld()->GetTimerManager().IsTimerActive(ShootTimer)
		&& (CurrentAmmo > 0 || bHasInfiniteAmmo);
}
