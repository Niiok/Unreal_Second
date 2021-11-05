// Fill out your copyright notice in the Description page of Project Settings.


#include "CCube.h"
#include "Global.h"
#include "Components/StaticMeshComponent.h"

//StaticMesh'/Game/Meshes/Mesh_Cube.Mesh_Cube'

// Sets default values
ACCube::ACCube()
{
	CHelpers::CreateComponent<UStaticMeshComponent>(this, &Mesh, "Mesh");

	UStaticMesh* mesh;
	CHelpers::GetAsset<UStaticMesh>(&mesh,
		"StaticMesh'/Game/Meshes/Mesh_Cube.Mesh_Cube'");

	Mesh->SetStaticMesh(mesh);
	Mesh->SetSimulatePhysics(true);
	Mesh->SetCollisionObjectType(ECollisionChannel::ECC_PhysicsBody);
}

// Called when the game starts or when spawned
void ACCube::BeginPlay()
{
	Super::BeginPlay();
	
}


