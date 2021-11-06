// Fill out your copyright notice in the Description page of Project Settings.


#include "CCylinder.h"
#include "Global.h"
#include "Components/TextRenderComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ACCylinder::ACCylinder()
{
	CHelpers::CreateComponent<USceneComponent>(this, &Scene, "Scene");
	CHelpers::CreateComponent<UTextRenderComponent>(this, &Text, "Text", Scene);
	CHelpers::CreateComponent<UStaticMeshComponent>(this, &Mesh, "Mesh", Scene);

	Text->SetRelativeLocation(FVector(0, 0, 140));
	Text->SetRelativeRotation(FRotator(0, 180, 0));
	Text->SetRelativeScale3D(FVector(2));
	Text->TextRenderColor = FColor::Red;
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	Text->Text = FText::FromString(GetName());

	UStaticMesh* mesh;
	CHelpers::GetAsset<UStaticMesh>(&mesh,
		"StaticMesh'/Game/Meshes/Mesh_Cylinder.Mesh_Cylinder'");

	Mesh->SetStaticMesh(mesh);
	//Mesh->SetSimulatePhysics(false);
	Mesh->SetRelativeScale3D(FVector(1, 1, 2.5f));

}

// Called when the game starts or when spawned
void ACCylinder::BeginPlay()
{
	Super::BeginPlay();
	
}
