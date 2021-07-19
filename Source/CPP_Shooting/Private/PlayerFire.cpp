// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerFire.h"
#include "ShootPlayer.h"
#include <Components/ArrowComponent.h>
#include "Bullet.h"
#include <Kismet/GameplayStatics.h>
#include "CPP_ShootingGameModeBase.h"

// Sets default values for this component's properties
UPlayerFire::UPlayerFire()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerFire::BeginPlay()
{
	Super::BeginPlay();

	me = Cast<AShootPlayer>(GetOwner());

	// �ѱ� �Ҵ����ֱ�
	if (me)
	{
		// ShootPlayer ���� �پ� �ִ� ������Ʈ ������
		// ���� ������Ʈ�� ���ϴ� Ÿ������ �����ϱ�
		firePosition = Cast<UArrowComponent>(me->GetDefaultSubobjectByName(TEXT("FirePosition")));
	}
}


// Called every frame
void UPlayerFire::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPlayerFire::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &UPlayerFire::Fire);
}

// ����ڰ� �߻��ư�� ������ ȣ��
void UPlayerFire::Fire()
{
	auto gameMode = Cast<ACPP_ShootingGameModeBase>(GetWorld()->GetAuthGameMode());
	if (gameMode && gameMode->state != EGameState::Playing)
	{
		// �Ʒ� ���� ������� �ʵ��� ����.
		return;
	}

	// �Ѿ��� �߻��ϰ� �ʹ�.
	// 1. �Ѿ��� �ʿ��ϴ�.(�Ѿ��� �����.)
	// -> Spawn Actor
	auto bullet = GetWorld()->SpawnActor<ABullet>(bulletFactory);
	// 2. �Ѿ��� ��ġ�ϰ� �ʹ�.
	if (bullet)
	{
		// ��ġ �� ����
		bullet->SetActorLocation(firePosition->GetComponentLocation());
		bullet->SetActorRotation(firePosition->GetComponentRotation());
	}

	// �Ѿ� ���� ���
	UGameplayStatics::PlaySound2D(GetWorld(), bulletSound);
}

