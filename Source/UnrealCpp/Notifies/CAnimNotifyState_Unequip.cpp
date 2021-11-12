// Fill out your copyright notice in the Description page of Project Settings.


#include "CAnimNotifyState_Unequip.h"
#include "Global.h"
#include "CRifle.h"
#include "iRifle.h"


FString UCAnimNotifyState_Unequip::GetNotifyName_Implementation() const
{
	return "Unequip";
}

void UCAnimNotifyState_Unequip::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);
	CheckNull(MeshComp);

	IiRifle* rifle = Cast<IiRifle>(MeshComp->GetOwner());
	CheckNull(rifle);

	rifle->GetRifle()->Begin_Unequip();
}

void UCAnimNotifyState_Unequip::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);
	CheckNull(MeshComp);

	IiRifle* rifle = Cast<IiRifle>(MeshComp->GetOwner());
	CheckNull(rifle);

	rifle->GetRifle()->End_Unequip();
}
