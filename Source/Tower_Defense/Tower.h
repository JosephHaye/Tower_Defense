// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tower.generated.h"

class USceneComponent;
class UCapsuleComponent;

UCLASS()
class TOWER_DEFENSE_API ATower : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATower();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		USceneComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UStaticMeshComponent* Turret;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UCapsuleComponent* TriggerComponent;

	void RotateTurretFunction(FVector LookAtTarget);

	bool GetGenerateOverlapEvents() const;
};
