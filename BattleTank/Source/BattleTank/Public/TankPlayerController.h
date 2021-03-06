// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#define OUT
#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"


/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATank* GetControlledTank() const;
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	//start the tank moving the barrel so that a shot would hit where
	//the crosshair intersects the world
	void AimTowardsCrosshair();

private:
	//return an out parameter,true if hit landscape
	bool GetSightRayHitLoaction(OUT FVector& HitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	
};
