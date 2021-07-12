// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

UCLASS()
class CPP_SHOOTING_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Box
	UPROPERTY(EditAnywhere, Category="Collision")
	class UBoxComponent* boxCollision;
	// StaticMesh
	UPROPERTY(EditAnywhere, Category = "BodyMesh")
	class UStaticMeshComponent* bodyMesh;
};
