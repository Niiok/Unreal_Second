// Copyright Epic Games, Inc. All Rights Reserved.


#include "UnrealCppGameModeBase.h"
#include "Global.h"

// Blueprint'/Game/BP_CPlayer.BP_CPlayer'

AUnrealCppGameModeBase::AUnrealCppGameModeBase()
{
	CHelpers::GetClass<APawn>(&DefaultPawnClass, "Blueprint'/Game/BP_CPlayer.BP_CPlayer_C'");
}