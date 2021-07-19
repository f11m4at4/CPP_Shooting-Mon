// Copyright Epic Games, Inc. All Rights Reserved.


#include "CPP_ShootingGameModeBase.h"
#include "CPP_Shooting.h"

ACPP_ShootingGameModeBase::ACPP_ShootingGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACPP_ShootingGameModeBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// state �� enum �����͸� �ֿܼ� ����ϱ�
	const UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EGameState"), true);
	if(enumPtr)
	{
		PRINTLOG(TEXT("%s"), *enumPtr->GetNameStringByValue((uint8)state));
	}
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

// Ready �����϶� ����
// �����ð� ��ٸ��ٰ� ���¸� Playing ���� ��ȯ
// �ʿ�Ӽ� : �����ð�(��ٸ��½ð�), ����ð�
void ACPP_ShootingGameModeBase::Ready()
{
	// �����ð� ��ٸ��ٰ� ���¸� Playing ���� ��ȯ
	// 1. �ð��� �귶���ϱ�
	currentTime += GetWorld()->DeltaTimeSeconds;
	// 2. �����ð��� �����ϱ�
	//  -> ���� ����ð��� ready ���ð��� �ʰ��Ͽ��ٸ�
	if(currentTime > readyDelayTime)
	{
		// 3. ���¸� Playing ���� ��ȯ
		state = EGameState::Playing;

		currentTime = 0;
	}
}

// �ƹ��͵� ���� ����
// -> �̶����ʹ� Player �� ������ �� �ְ�, ���鵵 ���� �� �ִ�.
void ACPP_ShootingGameModeBase::Playing()
{
	
}

// R Ű�� ������ ������ �ϰ� �ʹ�.
void ACPP_ShootingGameModeBase::Gameover()
{

}

