// Fill out your copyright notice in the Description page of Project Settings.


#include "GameFramework/Controllers/MainPlayerController.h"
#include "HUD/MainWidget.h"
#include "HUD/GameOverWidget.h"
#include "Blueprint/UserWidget.h"
#include "UsefulMacros.h"

void AMainPlayerController::UpdateHealth(float NewPercent)
{
	if (MainWidget)
	{
		MainWidget->SetHealthBarPercent(NewPercent);
	}
}

void AMainPlayerController::UpdateAmmo(int32 NewAmmo)
{
	if (MainWidget)
	{
		MainWidget->SetAmmo(NewAmmo);
	}
}

void AMainPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	if (MainWidget)
	{
		MainWidget->RemoveFromParent();
	}

	GetPawn()->DisableInput(this);

	SpawnGameOverWidget(bIsWinner);

	FInputModeUIOnly InputMode;
	SetInputMode(InputMode);

	bShowMouseCursor = true;
}

void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	CreateMainWidget();

	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);
	bShowMouseCursor = false;
}

void AMainPlayerController::SpawnGameOverWidget(bool bIsWinner)
{
	if (GameOverWidgetClass)
	{
		GameOverWidget = CreateWidget<UGameOverWidget>(this, GameOverWidgetClass);
		if (GameOverWidget)
		{
			GameOverWidget->AddToViewport();
			GameOverWidget->InitializeWidget(bIsWinner);
		}
	}
}

void AMainPlayerController::CreateMainWidget()
{
	if (MainWidgetClass)
	{
		MainWidget = CreateWidget<UMainWidget>(this, MainWidgetClass);
		if (MainWidget)
		{
			MainWidget->AddToViewport();
		}
	}
}
