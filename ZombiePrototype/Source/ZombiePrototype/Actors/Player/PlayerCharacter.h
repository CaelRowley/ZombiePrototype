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
	inline void TriggerLeftReleased() { RightController->TriggerLeftReleased(); }
	inline void TriggerRightPressed() { LeftController->TriggerRightPressed(); }
	inline void TriggerRightReleased() { RightController->TriggerRightReleased(); }
	inline void GrabLeftPressed() { LeftController->GrabLeftPressed(); }
	inline void GrabLeftReleased() { RightController->GrabLeftReleased(); }
	inline void GrabRightPressed() { LeftController->GrabRightPressed(); }
	inline void GrabRightReleased() { RightController->GrabRightReleased(); }

	// Axis mappings
	inline void LeftThumbstickX(float throttle) { LeftController->LeftThumbstickX(throttle, this, Camera); }
	inline void LeftThumbstickY(float throttle) { LeftController->LeftThumbstickY(throttle, this, Camera); }
	inline void RightThumbstickX(float throttle) { LeftController->RightThumbstickX(throttle, this, Camera); }
	inline void RightThumbstickY(float throttle) { LeftController->RightThumbstickY(throttle, this, Camera); }
	inline void SqueezeLeft(float throttle) { LeftController->SqueezeLeft(throttle); }
	inline void SqueezeRight(float throttle) { LeftController->SqueezeRight(throttle); }

};
