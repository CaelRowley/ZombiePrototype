// Fill out your copyright notice in the Description page of Project Settings.


#include "ControllerHand.h"

// Sets default values
AControllerHand::AControllerHand()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = false;

	//MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionController"));
	MotionController->SetShowDeviceModel(false);
	//SetRootComponent(MotionController);
}

void AControllerHand::PairControllers(AControllerBase* Controller)
{
	OtherController = Cast<AControllerHand>(Controller);
	OtherController->OtherController = this;
}

// Action mappings
void AControllerHand::TriggerLeftPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("TriggerLeftPressed()"));
}

void AControllerHand::TriggerLeftReleased()
{
	UE_LOG(LogTemp, Warning, TEXT("TriggerLeftReleased()"));
}

void AControllerHand::TriggerRightPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("TriggerRightPressed()"));
}

void AControllerHand::TriggerRightReleased()
{
	UE_LOG(LogTemp, Warning, TEXT("TriggerRightReleased()"));
}

void AControllerHand::GrabLeftPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("GrabLeftPressed()"));
}

void AControllerHand::GrabLeftReleased()
{
	UE_LOG(LogTemp, Warning, TEXT("GrabLeftReleased()"));
}

void AControllerHand::GrabRightPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("GrabRightPressed()"));
}

void AControllerHand::GrabRightReleased()
{
	UE_LOG(LogTemp, Warning, TEXT("GrabRightReleased()"));
}

// Axis mappings

void AControllerHand::LeftThumbstickX(float throttle, APawn* pawn, UCameraComponent* Camera)
{
	if (throttle != 0) {
		UE_LOG(LogTemp, Warning, TEXT("MoveRight: %f"), throttle);
	}
	pawn->AddMovementInput(throttle * Camera->GetRightVector());
}

void AControllerHand::LeftThumbstickY(float throttle, APawn* pawn, UCameraComponent* Camera)
{
	if (throttle != 0) {
		UE_LOG(LogTemp, Warning, TEXT("MoveForward: %f"), throttle);
	}
	pawn->AddMovementInput(throttle * Camera->GetForwardVector());
}

void AControllerHand::RightThumbstickX(float throttle, APawn* pawn, UCameraComponent* Camera)
{
	if (throttle != 0) {
		UE_LOG(LogTemp, Warning, TEXT("MoveRight: %f"), throttle);
	}
	pawn->AddMovementInput(throttle * Camera->GetRightVector());
}

void AControllerHand::RightThumbstickY(float throttle, APawn* pawn, UCameraComponent* Camera)
{
	if (throttle != 0) {
		UE_LOG(LogTemp, Warning, TEXT("MoveForward: %f"), throttle);
	}
	pawn->AddMovementInput(throttle * Camera->GetForwardVector());
}

void AControllerHand::SqueezeLeft(float throttle)
{
	UE_LOG(LogTemp, Warning, TEXT("SqueezeLeft(%f)"), throttle);
}

void AControllerHand::SqueezeRight(float throttle)
{
	if (throttle != 0) {
		UE_LOG(LogTemp, Warning, TEXT("SqueezeRight(%f)"), throttle);
	}
}
