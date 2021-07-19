// Copyright Epic Games, Inc. All Rights Reserved.


#include "CPP_ShootingGameModeBase.h"

ACPP_ShootingGameModeBase::ACPP_ShootingGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACPP_ShootingGameModeBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// ���� �ۼ��ϴ� ��
	// ���� ó�� �帧 �ۼ�
	// ���� state �� Ready ���
	switch (state)
	{
		case EGameState::Ready:
			// ��������ȣ (Ready �Լ� ȣ��)
			Ready();
			break;
		case EGameState::Playing:
			// ��������ȣ (Playing �Լ� ȣ��)
			Playing();
			break;
		case EGameState::Gameover:
			// ��������ȣ (Gameover �Լ� ȣ��)
			Gameover();
			break;
	}
}

void ACPP_ShootingGameModeBase::Ready()
{
	// ����
}

void ACPP_ShootingGameModeBase::Playing()
{

}

void ACPP_ShootingGameModeBase::Gameover()
{
}

