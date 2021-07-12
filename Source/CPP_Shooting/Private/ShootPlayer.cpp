// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootPlayer.h"
#include "CPP_Shooting.h"
#include "PlayerMove.h"
#include "PlayerFire.h"
#include <Components/ArrowComponent.h>
#include <Components/BoxComponent.h>
#include <Components/StaticMeshComponent.h>

// Sets default values
AShootPlayer::AShootPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Box Collision 컴포넌트 추가
	boxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	// Hit event 발생 시킬수 있다.
	RootComponent = boxCollision;
	// Block 형태로 충돌 옵션이 설정
	boxCollision->SetCollisionProfileName(TEXT("BlockAll"));

	// Body Mesh 컴포넌트 추가
	bodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	bodyMesh->SetupAttachment(RootComponent);
	// 충돌 안되도록 처리
	bodyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// 액터를 구성할 컴포넌트를 붙여주자
	playerMove = CreateDefaultSubobject<UPlayerMove>(TEXT("PlayerMove"));
	playerFire = CreateDefaultSubobject<UPlayerFire>(TEXT("PlayerFire"));
	firePosition = CreateDefaultSubobject<UArrowComponent>(TEXT("FirePosition"));
	firePosition->SetupAttachment(RootComponent);

	// 자동으로 컨트롤러 제어를 받을 수 있도록 설정
	AutoPossessPlayer = EAutoReceiveInput::Player0;
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

	// PlayerMove 컴포넌트의 SetupPlayer 함수 호출해주고 싶다.
	playerMove->SetupPlayerInputComponent(PlayerInputComponent);
	playerFire->SetupPlayerInputComponent(PlayerInputComponent);
}

