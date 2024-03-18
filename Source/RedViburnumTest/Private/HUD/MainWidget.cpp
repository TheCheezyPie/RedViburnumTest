// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/MainWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UMainWidget::SetHealthBarPercent(float NewPercent)
{
	HealthBar->SetPercent(NewPercent);
	HealthText->SetText(FText::FromString(FString::FromInt(NewPercent * 100)));
}

void UMainWidget::SetAmmo(int32 NewAmmo)
{
	AmmoText->SetText(FText::FromString(FString::FromInt(NewAmmo)));
}
