// Fill out your copyright notice in the Description page of Project Settings.


#include "GameFramework/Controllers/TurretAIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense_Sight.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "UsefulMacros.h"

ATurretAIController::ATurretAIController()
{
	AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PawnSensingComponent"));
}

void ATurretAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATurretAIController::BeginPlay()
{
	Super::BeginPlay();

	if (BehaviorTree)
	{
		RunBehaviorTree(BehaviorTree);
	}
	AIPerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &ATurretAIController::OnTargetPerceptionUpdated);
}

void ATurretAIController::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	TSubclassOf<UAISense> StimulusClass = UAIPerceptionSystem::GetSenseClassForStimulus(this, Stimulus);

	if (StimulusClass == UAISense_Sight::StaticClass())
	{
		HandleSightSense(Actor, Stimulus);
	}
}

void ATurretAIController::HandleSightSense(AActor* Actor, FAIStimulus Stimulus)
{
	if (IsViableTarget(Actor) && GetBlackboardComponent())
	{
		if (Stimulus.WasSuccessfullySensed())
		{
			GetBlackboardComponent()->SetValueAsObject("TargetActor", Actor);
		}
		else
		{
			GetBlackboardComponent()->ClearValue("TargetActor");
		}
	}
}

bool ATurretAIController::IsViableTarget(AActor* Actor) const
{
	return Actor 
		   && Actor->CanBeDamaged()
		   && !Actor->ActorHasTag("Enemy");
}
