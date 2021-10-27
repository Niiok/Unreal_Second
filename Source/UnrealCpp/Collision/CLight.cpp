// Fill out your copyright notice in the Description page of Project Settings.

#include "Global.h"
#include "CLight.h"
#include "CTrigger.h"
#include "Components/TextRenderComponent.h"
#include "Components/PointLightComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACLight::ACLight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	CHelpers::CreateComponent<USceneComponent>(this, &Scene, "Scene");
	CHelpers::CreateComponent<UTextRenderComponent>(this, &Text, "Text", Scene);
	CHelpers::CreateComponent<UPointLightComponent>(this, &Light, "Light", Scene);

	Text->SetRelativeLocation(FVector(0, 0, 100));
	Text->SetRelativeRotation(FRotator(0, 90, 0));
	Text->SetRelativeScale3D(FVector(2));
	Text->TextRenderColor = FColor::Red;
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	Text->Text = FText::FromString(GetName());

	Light->Intensity = 1e+4f;
	Light->AttenuationRadius = 200;
	Light->LightColor = FColor(255, 128, 50);
}

// Called when the game starts or when spawned
void ACLight::BeginPlay()
{
	Super::BeginPlay();
	Light->SetVisibility(false);

	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACTrigger::StaticClass(), actors);
	CheckFalse(actors.Num() > 0);

	ACTrigger* trigger = Cast<ACTrigger>(actors[0]);
	trigger->OnBoxLightBeginOverlap.BindUFunction(this, "OnLight");
	trigger->OnBoxLightEndOverlap.BindUFunction(this, "OffLight");
}

void ACLight::OnLight()
{
	Light->SetVisibility(true);
}

void ACLight::OffLight()
{
	Light->SetVisibility(false);
}