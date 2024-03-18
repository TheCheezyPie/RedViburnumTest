

#include "Pickups/BasePickup.h"
#include "Components/SphereComponent.h"
#include "NiagaraComponent.h"
#include "Components/OscillationMovementComponent.h"

ABasePickup::ABasePickup()
{
 	PrimaryActorTick.bCanEverTick = true;

	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	SetRootComponent(SphereCollision);

	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	PickupMesh->SetupAttachment(GetRootComponent());

	IdleEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("PickupFX"));
	IdleEffect->SetupAttachment(GetRootComponent());

	OscillationMovement = CreateDefaultSubobject<UOscillationMovementComponent>(TEXT("OscillationMovement"));
}

void ABasePickup::BeginPlay()
{
	Super::BeginPlay();
	
	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &ABasePickup::OnPickupOverlap);
}

void ABasePickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABasePickup::Pickup(AActor* Interactor)
{
}

void ABasePickup::OnPickupOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		Pickup(OtherActor);
	}
}
