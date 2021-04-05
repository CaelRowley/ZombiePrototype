// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MotionControllerComponent.h"
#include "Camera/CameraComponent.h"

#include "ControllerBase.generated.h"

UCLASS()
class ZOMBIEPROTOTYPE_API AControllerBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AControllerBase();

public:
	UPROPERTY(VisibleAnywhere)
	class UMotionControllerComponent* MotionController;

	inline void SetMotionSource(FName MotionSource) { MotionController->SetTrackingMotionSource(MotionSource); }
	virtual void PairControllers(AControllerBase* ControllerBase) { }


	// Action mappings
	virtual void TriggerLeftPressed() { }
	virtual void TriggerLeftReleased() { }
	virtual void TriggerRightPressed() { }
	virtual void TriggerRightReleased() { }
	virtual void GrabLeftPressed() { }
	virtual void GrabLeftReleased() { }
	virtual void GrabRightPressed() { }
	virtual void GrabRightReleased() { }

	// Axis mappings
	virtual void LeftThumbstickX(float throttle, APawn* pawn, UCameraComponent* Camera) { }
	virtual void LeftThumbstickY(float throttle, APawn* pawn, UCameraComponent* Camera) { }
	virtual void RightThumbstickX(float throttle, APawn* pawn, UCameraComponent* Camera) { }
	virtual void RightThumbstickY(float throttle, APawn* pawn, UCameraComponent* Camera) { }
	virtual void SqueezeLeft(float throttle) { }
	virtual void SqueezeRight(float throttle) { }
};
