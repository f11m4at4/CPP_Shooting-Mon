// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerFire.h"
#include "ShootPlayer.h"

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

}

// ����ڰ� �߻��ư�� ������ ȣ��
void UPlayerFire::Fire()
{
	// �Ѿ��� �߻��ϰ� �ʹ�.
}

