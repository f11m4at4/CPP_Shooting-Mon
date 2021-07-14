// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyManager.h"
#include "Enemy.h"

// Sets default values
AEnemyManager::AEnemyManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 일정시간에 한번씩 적을 만들고 싶다.
	// 1. 시간이 흘렀으니까 -> ue4 시간이 흐르는것을 어떻게 체크
	currentTime += DeltaTime;
	// 2. 일정시간이 됐으니 
	//  -> 만약 경과시간이 생성시간을 초과하였다면
	if(currentTime > createTime)
	{
		// 3. 적을 만들고 싶다. -> Actor 를 동적으로 생성하는 방법(Spawn)
		auto enemy = GetWorld()->SpawnActor<AEnemy>(enemyFactory, GetTransform());

		currentTime = 0;
	}
}

