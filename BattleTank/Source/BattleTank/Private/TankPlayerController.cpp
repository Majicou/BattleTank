// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"));
	}
	if (GetPawn())
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessed tank: %s"), *ControlledTank->GetName());
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardCrosshair()
{
	if (!GetControlledTank())
	{
		return;
	}

	FVector OutHitLocation; // Out parameter
	if (GetSightRayHitLocation(OutHitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *OutHitLocation.ToString());
		// Get world location of a linetrace through crosshair
				
			// Tell controlled tank to aim at this point
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	FHitResult HitResult;
	OutHitLocation = FVector(1.0f);
	// Linetrace from end of barrel to (infinity?) 
	//ActorLineTraceSingle(HitResult, )
	// Return true if hit landscape
	return true;
}
