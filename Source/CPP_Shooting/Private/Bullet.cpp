// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include <Components/BoxComponent.h>

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
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

	// bodyMesh 에 들어갈 Static Mesh 데이터 동적 로드하여 할당
	ConstructorHelpers::FObjectFinder<UStaticMesh> TempMesh(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	// check Load complete
	if (TempMesh.Succeeded())
	{
		bodyMesh->SetStaticMesh(TempMesh.Object);
	}
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 위로 계속 이동시키고 싶다.
	FVector dir = FVector::UpVector;
	// 필요속성 : 이동속도
	// P = P0 + vt
	FVector P = GetActorLocation() + dir * speed * DeltaTime;
	SetActorLocation(P, true);
}

