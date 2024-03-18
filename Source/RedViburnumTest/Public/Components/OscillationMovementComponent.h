
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OscillationMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class REDVIBURNUMTEST_API UOscillationMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UOscillationMovementComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

//  Functions

public:
	void Stop();
	void Resume();

protected:

private:

//  Variables

public:

protected:

private:
	bool bShouldMove = true;

	UPROPERTY(EditAnywhere, Category = "Idle Movement")
	bool bUseCos = true;
	UPROPERTY(EditAnywhere, Category = "Idle Movement")
	float Amplitude = 0.5f;
	UPROPERTY(EditAnywhere, Category = "Idle Movement")
	float MovementSpeed = 2.f;
	UPROPERTY(EditAnywhere, Category = "Idle Movement")
	float RotationSpeed = 50.f;
};
