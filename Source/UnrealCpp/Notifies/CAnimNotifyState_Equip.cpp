// Fill out your copyright notice in the Description page of Project Settings.


#include "CAnimNotifyState_Equip.h"
#include "Global.h"
#include "CRifle.h"
#include "iRifle.h"


FString UCAnimNotifyState_Equip::GetNotifyName_Implementation() const
{
	return "Equip";
}

void UCAnimNotifyState_Equip::NotifyBegin(USkeletalMeshComponent * MeshComp, UAnimSequenceBase * Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);
	CheckNull(MeshComp);

	IiRifle* rifle = Cast<IiRifle>(MeshComp->GetOwner());
	CheckNull(rifle);

	rifle->GetRifle()->Begin_Equip();
}

void UCAnimNotifyState_Equip::NotifyEbd(USkeletalMeshComponent * MeshComp, UAnimSequenceBase * Animation)
{
	Super::NotifyEnd(MeshComp, Animation);
	CheckNull(MeshComp);

	IiRifle* rifle = Cast<IiRifle>(MeshComp->GetOwner());
	CheckNull(rifle);

	rifle->GetRifle()->End_Equip();
}
