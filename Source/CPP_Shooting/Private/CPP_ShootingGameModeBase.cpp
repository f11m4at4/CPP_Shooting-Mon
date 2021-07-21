// Copyright Epic Games, Inc. All Rights Reserved.


#include "CPP_ShootingGameModeBase.h"
#include "CPP_Shooting.h"
#include <Blueprint/UserWidget.h>
#include <Kismet/GameplayStatics.h>

ACPP_ShootingGameModeBase::ACPP_ShootingGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

// �¾�� �Ҹ��� �Լ�
void ACPP_ShootingGameModeBase::BeginPlay()
{
	Super::BeginPlay();
}

void ACPP_ShootingGameModeBase::InitGameState()
{
	Super::InitGameState();
	
	// ready ui �� ȭ�鿡 ���̵��� ó���ϰ� �ʹ�.
	// 0. ready ui �� ���� ��
	if(readyUI == nullptr)
	{
		// 1. ready ui �� �־�� �Ѵ�.
		readyUI = CreateWidget<UUserWidget>(GetWorld(), readyUIFactory);
	}
	if (playingUI == nullptr)
	{
		// 1. playingUI ui �� �־�� �Ѵ�.
		playingUI = CreateWidget<UUserWidget>(GetWorld(), playingUIFactory);
	}
	if (gameoverUI == nullptr)
	{
		// 1. gameoverUI ui �� �־�� �Ѵ�.
		gameoverUI = CreateWidget<UUserWidget>(GetWorld(), gameoverUIFactory);
	}

	// 2. ui �� ȭ�鿡 ���̵��� ó��
	if (readyUI)
	{
		readyUI->AddToViewport();
	}
	state = EGameState::Ready;
}

void ACPP_ShootingGameModeBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// state �� enum �����͸� �ֿܼ� ����ϱ�
	/*const UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EGameState"), true);
	if(enumPtr)
	{
		PRINTLOG(TEXT("%s"), *enumPtr->GetNameStringByValue((uint8)state));
	}*/
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

// Gameover ó���� �Լ�
// ���¸� gameover �� �����, gameoverUI ����
// ������ �����ϰ� ���콺 Ŀ���� ȭ�鿡 ���� �ʹ�.
void ACPP_ShootingGameModeBase::OnGameoverProcess()
{
	// ������ �����ϰ� ���콺 Ŀ���� ȭ�鿡 ���� �ʹ�.
	UGameplayStatics::SetGamePaused(GetWorld(), true);
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;

	state = EGameState::Gameover;
	gameoverUI->AddToViewport();
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

		readyUI->RemoveFromViewport();
		playingUI->AddToViewport();

		currentTime = 0;
	}
}

// �ƹ��͵� ���� ����
// -> �̶����ʹ� Player �� ������ �� �ְ�, ���鵵 ���� �� �ִ�.
// play ui �� �����ð� ������ ��������������
// �ʿ�Ӽ� : �����ð�(ui �������ð�)
void ACPP_ShootingGameModeBase::Playing()
{
	// play ui �� �����ð� ������ ��������������
	// 1. �ð��� �귶���ϱ�
	currentTime += GetWorld()->DeltaTimeSeconds;
	// 2. �����ð��� �������ϱ�
	// ���� ui �� �������� �ִٸ�
	if(playingUI->IsInViewport() && currentTime > playingUITime)
	{
		// 3. ui �������� �ϰ� �ʹ�.
		playingUI->RemoveFromViewport();
		currentTime = 0;
	}
}

// R Ű�� ������ ������ �ϰ� �ʹ�.
void ACPP_ShootingGameModeBase::Gameover()
{

}

