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

	virtual void LeftThumbstickX(float throttle, APawn* pawn, UCameraComponent* Camera) { }
	virtual void LeftThumbstickY(float throttle, APawn* pawn, UCameraComponent* Camera) { }
	
	virtual void LeftTriggerPressed() { }
	virtual void RightTriggerPressed() { }
};
