// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerFire.h"
#include "ShootPlayer.h"
#include <Components/ArrowComponent.h>
#include "Bullet.h"

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

	// 총구 할당해주기
	if (me)
	{
		// ShootPlayer 한테 붙어 있는 컴포넌트 얻어오기
		// 얻어온 컴포넌트를 원하는 타입으로 변경하기
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

// 사용자가 발사버튼을 누르면 호출
void UPlayerFire::Fire()
{
	// 총알을 발사하고 싶다.
	// 1. 총알이 필요하다.(총알을 만든다.)
	// -> Spawn Actor
	auto bullet = GetWorld()->SpawnActor<ABullet>(bulletFactory);
	// 2. 총알을 배치하고 싶다.
	if (bullet)
	{
		// 위치 값 지정
		bullet->SetActorLocation(firePosition->GetComponentLocation());
		bullet->SetActorRotation(firePosition->GetComponentRotation());
	}
}

