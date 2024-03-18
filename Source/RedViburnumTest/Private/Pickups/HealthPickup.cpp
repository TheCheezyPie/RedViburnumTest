

#include "Pickups/HealthPickup.h"
#include "Components/HealthComponent.h"

void AHealthPickup::Pickup(AActor* Interactor)
{
	Super::Pickup(Interactor);

	UHealthComponent* HealthComponent = Interactor->FindComponentByClass<UHealthComponent>();
	if (HealthComponent)
	{
		if (HealthComponent->Heal(HealAmount))
		{
			Destroy();
		}
	}
}
