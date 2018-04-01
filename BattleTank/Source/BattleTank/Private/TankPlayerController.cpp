// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "BattleTank.h"



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	//check to see if controller is posseng  a tank
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController is not possesing tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController is possessing %s"), *ControlledTank->GetName());
	}
	UE_LOG(LogTemp,Warning,TEXT(""))
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();

}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation;//out parameter
	if (GetSightRayHitLoaction(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLoaction: %s"), *HitLocation.ToString());
		 
		// TODO tell controlled tank to aim at this point
	}
			
}

//get world location of line trace through crosshair,true if hits landscape
bool ATankPlayerController::GetSightRayHitLoaction(OUT FVector & HitLocation) const
{
	HitLocation = FVector(1.0f);
	return true;
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());//return pointer to ATank
	
}




