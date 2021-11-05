// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CLineTrace.generated.h"

class ACCylinder;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTraceResult, class AActor*, InActor, FLinearColor, InColor);

UCLASS()
class UNREALCPP_API ACLineTrace : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ACLineTrace();


private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Scene;

	UPROPERTY(VisibleDefaultsOnly)
		class UTextRenderComponent* Text;
	
	TArray<ACCylinder*> Cylinders;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	UPROPERTY(BlueprintAssignable)
		FTraceResult	OnTraceResult;

protected:
	UFUNCTION(BlueprintCallable)
		void RestoreColor(class ACPlayer* InPlayer);

private:
	UFUNCTION()
		void StartJump(class AActor* InActor, FLinearColor InColor);


};
