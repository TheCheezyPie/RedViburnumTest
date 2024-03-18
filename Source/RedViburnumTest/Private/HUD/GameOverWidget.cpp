// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/GameOverWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Kismet/KismetSystemLibrary.h"

void UGameOverWidget::NativeConstruct()
{
	Super::NativeConstruct();

	RestartButton->OnClicked.AddDynamic(this, &UGameOverWidget::RestartGame);
	QuitButton->OnClicked.AddDynamic(this, &UGameOverWidget::QuitGame);
}

void UGameOverWidget::Initialize(bool bPlayerWon)
{
	if (bPlayerWon)
	{
		UpperGameOverText->SetText(FText::FromString("You Won!"));
		LowerGameOverText->SetText(FText::FromString("Congratulations!"));

		UpperGameOverText->SetColorAndOpacity(FSlateColor(FLinearColor::Green));
		LowerGameOverText->SetColorAndOpacity(FSlateColor(FLinearColor::Green));
	}
	else
	{
		UpperGameOverText->SetText(FText::FromString("You Lost!"));
		LowerGameOverText->SetText(FText::FromString("Better luck next time!"));

		UpperGameOverText->SetColorAndOpacity(FSlateColor(FLinearColor::Red));
		LowerGameOverText->SetColorAndOpacity(FSlateColor(FLinearColor::Red));
	}
}

void UGameOverWidget::RestartGame()
{
	GetOwningPlayer()->RestartLevel();
}

void UGameOverWidget::QuitGame()
{
	UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, false);
}
