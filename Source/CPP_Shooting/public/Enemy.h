// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Enemy.generated.h"

UCLASS()
class CPP_SHOOTING_API AEnemy : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void OnTriggerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// Box Collision
	UPROPERTY(VisibleAnywhere, Category="Collision")
	class UBoxComponent* collision;
	// static mesh
	UPROPERTY(VisibleAnywhere, Category = "BodyMesh")
	class UStaticMeshComponent* bodyMesh;
	// ÃÑ±¸
	UPROPERTY(VisibleAnywhere, Category="FirePosition")
	class UArrowComponent* firePosition;

	// EnemyMove ÄÄÆ÷³ÍÆ®
	UPROPERTY(VisibleAnywhere, Category="EnemyMove")
	class UEnemyMove* enemyMove;
};
