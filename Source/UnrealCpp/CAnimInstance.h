// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCPP_API UCAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		float Speed;

public :
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float deltaSecond) override;

private:
	class ACharacter* OwnerCharacter;
};