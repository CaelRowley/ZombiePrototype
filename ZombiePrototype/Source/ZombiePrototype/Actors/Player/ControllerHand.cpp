// Fill out your copyright notice in the Description page of Project Settings.


#include "ControllerHand.h"

// Sets default values
AControllerHand::AControllerHand()
{

}

void AControllerHand::PairControllers(AControllerBase* Controller)
{
	OtherController = Cast<AControllerHand>(Controller);
	OtherController->OtherController = this;
}


// Axis mappings
void AControllerHand::LeftThumbstickX(float axisValue, APawn* pawn, FVector direction)
{
	Super::LeftThumbstickX(axisValue, pawn, direction);
	pawn->AddMovementInput(axisValue * direction);
}

void AControllerHand::LeftThumbstickY(float axisValue, APawn* pawn, FVector direction)
{
	Super::LeftThumbstickY(axisValue, pawn, direction);
	pawn->AddMovementInput(axisValue * direction);
}
