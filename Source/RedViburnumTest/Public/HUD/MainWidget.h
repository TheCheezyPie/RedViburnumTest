// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainWidget.generated.h"

/**
 * 
 */
UCLASS()
class REDVIBURNUMTEST_API UMainWidget : public UUserWidget
{
	GENERATED_BODY()
	
//  Functions

public:
	// @param Percent: 0.f - 1.f
	void SetHealthBarPercent(float NewPercent);
	void SetAmmo(int32 NewAmmo);

protected:

private:

//  Variables

public:

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UProgressBar> HealthBar;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UTextBlock> HealthText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UTextBlock> AmmoText;

private:
};
