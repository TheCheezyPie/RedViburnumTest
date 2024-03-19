// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Services/BTS_SetGameplayFocus.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTS_SetGameplayFocus::UBTS_SetGameplayFocus()
{
	NodeName = "Set Gameplay Focus";
}

void UBTS_SetGameplayFocus::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	AActor* Actor = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(GetSelectedBlackboardKey()));

	OwnerComp.GetAIOwner()->SetFocus(Actor, EAIFocusPriority::LastFocusPriority);
}

void UBTS_SetGameplayFocus::OnCeaseRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::OnCeaseRelevant(OwnerComp, NodeMemory);

	OwnerComp.GetAIOwner()->SetFocus(nullptr);
}
