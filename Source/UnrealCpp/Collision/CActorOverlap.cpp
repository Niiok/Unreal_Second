// Fill out your copyright notice in the Description page of Project Settings.

#include "Global.h"
#include "CActorOverlap.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"

// Sets default values
ACActorOverlap::ACActorOverlap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CHelpers::CreateComponent<USceneComponent>(this, &Scene, "Scene");
	CHelpers::CreateComponent<UBoxComponent>(this, &Box, "Box", Scene);
	CHelpers::CreateComponent<UTextRenderComponent>(this, &Text, "Text", Scene);

	Box->SetRelativeScale3D(FVector(3));
	Box->bHiddenInGame = false;

	Text->SetRelativeLocation(FVector(0, 0, 100));
	Text->SetRelativeRotation(FRotator(0, 90, 0));
	Text->SetRelativeScale3D(FVector(2));
	Text->TextRenderColor = FColor::Red;
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	Text->Text = FText::FromString(GetName());
}

// Called when the game starts or when spawned
void ACActorOverlap::BeginPlay()
{
	Super::BeginPlay();
	
	OnActorBeginOverlap.AddDynamic(this, &ACActorOverlap::ActorBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &ACActorOverlap::ActorEndOverlap);
}

void ACActorOverlap::ActorBeginOverlap(AActor * OverlappedActor, AActor * OtherActor)
{
	FString str = "";
	str.Append(__FUNCTION__);
	str.Append(" : ");
	str.Append(OtherActor->GetActorLabel());
	CLog::Log(str);
}

void ACActorOverlap::ActorEndOverlap(AActor * OverlappedActor, AActor * OtherActor)
{
	FString str = "";
	str.Append(__FUNCTION__);
	str.Append(" : ");
	str.Append(OtherActor->GetActorLabel());
	CLog::Log(str);
}

