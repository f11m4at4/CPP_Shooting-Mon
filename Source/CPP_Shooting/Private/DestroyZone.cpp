// Fill out your copyright notice in the Description page of Project Settings.


#include "DestroyZone.h"
#include <Components/BoxComponent.h>
#include "ShootPlayer.h"

// Sets default values
ADestroyZone::ADestroyZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	RootComponent = collision;
	// collision 이 사용할 충돌 Profile 설정하기
	collision->SetCollisionProfileName(TEXT("DestroyZone"));
}

// Called when the game starts or when spawned
void ADestroyZone::BeginPlay()
{
	Super::BeginPlay();
	
	// Hit 이벤트가 발생하도록 처리
	collision->OnComponentHit.AddDynamic(this, &ADestroyZone::OnCollisionEnter);
}

// Called every frame
void ADestroyZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// 다른물체와 부딪혔을 때 호출될 함수
void ADestroyZone::OnCollisionEnter(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// 부딪힌 녀석이 Player 라면
	auto player = Cast<AShootPlayer>(OtherActor);
	if(player)
	{
		// 아래 내용은 처리하지 않는다.
		return;
	}

	OtherActor->Destroy();

	// 부딪힌 녀석이 Player 가 아니라면
	/*if(player == nullptr)
	{
		OtherActor->Destroy();
	}*/
}

