// Copyright Epic Games, Inc. All Rights Reserved.


#include "CPP_ShootingGameModeBase.h"

ACPP_ShootingGameModeBase::ACPP_ShootingGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACPP_ShootingGameModeBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// 목차 작성하는 곳
	// 상태 처리 흐름 작성
	// 만약 state 가 Ready 라면
	switch (state)
	{
		case EGameState::Ready:
			// 페이지번호 (Ready 함수 호출)
			Ready();
			break;
		case EGameState::Playing:
			// 페이지번호 (Playing 함수 호출)
			Playing();
			break;
		case EGameState::Gameover:
			// 페이지번호 (Gameover 함수 호출)
			Gameover();
			break;
	}
}

void ACPP_ShootingGameModeBase::Ready()
{
	// 본문
}

void ACPP_ShootingGameModeBase::Playing()
{

}

void ACPP_ShootingGameModeBase::Gameover()
{
}

