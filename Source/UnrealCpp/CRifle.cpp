// Fill out your copyright notice in the Description page of Project Settings.


#include "CRifle.h"
#include "Global.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Character.h"
#include "CPlayer.h"
#include "Animation/AnimMontage.h"


ACRifle * ACRifle::Spawn(UWorld * InWorld, ACharacter * InOwner)
{
	FActorSpawnParameters param;
	param.Owner = InOwner;
	return InWorld->SpawnActor<ACRifle>(param);
}



// Sets default values
ACRifle::ACRifle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CHelpers::CreateComponent<USkeletalMeshComponent>(this, &Mesh, "Mesh");
	USkeletalMesh* mesh;
	CHelpers::GetAsset<USkeletalMesh>(&mesh, 
		"SkeletalMesh'/Game/Weapons/Meshes/AR4/SK_AR4.SK_AR4'");
	Mesh->SetSkeletalMesh(mesh);

	CHelpers::GetAsset<UAnimMontage>(&GrabMontage,
		"AnimMontage'/Game/Character/Montages/Rifle_Grab_Montage.Rifle_Grab_Montage'");
	CHelpers::GetAsset<UAnimMontage>(&UngrabMontage,
		"AnimMontage'/Game/Character/Montages/Rifle_Ungrab_Montage.Rifle_Ungrab_Montage'");
}

// Called when the game starts or when spawned
void ACRifle::BeginPlay()
{
	Super::BeginPlay();
	
	OwnerCharacter = Cast<ACharacter>(GetOwner());
	AttachToComponent(OwnerCharacter->GetMesh(),
		FAttachmentTransformRules(EAttachmentRule::KeepRelative, true),
			HolsterSocket);
}

// Called every frame
void ACRifle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}





void ACRifle::Equip()
{
	CheckTrue(bEquipped);
	CheckTrue(bEquipping);

	bEquipping = true;
	OwnerCharacter->PlayAnimMontage(GrabMontage);
}

void ACRifle::Begin_Equip()
{
	bEquipped = true;
	AttachToComponent(OwnerCharacter->GetMesh(),
		FAttachmentTransformRules(EAttachmentRule::KeepRelative, true),
		HandSocket);
}

void ACRifle::End_Equip()
{
	bEquipping = false;
}

void ACRifle::Unequip()
{
	CheckFalse(bEquipped);
	CheckTrue(bEquipping);

	bEquipping = true;
	OwnerCharacter->PlayAnimMontage(UngrabMontage);
}

void ACRifle::Begin_Unequip()
{
	bEquipped = false;
	AttachToComponent(OwnerCharacter->GetMesh(),
		FAttachmentTransformRules(EAttachmentRule::KeepRelative, true),
		HolsterSocket);
}

void ACRifle::End_Unequip()
{
	bEquipping = false;
}

void ACRifle::Begin_Aiming()
{
	bAiming = true;
}

void ACRifle::End_Aiming()
{
	bAiming = false;
}
