// Fill out your copyright notice in the Description page of Project Settings.


#include "CLog.h"
#include "Engine.h"

void CLog::Print(int32 InValue, int32 InKey, float Duration, FColor inColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, Duration, inColor,
		FString::FromInt(InValue));
}
