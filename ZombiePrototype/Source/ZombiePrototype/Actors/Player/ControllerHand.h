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
	void PairControllers(AControllerBase* Controller) override;

	void LeftThumbstickX(float throttle, APawn* pawn, UCameraComponent* Camera) override;
	void LeftThumbstickY(float throttle, APawn* pawn, UCameraComponent* Camera) override;

	void LeftTriggerPressed() override;
	void RightTriggerPressed() override;

	AControllerHand* OtherController;
};
