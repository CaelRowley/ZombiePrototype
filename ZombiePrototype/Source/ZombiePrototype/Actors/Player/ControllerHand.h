// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ControllerBase.h"
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

	void LeftThumbstickX(float throttle) override;
	void LeftThumbstickY() override;
	void RightThumbstickX() override;
	void RightThumbstickY() override;
	void LeftTriggerPressed() override;

	AControllerHand* OtherController;
};
