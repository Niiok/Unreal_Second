// Fill out your copyright notice in the Description page of Project Settings.


#include "CRifle.h"
#include "Global.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Character.h"
#include "CPlayer.h"
#include "Animation/AnimMontage.h"
#include "Engine/StaticMeshActor.h"
#include "Particles/ParticleSystem.h"
#include "Sound/SoundCue.h"
#include "CBullet.h"


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
	CHelpers::GetAsset<UAnimMontage>(&FireMontage,
		"AnimMontage'/Game/Character/Montages/Rifle_Fire_Montage.Rifle_Fire_Montage'");
	/*CHelpers::GetAsset<UParticleSystem>(&FlashParticle,
		"");*/
	/*CHelpers::GetAsset<UParticleSystem>(&EjectParticle,
		"");*/
	/*CHelpers::GetAsset<USoundCue>(&FireSoundCue,
		"");*/
		
	CHelpers::GetClass<ACBullet>(&BulletClass, "Blueprint'/Game/BP_CBullet.BP_CBullet_C'");
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

	CheckFalse(bAiming);

	IiRifle* rifle = Cast<IiRifle>(OwnerCharacter);
	CheckNull(rifle);

	FVector start, end, direction;

	rifle->GetLocationAndDirection(start, end, direction);

	//DrawDebugLine(GetWorld(), start, end, FColor::Green, false, 3.0f);

	FCollisionQueryParams params;
	params.AddIgnoredActor(this);
	params.AddIgnoredActor(OwnerCharacter);

	FHitResult hitResult;
	if (GetWorld()->LineTraceSingleByChannel(hitResult, start, end,
		ECollisionChannel::ECC_WorldDynamic, params))
	{
		AStaticMeshActor* staticMeshActor = Cast<AStaticMeshActor>(
			hitResult.GetActor());
		if (!!staticMeshActor)
		{
			UStaticMeshComponent* meshComponent = Cast<UStaticMeshComponent>(
				staticMeshActor->GetRootComponent());
			if (!!meshComponent && meshComponent->BodyInstance.bSimulatePhysics)
			{
				// hit affection
				rifle->OnFocus();
				return;
			}
		}
	}

	rifle->OffFocus();
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

void ACRifle::Begin_Fire()
{
	CheckFalse(bEquipped);
	CheckTrue(bEquipping);
	CheckFalse(bAiming);
	CheckTrue(bFiring);

	Firing();
}

void ACRifle::Firing()
{
	IiRifle* rifle = Cast<IiRifle>(OwnerCharacter);
	CheckNull(rifle);

	FVector start, end, direction;
	rifle->GetLocationAndDirection(start, end, direction);

	OwnerCharacter->PlayAnimMontage(FireMontage);
	ACPlayer* player = Cast<ACPlayer>(OwnerCharacter);
	if (!!player)
	{
		player->PlayCameraShake();
	}

	/*UGameplayStatics::SpawnEmitterAttached(FlashParticle, Mesh, "MuzzleFlash", 
		FVector::ZeroVector, FRotator::ZeroRotator, EAttachLocation::KeepRelativeOffset);*/
		
	/*UGameplayStatics::SpawnEmitterAttached(EjectParticle, Mesh, "EjectBullet", 
		FVector::ZeroVector, FRotator::ZeroRotator, EAttachLocation::KeepRelativeOffset);*/
		
	FVector muzzleLocation = Mesh->GetSocketLocation("MuzzleFlash");
	/*UGameplayStatics::SpawnSoundAtLocation(GetWorld(), FireSoundCue, muzzleLocation);*/

	if (!!BulletClass)
		GetWorld()->SpawnActor<ACBullet>(BulletClass, muzzleLocation, direction.Rotation());

	FCollisionQueryParams params;
	params.AddIgnoredActor(this);
	params.AddIgnoredActor(OwnerCharacter);

	FHitResult hitResult;
	if (GetWorld()->LineTraceSingleByChannel(hitResult, start, end,
		ECollisionChannel::ECC_WorldDynamic, params))
	{
		AStaticMeshActor* staticMeshActor = Cast<AStaticMeshActor>(
			hitResult.GetActor());
		if (!!staticMeshActor)
		{
			UStaticMeshComponent* meshComponent = Cast<UStaticMeshComponent>(
				staticMeshActor->GetRootComponent());
			if (!!meshComponent && meshComponent->BodyInstance.bSimulatePhysics)
			{
				// hit affection
				direction = staticMeshActor->GetActorLocation() -
					OwnerCharacter->GetActorLocation();
				direction.Normalize();
				meshComponent->AddImpulseAtLocation(direction *
					meshComponent->GetMass() * 100,
					OwnerCharacter->GetActorLocation());

				return;
			}
		}
	}
}

void ACRifle::End_Fire()
{
}
