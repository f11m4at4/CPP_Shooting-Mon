// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyMove.h"
#include "Enemy.h"
#include <Kismet/GameplayStatics.h>
#include "ShootPlayer.h"

// Sets default values for this component's properties
UEnemyMove::UEnemyMove()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEnemyMove::BeginPlay()
{
	Super::BeginPlay();

	me = Cast<AEnemy>(GetOwner());
	
	// target 찾기
	target = UGameplayStatics::GetActorOfClass(GetWorld(), AShootPlayer::StaticClass());

	// 랜덤값을 하나 구해서 확률이 50% 미만일 때는 아래로
	// 그렇지 않으면 타겟쪽으로
	int32 ratio = FMath::RandRange(1, 100);

	v = FVector::DownVector * speed;

	// target 쪽 방향으로 이동하기
	if (target && ratio > 50)
	{
		v = target->GetActorLocation() - me->GetActorLocation();
		v.Normalize();
		v *= speed;
	}
}


// Called every frame
void UEnemyMove::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// 아래로 계속 이동하고 싶다.
	// P = P0 + vt
	

	FVector P = me->GetActorLocation() + v * DeltaTime;
	me->SetActorLocation(P, true);
}

