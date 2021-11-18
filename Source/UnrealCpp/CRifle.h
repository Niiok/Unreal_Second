// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CRifle.generated.h"

UCLASS()
class UNREALCPP_API ACRifle : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleDefaultsOnly, Category = "Rifel")
		class USkeletalMeshComponent* Mesh;
	
	UPROPERTY(VisibleDefaultsOnly, Category = "Rifel")
		FName HandSocket = "Hand_Rifle";
	
	UPROPERTY(VisibleDefaultsOnly, Category = "Rifel")
		FName HolsterSocket = "Holster_Rifle";

	UPROPERTY(VisibleDefaultsOnly, Category = "Rifel")
		class UAnimMontage* GrabMontage;

	UPROPERTY(VisibleDefaultsOnly, Category = "Rifel")
		class UAnimMontage* UngrabMontage;

	class ACharacter* OwnerCharacter;

	bool bEquipped;
	bool bEquipping;
	bool bAiming;


public :
	static ACRifle* Spawn(class UWorld* InWorld, class	ACharacter* InOwner);



public:	
	// Sets default values for this actor's properties
	ACRifle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



public:
	FORCEINLINE bool GetEquipped() { return bEquipped; }
	FORCEINLINE bool GetEquipping() { return bEquipping; }
	FORCEINLINE bool GetAiming() { return bAiming; }

	void Equip();
	void Begin_Equip();
	void End_Equip();
	
	void Unequip();
	void Begin_Unequip();
	void End_Unequip();

	void Begin_Aiming();
	void End_Aiming();

};
