// Copyright Epic Games, Inc. All Rights Reserved.


#include "CPP_ShootingGameModeBase.h"
#include "CPP_Shooting.h"
#include <Blueprint/UserWidget.h>

ACPP_ShootingGameModeBase::ACPP_ShootingGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

// 태어날때 불리는 함수
void ACPP_ShootingGameModeBase::BeginPlay()
{
	Super::BeginPlay();
}

void ACPP_ShootingGameModeBase::InitGameState()
{
	Super::InitGameState();
	
	// ready ui 가 화면에 보이도록 처리하고 싶다.
	// 0. ready ui 가 없을 때
	if(readyUI == nullptr)
	{
		// 1. ready ui 가 있어야 한다.
		readyUI = CreateWidget<UUserWidget>(GetWorld(), readyUIFactory);
	}
	if (playingUI == nullptr)
	{
		// 1. playingUI ui 가 있어야 한다.
		playingUI = CreateWidget<UUserWidget>(GetWorld(), playingUIFactory);
	}

	// 2. ui 가 화면에 보이도록 처리
	if (readyUI)
	{
		readyUI->AddToViewport();
	}
	state = EGameState::Ready;
}

void ACPP_ShootingGameModeBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// state 값 enum 데이터를 콘솔에 출력하기
	/*const UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EGameState"), true);
	if(enumPtr)
	{
		PRINTLOG(TEXT("%s"), *enumPtr->GetNameStringByValue((uint8)state));
	}*/
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

// Ready 상태일때 내용
// 일정시간 기다리다가 상태를 Playing 으로 전환
// 필요속성 : 일정시간(기다리는시간), 경과시간
void ACPP_ShootingGameModeBase::Ready()
{
	// 일정시간 기다리다가 상태를 Playing 으로 전환
	// 1. 시간이 흘렀으니까
	currentTime += GetWorld()->DeltaTimeSeconds;
	// 2. 일정시간이 됐으니까
	//  -> 만약 경과시간이 ready 대기시간을 초과하였다면
	if(currentTime > readyDelayTime)
	{
		// 3. 상태를 Playing 으로 전환
		state = EGameState::Playing;

		readyUI->RemoveFromViewport();
		playingUI->AddToViewport();

		currentTime = 0;
	}
}

// 아무것도 하지 말자
// -> 이때부터는 Player 가 움직일 수 있고, 적들도 나올 수 있다.
// play ui 를 일정시간 지나면 없어지도록하자
// 필요속성 : 일정시간(ui 보여질시간)
void ACPP_ShootingGameModeBase::Playing()
{
	// play ui 를 일정시간 지나면 없어지도록하자
	// 1. 시간이 흘렀으니까
	currentTime += GetWorld()->DeltaTimeSeconds;
	// 2. 일정시간이 지났으니까
	// 만약 ui 가 보여지고 있다면
	if(playingUI->IsInViewport() && currentTime > playingUITime)
	{
		// 3. ui 없어지게 하고 싶다.
		playingUI->RemoveFromViewport();
		currentTime = 0;
	}
}

// R 키를 누르면 리셋을 하고 싶다.
void ACPP_ShootingGameModeBase::Gameover()
{

}

