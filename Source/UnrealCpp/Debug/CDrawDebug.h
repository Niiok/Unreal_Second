// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DrawDebugHelpers.h"
#include "CDrawDebug.generated.h"

UCLASS()
class UNREALCPP_API ACDrawDebug : public AActor
{
	GENERATED_BODY()
	
private:
	FVector InitLocation[5];
	FVector Location[5];
	FBox Box;
	FTransform Transform;

public:	
	// Sets default values for this actor's properties
	ACDrawDebug();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
