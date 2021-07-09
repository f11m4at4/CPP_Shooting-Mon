// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootPlayer.h"
#include "CPP_Shooting.h"
#include "PlayerMove.h"

// Sets default values
AShootPlayer::AShootPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ���͸� ������ ������Ʈ�� �ٿ�����
	playerMove = CreateDefaultSubobject<UPlayerMove>(TEXT("PlayerMove"));
	
}

// Called when the game starts or when spawned
void AShootPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	int result = Multiply(1+2, 1 + 1);

	PRINTLOG(TEXT("%s, %d"), TEXT("Hello World"), result);
}

// Called every frame
void AShootPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShootPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// PlayerMove ������Ʈ�� SetupPlayer �Լ� ȣ�����ְ� �ʹ�.
	playerMove->SetupPlayerInputComponent(PlayerInputComponent);
}
