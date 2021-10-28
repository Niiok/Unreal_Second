// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CBox.generated.h"

UCLASS()
class UNREALCPP_API ACBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Scene;

	UPROPERTY(VisibleDefaultsOnly)
		class UTextRenderComponent* Text;

	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* Mesh[3];


	//UPROPERTY(VisibleDefaultsOnly)
	UMaterialInstanceDynamic*	Materials[3];
	FVector						WorldLocation[3];


private:
	UFUNCTION()
		void OnPhysics(int32 InIndex, FLinearColor InColor);
};
