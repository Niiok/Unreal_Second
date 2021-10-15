// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CProperty.generated.h"

UCLASS()
class UNREALCPP_API ACProperty : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere)
		int a = 10;
	UPROPERTY(EditInstanceOnly)
		int b = 20;
	UPROPERTY(EditDefaultsOnly)
		int c;

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		int d = 40;

public:	
	// Sets default values for this actor's properties
	ACProperty();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
