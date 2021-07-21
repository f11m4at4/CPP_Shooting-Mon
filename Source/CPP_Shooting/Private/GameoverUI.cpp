// Fill out your copyright notice in the Description page of Project Settings.


#include "GameoverUI.h"
#include <Kismet/KismetSystemLibrary.h>
#include <Kismet/GameplayStatics.h>
#include "CPP_ShootingGameModeBase.h"

void UGameoverUI::OnClick_Restart()
{
	// 레벨을 재시작한다.
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("ShootingMap"));
	// gameoverui 는 화면에서 내려주자
	auto gamemode = Cast<ACPP_ShootingGameModeBase>(GetWorld()->GetAuthGameMode());
	gamemode->gameoverUI->RemoveFromViewport();
}

void UGameoverUI::OnClick_Quit()
{
	// 어플리케이션을 종료
	UKismetSystemLibrary::QuitGame(GetWorld(), GetWorld()->GetFirstPlayerController(), EQuitPreference::Quit, false);
}
