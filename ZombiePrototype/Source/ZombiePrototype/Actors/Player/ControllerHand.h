// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ControllerBase.h"
#include "Camera/CameraComponent.h"
//#include "Engine/SkeletalMesh.h"

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

	//Class USkeletalMesh* SkeletalMesh;

	void PairControllers(AControllerBase* Controller) override;
	void Initialize() override;

	// Action mappings
	virtual void TriggerLeftPressed() override;
	virtual void TriggerLeftReleased() override;
	virtual void TriggerRightPressed() override;
	virtual void TriggerRightReleased() override;
	virtual void GrabLeftPressed() override;
	virtual void GrabLeftReleased() override;
	virtual void GrabRightPressed() override;
	virtual void GrabRightReleased() override;

	// Axis mappings
	void LeftThumbstickX(float throttle, APawn* pawn, UCameraComponent* Camera) override;
	void LeftThumbstickY(float throttle, APawn* pawn, UCameraComponent* Camera) override;
	void RightThumbstickX(float throttle, APawn* pawn, UCameraComponent* Camera) override;
	void RightThumbstickY(float throttle, APawn* pawn, UCameraComponent* Camera) override;
	void SqueezeLeft(float throttle) override;
	void SqueezeRight(float throttle) override;

	AControllerHand* OtherController;

private:
	bool bIsRightGripping = false;
};
