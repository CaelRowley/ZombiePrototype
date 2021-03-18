// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "Components/SplineComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VRRoot = CreateDefaultSubobject<USceneComponent>(TEXT("VRRoot"));
	VRRoot->SetupAttachment(GetRootComponent());

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(VRRoot);
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	FVector NewCameraOffset = Camera->GetComponentLocation();
	NewCameraOffset.X = 0;
	NewCameraOffset.Y = 0;
	NewCameraOffset.Z = -GetCapsuleComponent()->GetScaledCapsuleHalfHeight();
	VRRoot->AddWorldOffset(NewCameraOffset);

	LeftController = GetWorld()->SpawnActor<AControllerBase>(ControllerBase);
	if (LeftController != nullptr)
	{
		LeftController->AttachToComponent(VRRoot, FAttachmentTransformRules::KeepRelativeTransform);
		LeftController->SetMotionSource(FName("Left"));
		LeftController->SetOwner(this);
	}

	RightController = GetWorld()->SpawnActor<AControllerBase>(ControllerBase);
	if (RightController != nullptr)
	{
		RightController->AttachToComponent(VRRoot, FAttachmentTransformRules::KeepRelativeTransform);
		RightController->SetMotionSource(FName("Right"));
		RightController->SetOwner(this);
	}
	
	LeftController->PairControllers(RightController);
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewCameraOffset = Camera->GetComponentLocation() - GetActorLocation();
	NewCameraOffset.Z = 0;
	AddActorWorldOffset(NewCameraOffset);
	VRRoot->AddWorldOffset(-NewCameraOffset);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Forward"), this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("Right"), this, &APlayerCharacter::MoveRight);

	PlayerInputComponent->BindAxis(TEXT("ThumbstickX"), this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("ThumbstickY"), this, &APlayerCharacter::MoveForward);

}

void APlayerCharacter::MoveForward(float throttle)
{
	if (throttle > 0) {
		UE_LOG(LogTemp, Warning, TEXT("MoveForward: %f"), throttle);
	}
	AddMovementInput(throttle * Camera->GetForwardVector());
}

void APlayerCharacter::MoveRight(float throttle)
{
	if (throttle > 0) {
		UE_LOG(LogTemp, Warning, TEXT("MoveRight: %f"), throttle);
	}
	AddMovementInput(throttle * Camera->GetRightVector());
}

