// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Character.h"

#include "ControllerBase.h"

#include "PlayerCharacter.generated.h"

UCLASS()
class ZOMBIEPROTOTYPE_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* Camera;
	UPROPERTY(VisibleAnywhere)
	class USceneComponent* VRRoot;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AControllerBase> ControllerBase;

	UPROPERTY(VisibleAnywhere)
	AControllerBase* LeftController;
	UPROPERTY(VisibleAnywhere)
	AControllerBase* RightController;
	
	// Action mappings
	inline void TriggerLeftPressed() { LeftController->TriggerLeftPressed(); }
	inline void TriggerLeftReleased() { LeftController->TriggerLeftReleased(); }

	inline void TriggerRightPressed() { RightController->TriggerRightPressed(); }
	inline void TriggerRightReleased() { RightController->TriggerRightReleased(); }

	inline void GrabLeftPressed() { LeftController->GrabLeftPressed(); }
	inline void GrabLeftReleased() { LeftController->GrabLeftReleased(); }

	inline void GrabRightPressed() { RightController->GrabRightPressed(); }
	inline void GrabRightReleased() { RightController->GrabRightReleased(); }

	inline void TrackpadLeftPressed() { LeftController->TrackpadLeftPressed(); }
	inline void TrackpadLeftReleased() { LeftController->TrackpadLeftReleased(); }

	inline void TrackpadRightPressed() { RightController->TrackpadRightPressed(); }
	inline void TrackpadRightReleased() { RightController->TrackpadRightReleased(); }

	// Axis mappings
	inline void LeftThumbstickX(float throttle) { LeftController->LeftThumbstickX(throttle, this, Camera->GetRightVector()); }
	inline void LeftThumbstickY(float throttle) { LeftController->LeftThumbstickY(throttle, this, Camera->GetForwardVector()); }

	inline void RightThumbstickX(float throttle) { RightController->RightThumbstickX(throttle, this, Camera->GetRightVector()); }
	inline void RightThumbstickY(float throttle) { RightController->RightThumbstickY(throttle, this, Camera->GetForwardVector()); }

	inline void SqueezeLeft(float throttle) { LeftController->SqueezeLeft(throttle); }
	inline void SqueezeRight(float throttle) { RightController->SqueezeRight(throttle); }

	inline void TriggerLeftAxis(float throttle) { RightController->TriggerLeftAxis(throttle); }
	inline void TriggerRightAxis(float throttle) { RightController->TriggerRightAxis(throttle); }
};
