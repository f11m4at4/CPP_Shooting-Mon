// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

// UE_LOG -> Category 추가
DECLARE_LOG_CATEGORY_EXTERN(Shoot, Log, All);

// 어디에서 찍혔는지 정보값 매크로
#define APPINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))

// 어디서 호출했는지 그냥 찍어보는 함수
#define CALLINFO() UE_LOG(Shoot, Warning, TEXT("%s"), *APPINFO)

// 사용자가 로그 찍을 때 이용할 매크로 함수
#define PRINTLOG(fmt, ...) UE_LOG(Shoot, Warning, TEXT("%s %s"), *APPINFO, *FString::Printf(fmt, ##__VA_ARGS__))

#define Multiply(x, y) ((x) * (y))