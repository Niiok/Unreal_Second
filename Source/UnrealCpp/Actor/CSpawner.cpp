// Fill out your copyright notice in the Description page of Project Settings.


#include "CSpawner.h"
#include "Global.h"
#include "CSpawnActor.h"

// Sets default values
ACSpawner::ACSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	for (int32 i = 0; i < 3; i++)
	{
		FTransform transform;
		FVector location = GetActorLocation();
		spawnActors[i] = GetWorld()->SpawnActor<ACSpawnActor>(spawnClass[i], transform);
		spawnActors[i]->SetActorLocation(FVector(location.X + i * 400,	
			location.Y, location.Z));
	}
}

// Called every frame
void ACSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

