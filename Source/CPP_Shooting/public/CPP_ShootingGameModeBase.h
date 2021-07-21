// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CPP_ShootingGameModeBase.generated.h"

// ������
// Ư���� ���ڸ� �ǹ��ִ� �����ͷ� ������ִ� ����� �ڷ���c
UENUM(BlueprintType)
enum class EGameState : uint8
{
	Ready UMETA(DisplayName = "READY STATE"),
	Playing UMETA(DisplayName = "PLAYING STATE"),
	Gameover UMETA(DisplayName = "GAMEOVER STATE")
};

/**
 * 
 */
UCLASS()
class CPP_SHOOTING_API ACPP_ShootingGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ACPP_ShootingGameModeBase();

	virtual void BeginPlay() override;

	virtual void InitGameState() override;
	
	// Tick �Լ� �������̵�
	virtual void Tick( float DeltaSeconds ) override;

	// Gameover ó���� �Լ�
	void OnGameoverProcess();

	//int state = 0;
	UPROPERTY(EditAnywhere, Category="FSM", BlueprintReadWrite)
	EGameState state = EGameState::Ready;

	// �ʿ�Ӽ� : �����ð�(��ٸ��½ð�), ����ð�
	UPROPERTY(EditAnywhere, Category="FSM")
	float readyDelayTime = 2;

	UPROPERTY()
	float currentTime = 0;

	// Ready UI Widget
	UPROPERTY(EditDefaultsOnly, Category="UI")
	TSubclassOf<class UUserWidget> readyUIFactory;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UUserWidget> playingUIFactory;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UUserWidget> gameoverUIFactory;

	// ������� ReadyUI �ν��Ͻ�
	UPROPERTY()
	class UUserWidget* readyUI;

	UPROPERTY()
	class UUserWidget* playingUI;

	UPROPERTY()
	class UUserWidget* gameoverUI;

	// �ʿ�Ӽ� : �����ð�(ui �������ð�)
	UPROPERTY(EditAnywhere, Category="UI")
	float playingUITime = 1;

private:
	void Ready();
	void Playing();
	void Gameover();
};
