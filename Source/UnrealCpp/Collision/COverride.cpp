// Fill out your copyright notice in the Description page of Project Settings.


#include "COverride.h"
#include "Global.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"

// Sets default values
ACOverride::ACOverride()
{
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
void ACOverride::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &ACOverride::ActorBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &ACOverride::ActorEndOverlap);
}

void ACOverride::ActorBeginOverlap(AActor * OverlappedActor, AActor * OtherActor)
{
}

void ACOverride::ActorEndOverlap(AActor * OverlappedActor, AActor * OtherActor)
{
}

