// Fill out your copyright notice in the Description page of Project Settings.


#include "ControllerBase.h"

// Sets default values
AControllerBase::AControllerBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionController"));
	MotionController->SetShowDeviceModel(true);
	SetRootComponent(MotionController);
}

// Action mappings
void AControllerBase::TriggerLeftPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("TriggerLeftPressed()"));
}

void AControllerBase::TriggerLeftReleased()
{
	UE_LOG(LogTemp, Warning, TEXT("TriggerLeftReleased()"));
}

void AControllerBase::TriggerRightPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("TriggerRightPressed()"));
}

void AControllerBase::TriggerRightReleased()
{
	UE_LOG(LogTemp, Warning, TEXT("TriggerRightReleased()"));
}

void AControllerBase::GrabLeftPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("GrabLeftPressed()"));
}

void AControllerBase::GrabLeftReleased()
{
	UE_LOG(LogTemp, Warning, TEXT("GrabLeftReleased()"));
}

void AControllerBase::GrabRightPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("GrabRightPressed()"));
}

void AControllerBase::GrabRightReleased()
{
	UE_LOG(LogTemp, Warning, TEXT("GrabRightReleased()"));
}

void AControllerBase::TrackpadLeftPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("TrackpadLeftPressed()"));
}

void AControllerBase::TrackpadLeftReleased()
{
	UE_LOG(LogTemp, Warning, TEXT("TrackpadLeftReleased()"));
}

void AControllerBase::TrackpadRightPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("TrackpadRightPressed()"));
}

void AControllerBase::TrackpadRightReleased()
{
	UE_LOG(LogTemp, Warning, TEXT("TrackpadRightReleased()"));
}

// Axis mappings
void AControllerBase::LeftThumbstickX(float axisValue, APawn* pawn, FVector direction)
{
	if (axisValue > 0.1 || axisValue < -0.1) {
		UE_LOG(LogTemp, Warning, TEXT("LeftThumbstickX(%f, %s, %s)"), axisValue, *FString(pawn->GetName()), *FString(direction.ToString()));
	}
}

void AControllerBase::LeftThumbstickY(float axisValue, APawn* pawn, FVector direction)
{
	if (axisValue > 0.1 || axisValue < -0.1) {
		UE_LOG(LogTemp, Warning, TEXT("LeftThumbstickY(%f, %s, %s)"), axisValue, *FString(pawn->GetName()), *FString(direction.ToString()));
	}
}

void AControllerBase::RightThumbstickX(float axisValue, APawn* pawn, FVector direction)
{
	if (axisValue > 0.1 || axisValue < -0.1) {
		UE_LOG(LogTemp, Warning, TEXT("RightThumbstickX(%f, %s, %s)"), axisValue, *FString(pawn->GetName()), *FString(direction.ToString()));
	}
}

void AControllerBase::RightThumbstickY(float axisValue, APawn* pawn, FVector direction)
{
	if (axisValue > 0.1 || axisValue < -0.1) {
		UE_LOG(LogTemp, Warning, TEXT("RightThumbstickY(%f, %s, %s)"), axisValue, *FString(pawn->GetName()), *FString(direction.ToString()));
	}
}

void AControllerBase::SqueezeLeft(float axisValue)
{
	if (axisValue > 0.1 || axisValue < -0.1) {
		UE_LOG(LogTemp, Warning, TEXT("SqueezeLeft(%f)"), axisValue);
	}
}

void AControllerBase::SqueezeRight(float axisValue)
{
	if (axisValue > 0.1 || axisValue < -0.1) {
		UE_LOG(LogTemp, Warning, TEXT("SqueezeRight(%f)"), axisValue);
	}
}

void AControllerBase::TriggerLeftAxis(float axisValue)
{
	if (axisValue > 0.1 || axisValue < -0.1) {
		UE_LOG(LogTemp, Warning, TEXT("TriggerLeftAxis(%f)"), axisValue);
	}
}

void AControllerBase::TriggerRightAxis(float axisValue)
{
	if (axisValue > 0.1 || axisValue < -0.1) {
		UE_LOG(LogTemp, Warning, TEXT("TriggerRightAxis(%f)"), axisValue);
	}
}
