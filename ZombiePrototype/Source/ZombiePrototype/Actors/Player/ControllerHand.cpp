// Fill out your copyright notice in the Description page of Project Settings.


#include "ControllerHand.h"

void AControllerHand::PairControllers(AControllerBase* Controller)
{
	OtherController = Cast<AControllerHand>(Controller);
	OtherController->OtherController = this;
}

void AControllerHand::LeftThumbstickX(float throttle)
{
	UE_LOG(LogTemp, Warning, TEXT("throttle: %f"), throttle);
}

void AControllerHand::LeftThumbstickY()
{
	UE_LOG(LogTemp, Warning, TEXT("LeftThumbstickX"));
}

void AControllerHand::RightThumbstickX()
{
}

void AControllerHand::RightThumbstickY()
{
}

void AControllerHand::LeftTriggerPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("LeftTriggerPressed"));
}
