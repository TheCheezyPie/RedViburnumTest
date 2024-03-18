// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameOverWidget.generated.h"

/**
 * 
 */
UCLASS()
class REDVIBURNUMTEST_API UGameOverWidget : public UUserWidget
{
	GENERATED_BODY()
	
//  Functions

public:
	virtual void NativeConstruct() override;

	void Initialize(bool bPlayerWon);

protected:
	UFUNCTION()
	void RestartGame();

	UFUNCTION()
	void QuitGame();

private:

//  Variables

public:

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UTextBlock> UpperGameOverText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UTextBlock> LowerGameOverText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UButton> RestartButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UButton> QuitButton;

private:
};
