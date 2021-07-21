// Fill out your copyright notice in the Description page of Project Settings.


#include "GameoverUI.h"
#include <Kismet/KismetSystemLibrary.h>
#include <Kismet/GameplayStatics.h>
#include "CPP_ShootingGameModeBase.h"

void UGameoverUI::OnClick_Restart()
{
	// ������ ������Ѵ�.
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("ShootingMap"));
	// gameoverui �� ȭ�鿡�� ��������
	auto gamemode = Cast<ACPP_ShootingGameModeBase>(GetWorld()->GetAuthGameMode());
	gamemode->gameoverUI->RemoveFromViewport();
}

void UGameoverUI::OnClick_Quit()
{
	// ���ø����̼��� ����
	UKismetSystemLibrary::QuitGame(GetWorld(), GetWorld()->GetFirstPlayerController(), EQuitPreference::Quit, false);
}
