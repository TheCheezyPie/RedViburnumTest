

#include "Components/HealthComponent.h"

UHealthComponent::UHealthComponent()
{
	//
	PrimaryComponentTick.bCanEverTick = false;
	//
}

void UHealthComponent::Initialize()
{
	CurrentHealth = CurrentHealth > 0 ? CurrentHealth : MaxHealth;
	UE_LOG(LogTemp, Warning, TEXT("HealthComponent::Initialize() CurrentHealth: %f"), CurrentHealth);
	OnHealthChanged.Broadcast(CurrentHealth / MaxHealth);

	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::HandleTakeAnyDamage);
}

bool UHealthComponent::Heal(float HealAmount)
{
	if (CurrentHealth == MaxHealth)
	{
		return false;
	}
	else
	{
		CurrentHealth = FMath::Clamp(CurrentHealth + HealAmount, 0.0f, MaxHealth);
		OnHealthChanged.Broadcast(CurrentHealth / MaxHealth);
		return true;
	}
}

void UHealthComponent::HandleTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0.0f, MaxHealth);

	if (CurrentHealth <= 0)
	{
		HandleDeath(DamagedActor);
	}
	else
	{
		OnHealthChanged.Broadcast(CurrentHealth / MaxHealth);
	}
}

void UHealthComponent::HandleDeath(AActor* Killer)
{
	OnDeath.Broadcast();
}

