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

}

// 사용자가 발사버튼을 누르면 호출
void UPlayerFire::Fire()
{
	// 총알을 발사하고 싶다.
}

