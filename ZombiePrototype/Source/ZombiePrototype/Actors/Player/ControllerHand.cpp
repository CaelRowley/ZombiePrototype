// Fill out your copyright notice in the Description page of Project Settings.


#include "ControllerHand.h"

void AControllerHand::PairControllers(AControllerBase* Controller)
{
	OtherController = Cast<AControllerHand>(Controller);
	OtherController->OtherController = this;
}

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

void AControllerHand::LeftTriggerPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("Left trigger Pressed"));
}

void AControllerHand::RightTriggerPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("Right trigger Pressed"));
}
