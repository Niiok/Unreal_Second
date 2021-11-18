// Fill out your copyright notice in the Description page of Project Settings.


#include "CAnimInstance.h"
#include "Global.h"
#include "GameFrameWork/Character.h"
#include "CRifle.h"
#include "iRifle.h"

void UCAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	OwnerCharacter = Cast<ACharacter>(TryGetPawnOwner());
}

void UCAnimInstance::NativeUpdateAnimation(float deltaSecond)
{
	Super::NativeUpdateAnimation(deltaSecond);

	CheckNull(OwnerCharacter);

	Speed = OwnerCharacter->GetVelocity().Size2D();
	Direction = CalculateDirection(OwnerCharacter->GetVelocity(),
		OwnerCharacter->GetControlRotation());

	Pitch = OwnerCharacter->GetBaseAimRotation().Pitch;

	IiRifle* rifle = Cast<IiRifle>(OwnerCharacter);
	if (!!rifle)
	{
		bEquipped = rifle->GetRifle()->GetEquipped();
		bAiming = rifle->GetRifle()->GetAiming();
	}
}
