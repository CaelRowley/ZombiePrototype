// Fill out your copyright notice in the Description page of Project Settings.

#include "ControllerHand.h"

// Sets default values
AControllerHand::AControllerHand()
{
	MotionController->SetShowDeviceModel(false);
}

void AControllerHand::PairControllers(AControllerBase* Controller)
{
	OtherController = Cast<AControllerHand>(Controller);
	OtherController->OtherController = this;
}

void AControllerHand::Initialize()
{
	//SkeletalMesh = Cast<USkeletalMesh>(GetWorld()->GetDefaultSubobjectByName("SkeletalMesh"));
	FName MotionSource = MotionController->MotionSource;

	if (MotionSource == FName("Left")) {
		MotionController->SetRelativeScale3D(FVector(1.0, -1.0, 1.0));
		UE_LOG(LogTemp, Warning, TEXT("SetRelativeScale3D=========LEFT"));
	}

	if (MotionSource == FName("Right")) {
		MotionController->SetRelativeScale3D(FVector(1.0, 1.0, 1.0));
		UE_LOG(LogTemp, Warning, TEXT("SetRelativeScale3D=========RIGHT"));
	}

	UE_LOG(LogTemp, Warning, TEXT("MotionSource=========(%s)"), *FString(MotionController->MotionSource.ToString()));
	//UE_LOG(LogTemp, Warning, TEXT("SkeletalMesh=========(%s)"), *FString(SkeletalMesh->GetFName().ToString()));
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
