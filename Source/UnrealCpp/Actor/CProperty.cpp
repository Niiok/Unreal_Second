// Fill out your copyright notice in the Description page of Project Settings.


#include "CProperty.h"

// Sets default values
ACProperty::ACProperty()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACProperty::BeginPlay()
{
	Super::BeginPlay();
	
	FString str;
	str.Append("A : ");
	str.Append(FString::FromInt(a));
	
	str.Append(" , B : ");
	str.Append(FString::FromInt(b));
	
	str.Append(" , C : ");
	str.Append(FString::FromInt(c));
	
	str.Append(" , D : ");
	str.Append(FString::FromInt(d));

	GLog->Log(str);
}

// Called every frame
void ACProperty::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

