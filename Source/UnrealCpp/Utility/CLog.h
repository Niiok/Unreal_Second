// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#define PrintLine() {CLog::Log(__FUNCTION__, __LINE__);}

/**
 * 
 */
class UNREALCPP_API CLog
{
public:
	static void Print(int32 InValue, int32 InKey = -1,
		float Duration = 10.0f, FColor inColor = FColor::Blue);
	
	static void Print(const FString& inString, int32 InKey = -1,
		float Duration = 10.0f, FColor inColor = FColor::Blue);

	static void Log(int32 InValue);
	static void Log(float InValue);
	static void Log(const FString& InValue);
	static void Log(const FVector& InValue);
	static void Log(const FRotator& InValue);
	static void Log(const UObject* InObject);
	static void Log(const FString& InFuncName, int32 InLineNumber);

};
