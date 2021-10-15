// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CSpawnActor.generated.h"


UCLASS()
class UNREALCPP_API ACSpawnActor : public AActor
{
	GENERATED_BODY()

protected:
	/*UPROPERTY(BlueprintReadOnly, EditAnywhere)
		UStaticMeshComponent* Mesh;*/


public:	
	// Sets default values for this actor's properties
	ACSpawnActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* Mesh;

private:
	class UMaterialInstanceDynamic* Material;

	UFUNCTION()
		void ChangeColor();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
