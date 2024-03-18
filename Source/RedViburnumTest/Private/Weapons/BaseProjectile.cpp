

#include "Weapons/BaseProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"

ABaseProjectile::ABaseProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
	SetRootComponent(ProjectileMesh);
	ProjectileMesh->SetNotifyRigidBodyCollision(true); // Simulation Generates Hit Events from BP

	TrailParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("TrailParticle"));
	TrailParticle->SetupAttachment(GetRootComponent());

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
}

void ABaseProjectile::BeginPlay()
{
	if (GetOwner())
	{
		ProjectileMesh->IgnoreActorWhenMoving(GetOwner(), true);
	}

	Super::BeginPlay();
	
	ProjectileMesh->OnComponentHit.AddDynamic(this, &ABaseProjectile::OnHit);
}

void ABaseProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor && OtherActor != GetOwner())
	{
		FDamageEvent DamageEvent;
		OtherActor->TakeDamage(Damage, DamageEvent, GetInstigatorController(), this);
	}

	SpawnHitParticle(Hit.ImpactPoint);
	SpawnHitSound(Hit.ImpactPoint, OtherActor);

	Destroy();
}

void ABaseProjectile::SpawnHitParticle(const FVector& Location)
{
	if (HitParticle)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), HitParticle, Location);
	}
}

void ABaseProjectile::SpawnHitSound(const FVector& Location, AActor* HitTarget)
{
	if (HitTarget)
	{
		USoundBase* HitSound = nullptr;

		if (APawn* HitPawn = HitTarget->GetInstigator())
		{
			if (HitPawn->GetController())
			{
				HitSound = CharacterHitSound;
			}
			else
			{
				HitSound = EnvironmentHitSound;
			}
		}
		else
		{
			HitSound = EnvironmentHitSound;
		}

		if (HitSound)
		{
			UGameplayStatics::SpawnSoundAtLocation(HitTarget, HitSound, Location);
		}
	}
}

