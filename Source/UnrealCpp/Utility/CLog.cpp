// Fill out your copyright notice in the Description page of Project Settings.


#include "CLog.h"
#include "Logging/LogMacros.h"
#include "Engine.h"

void CLog::Print(int32 InValue, int32 InKey, float Duration, FColor inColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, Duration, inColor,
		FString::FromInt(InValue));
}

void CLog::Print(const FString & inString, int32 InKey, float Duration, FColor inColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, Duration, inColor,
		inString);
}

void CLog::Log(int32 InValue)
{
}

void CLog::Log(float InValue)
{
}

void CLog::Log(const FString & InValue)
{
}

void CLog::Log(const FVector & InValue)
{
}

void CLog::Log(const FRotator & InValue)
{
}

void CLog::Log(const UObject * InObject)
{
	/*FString str;
	if (!!InObject)
		str.Append(InObject->GetName());
	str.Append((!!InObject) ? "Not Null" : "Null");
	UE_LOG(GameProject, Display, L"%s", *str);*/
}

void CLog::Log(const FString & InFuncName, int32 InLineNumber)
{
	/*FString str;
	str.Append(InFuncName);
	str.Append(" , ");
	str.Append(FString::FromInt(InLineNumber));
	UE_LOG(GameProject, Display, L"%s", *str);*/
}
