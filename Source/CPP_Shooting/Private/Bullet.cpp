// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include <Components/BoxComponent.h>

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
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

	// bodyMesh �� �� Static Mesh ������ ���� �ε��Ͽ� �Ҵ�
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
	
	SetLifeSpan(3);

}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ���� ��� �̵���Ű�� �ʹ�.
	FVector dir = FVector::UpVector;
	// �ʿ�Ӽ� : �̵��ӵ�
	// P = P0 + vt
	FVector P = GetActorLocation() + dir * speed * DeltaTime;
	SetActorLocation(P, true);
}

