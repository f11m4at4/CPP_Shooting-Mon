// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyManager.generated.h"

// �����ð��� �ѹ��� ���� ����� �ʹ�.
// 1. �ð��� �귶���ϱ� -> ue4 �ð��� �帣�°��� ��� üũ
// 2. �����ð��� ������ 
// 3. ���� ����� �ʹ�. -> Actor �� �������� �����ϴ� ���(Spawn)
// �ʿ�Ӽ� : ������, �����ð�, ����ð�

UCLASS()
class CPP_SHOOTING_API AEnemyManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	// �ʿ�Ӽ� : ������, �����ð�, ����ð�
	UPROPERTY(EditDefaultsOnly, Category = "Enemy Factory")
	TSubclassOf<class AEnemy> enemyFactory;

	UPROPERTY(EditAnywhere, Category="Setting")
	float createTime = 2;

	UPROPERTY()
	float currentTime = 0;
};
