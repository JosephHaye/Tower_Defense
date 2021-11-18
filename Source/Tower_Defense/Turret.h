// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Components/PrimitiveComponent.h>
#include "CoreMinimal.h"
#include "Tower.h"
#include "Turret.generated.h"


class AEnemyCharacter;

UCLASS()
class TOWER_DEFENSE_API ATurret : public ATower
{
	GENERATED_BODY()

public:

	ATurret();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndext);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat");
	float FireRate = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat");
	float FireRange = 50000.0f;

private:

	FTimerHandle FireRateTimerHandle;

	AEnemyCharacter* Enemy;

	float ReturnDistanceToEnemy();

};
