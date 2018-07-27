// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 *
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	ATank* GetControlledTank() const;

	// Begin moving the barrel so that a shot will hit where the crosshair intersects the world
	void AimTowardCrosshair();

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
};
