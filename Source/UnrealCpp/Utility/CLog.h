// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class UNREALCPP_API CLog
{
public:
	static void Print(int32 InValue, int32 InKey = -1,
		float Duration = 10.0f, FColor inColor = FColor::Blue);
};
