// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include <Components/BoxComponent.h>
#include <Components/StaticMeshComponent.h>
#include <Components/ArrowComponent.h>
#include "EnemyMove.h"
#include <Kismet/GameplayStatics.h>
#include "ShootPlayer.h"
#include "CPP_ShootingGameModeBase.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	RootComponent = collision;
	//collision->SetCollisionObjectType(ECollisionChannel::ECC_GameTraceChannel1);
	collision->SetCollisionProfileName(TEXT("Enemy"));

	bodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	bodyMesh->SetupAttachment(RootComponent);
	bodyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	firePosition = CreateDefaultSubobject<UArrowComponent>(TEXT("FirePosition"));
	firePosition->SetupAttachment(RootComponent);

	enemyMove = CreateDefaultSubobject<UEnemyMove>(TEXT("EnemyMove"));



}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	collision->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::OnTriggerEnter);

	// 생명력
	SetLifeSpan(3);
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemy::OnTriggerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// 만약 부딪힌 녀석이 Enemy 라면 처리하지 않고 싶다.
	//auto enemy = Cast<AEnemy>(OtherActor);
	////if (OtherActor->GetName().Contains(TEXT("Enemy")))
	//if(enemy)
	//{
	//	return;
	//}

	// 부딪힌 녀석이 Player 라면 상태를 Gameover 로 전환하고 싶다.
	auto player = Cast<AShootPlayer>(OtherActor);
	if (player)
	{
		auto gameMode = Cast<ACPP_ShootingGameModeBase>(GetWorld()->GetAuthGameMode());
		gameMode->state = EGameState::Gameover;
	}

	// 폭발효과 생성
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), explosionFactory, GetActorTransform());

	UGameplayStatics::PlaySound2D(GetWorld(), explosionSound);

	// 갸도 죽고
	OtherActor->Destroy();
	// 나도 죽고
	Destroy();
}

