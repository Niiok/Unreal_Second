// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CTrigger.generated.h"

DECLARE_DELEGATE(FBoxLightBeginOverlap);
DECLARE_DELEGATE(FBoxLightEndOverlap);

UCLASS()
class UNREALCPP_API ACTrigger : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Scene;

	UPROPERTY(VisibleDefaultsOnly)
		class UBoxComponent* Box;

	UPROPERTY(VisibleDefaultsOnly)
		class UTextRenderComponent* Text;

private:

	UFUNCTION()
		void ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
	UFUNCTION()
		void ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor);

public:
	FBoxLightBeginOverlap	OnBoxLightBeginOverlap;
	FBoxLightEndOverlap		OnBoxLightEndOverlap;
};
