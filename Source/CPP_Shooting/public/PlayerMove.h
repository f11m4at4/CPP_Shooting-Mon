// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerMove.generated.h"

// 사용자의 입력에 따라 상하좌우로 이동하고 싶다.
// 필요속성 : 이동속도

UCLASS( ClassGroup=(HO), meta=(BlueprintSpawnableComponent) )
class CPP_SHOOTING_API UPlayerMove : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerMove();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);

	void Horizontal(float value);
	void Vertical(float value);
	
public:
	// 필요속성 : 이동속도
	UPROPERTY(EditAnywhere, Category="Setting", BlueprintReadOnly)
	float speed = 500;

private:
	UPROPERTY()
	class AShootPlayer* me;

	UPROPERTY()
	float h;
	UPROPERTY()
	float v;
};
