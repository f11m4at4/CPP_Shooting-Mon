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
	
	// Tick 함수 오버라이딩
	virtual void Tick( float DeltaSeconds ) override;

	//int state = 0;
	UPROPERTY(EditAnywhere, Category="FSM", BlueprintReadWrite)
	EGameState state = EGameState::Ready;

	// 필요속성 : 일정시간(기다리는시간), 경과시간
	UPROPERTY(EditAnywhere, Category="FSM")
	float readyDelayTime = 2;

	UPROPERTY()
	float currentTime = 0;
private:
	void Ready();
	void Playing();
	void Gameover();
};
