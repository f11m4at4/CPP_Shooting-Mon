// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMove.h"
#include "ShootPlayer.h"
#include "CPP_ShootingGameModeBase.h"

// Sets default values for this component's properties
UPlayerMove::UPlayerMove()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	//speed = 500;
}


// Called when the game starts
void UPlayerMove::BeginPlay()
{
	Super::BeginPlay();

	me = Cast<AShootPlayer>(GetOwner());
	
}


// Called every frame
void UPlayerMove::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// GameMode 의 상태가 Playing 이 아니라면
	auto gameMode = Cast<ACPP_ShootingGameModeBase>(GetWorld()->GetAuthGameMode());
	if(gameMode && gameMode->state != EGameState::Playing)
	{
		// 아래 내용 실행되지 않도록 하자.
		return;
	}
	// 사용자의 입력에 따라 상하좌우로 이동하고 싶다.
	// 1. 방향이 필요
	FVector dir = FVector(0, h, v);
	// 2. 이동하고 싶다.
	// P = P0 + vt
	
	if (me)
	{
		FVector P0 = me->GetActorLocation();
		FVector P = P0 + dir * speed * DeltaTime;
		me->SetActorLocation(P, true);
	}
}

void UPlayerMove::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// input bind
	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &UPlayerMove::Horizontal);
	PlayerInputComponent->BindAxis(TEXT("Vertical"), this, &UPlayerMove::Vertical);
}


void UPlayerMove::Horizontal(float value)
{
	h = value;
}

void UPlayerMove::Vertical(float value)
{
	v = value;
}

