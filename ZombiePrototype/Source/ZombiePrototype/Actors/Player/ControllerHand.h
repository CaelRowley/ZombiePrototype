// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ControllerBase.h"
#include "Camera/CameraComponent.h"

#include "ControllerHand.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIEPROTOTYPE_API AControllerHand : public AControllerBase
{
	GENERATED_BODY()
	
public:
	AControllerHand();

	void PairControllers(AControllerBase* Controller) override;

	// Axis mappings
	void LeftThumbstickX(float axisValue, APawn* pawn, FVector direction) override;
	void LeftThumbstickY(float axisValue, APawn* pawn, FVector direction) override;

	AControllerHand* OtherController;

private:
	bool bIsRightGripping = false;
};
