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

	// Box Collision ������Ʈ �߰�
	boxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	// Hit event �߻� ��ų�� �ִ�.
	RootComponent = boxCollision;
	// Block ���·� �浹 �ɼ��� ����
	boxCollision->SetCollisionProfileName(TEXT("BlockAll"));

	// Body Mesh ������Ʈ �߰�
	bodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	bodyMesh->SetupAttachment(RootComponent);
	// �浹 �ȵǵ��� ó��
	bodyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// ���͸� ������ ������Ʈ�� �ٿ�����
	playerMove = CreateDefaultSubobject<UPlayerMove>(TEXT("PlayerMove"));
	playerFire = CreateDefaultSubobject<UPlayerFire>(TEXT("PlayerFire"));
	firePosition = CreateDefaultSubobject<UArrowComponent>(TEXT("FirePosition"));
	firePosition->SetupAttachment(RootComponent);

	// �ڵ����� ��Ʈ�ѷ� ��� ���� �� �ֵ��� ����
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

	// PlayerMove ������Ʈ�� SetupPlayer �Լ� ȣ�����ְ� �ʹ�.
	playerMove->SetupPlayerInputComponent(PlayerInputComponent);
	playerFire->SetupPlayerInputComponent(PlayerInputComponent);
}

