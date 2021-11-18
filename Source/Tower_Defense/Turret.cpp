// Fill out your copyright notice in the Description page of Project Settings.


#include "Turret.h"
#include <Kismet/GameplayStatics.h>
#include "AIController.h"
#include "EnemyCharacter.h"

ATurret::ATurret()
{

}

// Called every frame
void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!Enemy|| ReturnDistanceToEnemy() > FireRange)
	{
		return;
	}

	RotateTurretFunction(Enemy->GetActorLocation());
}


void ATurret::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("In Range"));
		}
	}
}

void ATurret::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndext)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("Out of Range"));
	}
}

float ATurret::ReturnDistanceToEnemy()
{
	if (!Enemy)
	{
		return 0.0f;
	}

	float Distance = FVector::Dist(Enemy->GetActorLocation(), GetActorLocation());
	return Distance;
}

// Called when the game starts or when spawned
void ATurret::BeginPlay()
{
	Super::BeginPlay();

	Enemy = Cast<AEnemyCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
}