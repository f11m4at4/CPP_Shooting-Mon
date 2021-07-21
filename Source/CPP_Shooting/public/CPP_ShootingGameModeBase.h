// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CPP_ShootingGameModeBase.generated.h"

// 열거형
// 특정한 숫자를 의미있는 데이터로 만들어주는 사용자 자료형c
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
	
	// Tick 함수 오버라이딩
	virtual void Tick( float DeltaSeconds ) override;

	// Gameover 처리할 함수
	void OnGameoverProcess();

	//int state = 0;
	UPROPERTY(EditAnywhere, Category="FSM", BlueprintReadWrite)
	EGameState state = EGameState::Ready;

	// 필요속성 : 일정시간(기다리는시간), 경과시간
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

	// 만들어진 ReadyUI 인스턴스
	UPROPERTY()
	class UUserWidget* readyUI;

	UPROPERTY()
	class UUserWidget* playingUI;

	UPROPERTY()
	class UUserWidget* gameoverUI;

	// 필요속성 : 일정시간(ui 보여질시간)
	UPROPERTY(EditAnywhere, Category="UI")
	float playingUITime = 1;

private:
	void Ready();
	void Playing();
	void Gameover();
};
