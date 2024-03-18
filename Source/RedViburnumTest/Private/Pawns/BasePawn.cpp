

#include "Pawns/BasePawn.h"
#include "Components/BoxComponent.h"
#include "Weapons/ShootingComponent.h"
#include "Components/HealthComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameModes/BaseGameMode.h"

ABasePawn::ABasePawn()
{
 	PrimaryActorTick.bCanEverTick = true;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("CapsuleCollision"));
	SetRootComponent(BoxCollision);
	BoxCollision->SetCollisionProfileName(TEXT("Pawn"));

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	BaseMesh->SetupAttachment(GetRootComponent());

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretMesh"));

	ShootingComponent = CreateDefaultSubobject<UShootingComponent>(TEXT("ShootingComponent"));
	ShootingComponent->SetupAttachment(TurretMesh);

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));

	SetInstigator(this);
}

void ABasePawn::BeginPlay()
{
	Super::BeginPlay();
	
	InitializeComponents();
}

void ABasePawn::InitializeComponents()
{
	HealthComponent->OnHealthChanged.AddUObject(this, &ABasePawn::HealthChanged);
	HealthComponent->OnDeath.AddUObject(this, &ABasePawn::HandleDeath);

	if (HealthComponent)
	{
		HealthComponent->Initialize();
	}
	if (ShootingComponent)
	{
		ShootingComponent->Initialize();
	}
}

void ABasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABasePawn::Shoot()
{
	if (ShootingComponent)
	{
		ShootingComponent->Shoot();
	}
}

void ABasePawn::HealthChanged(float NewPercent)
{
}

void ABasePawn::HandleDeath()
{
	ABaseGameMode* GameMode = GetWorld()->GetAuthGameMode<ABaseGameMode>();
	if (GameMode)
	{
		GameMode->PawnKilled(this);
	}

	SpawnDeathEffects();
	DetachFromControllerPendingDestroy();
}

void ABasePawn::SpawnDeathEffects()
{
	SpawnDeathParticle();
	SpawnDeathSound();
}

void ABasePawn::SpawnDeathSound()
{
	if (DeathSound)
	{
		UGameplayStatics::SpawnSoundAtLocation(GetWorld(), DeathSound, GetActorLocation());
	}
}

void ABasePawn::SpawnDeathParticle()
{
	if (DeathFX)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), DeathFX, GetActorTransform());
	}
}

