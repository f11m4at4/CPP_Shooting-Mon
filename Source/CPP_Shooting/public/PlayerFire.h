// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerFire.generated.h"


// 사용자가 발사버튼을 누르면 총알을 발사하고 싶다.
// 필요속성 : 총구, 총알공장

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CPP_SHOOTING_API UPlayerFire : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerFire();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);

	// 총알 발사 함수
	void Fire();

private:
	// 필요속성 : 총구, 총알공장
	UPROPERTY()
	class UArrowComponent* firePosition;

	UPROPERTY(EditDefaultsOnly, Category="BulletFactory", meta = (AllowPrivateAccess = true))
	TSubclassOf<class ABullet> bulletFactory;

	UPROPERTY()
	class AShootPlayer* me;

	// 총알 발사소리 속성
	UPROPERTY(EditDefaultsOnly, Category = "Audio")
	class USoundBase* bulletSound;
};
