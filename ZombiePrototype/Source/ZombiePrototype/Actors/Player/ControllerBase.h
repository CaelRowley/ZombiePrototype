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
	virtual void TriggerLeftPressed();
	virtual void TriggerLeftReleased();
	virtual void TriggerRightPressed();
	virtual void TriggerRightReleased();
	virtual void GrabLeftPressed();
	virtual void GrabLeftReleased();
	virtual void GrabRightPressed();
	virtual void GrabRightReleased();
	virtual void TrackpadLeftPressed();
	virtual void TrackpadLeftReleased();
	virtual void TrackpadRightPressed();
	virtual void TrackpadRightReleased();

	// Axis mappings
	virtual void LeftThumbstickX(float axisValue, APawn* pawn, FVector direction);
	virtual void LeftThumbstickY(float axisValue, APawn* pawn, FVector direction);
	virtual void RightThumbstickX(float axisValue, APawn* pawn, FVector direction);
	virtual void RightThumbstickY(float axisValue, APawn* pawn, FVector direction);
	virtual void SqueezeLeft(float axisValue);
	virtual void SqueezeRight(float axisValue);
	virtual void TriggerLeftAxis(float axisValue);
	virtual void TriggerRightAxis(float axisValue);
};
