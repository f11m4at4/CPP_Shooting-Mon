// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameoverUI.generated.h"

/**
 * 
 */
UCLASS()
class CPP_SHOOTING_API UGameoverUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	// Restart ��ư ������ �� ó���� �Լ�
	UFUNCTION(BlueprintCallable)
	void OnClick_Restart();

	// Quit ��ư ������ �� ó���� �Լ�
	UFUNCTION(BlueprintCallable)
	void OnClick_Quit();

};
