// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Turret.h"
#include <Components/SceneComponent.h>
#include <Components/CapsuleComponent.h>
#include <Components/BoxComponent.h>
#include <Components/PrimitiveComponent.h>

// Sets default values
ATower::ATower()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<USceneComponent>(TEXT("Capsule Collision"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(RootComponent);

	Turret = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret"));
	Turret->SetupAttachment(BaseMesh);

	TriggerComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Range"));
	TriggerComponent->InitCapsuleSize(55.f, 96.f);
	TriggerComponent->SetCollisionProfileName(TEXT("Trigger"));
	TriggerComponent->SetupAttachment(RootComponent);

	//TriggerComponent->OnComponentBeginOverlap.AddDynamic(this, &ATurret::OnOverlapBegin);
	//TriggerComponent->OnComponentEndOverlap.AddDynamic(this, &ATurret::OnOverlapEnd);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(Turret);

}

void ATower::RotateTurretFunction(FVector LookAtTarget)
{

	FVector LookAtTargetClean = FVector(LookAtTarget.X, LookAtTarget.Y, Turret->GetComponentLocation().Z);
	FVector StartLocation = Turret->GetComponentLocation();

	FRotator TurretRotation = FVector(LookAtTargetClean - StartLocation).Rotation();
	Turret->SetWorldRotation(TurretRotation);

}

bool ATower::GetGenerateOverlapEvents() const
{
	return true;
}

