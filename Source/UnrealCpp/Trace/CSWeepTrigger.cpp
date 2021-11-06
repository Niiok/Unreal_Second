// Fill out your copyright notice in the Description page of Project Settings.


#include "CSWeepTrigger.h"
#include "Global.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"
#include "CExplosion.h"

// Sets default values
ACSWeepTrigger::ACSWeepTrigger()
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
	Box->bHiddenInGame = false;
}

// Called when the game starts or when spawned
void ACSWeepTrigger::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<ACExplosion*> explosions;
	CHelpers::FindActor(GetWorld(), explosions);

	OnActorBeginOverlap.AddDynamic(explosions[0], &ACExplosion::ActorBeginOverlap);
}

