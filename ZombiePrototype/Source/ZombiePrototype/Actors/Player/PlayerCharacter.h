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
	UPROPERTY(VisibleAnywhere)
	class USplineComponent* TeleportPath;
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* DestinationMarker;

	UPROPERTY()
	class UPostProcessComponent* PostProcessComponent;
	UPROPERTY()
	AControllerBase* LeftController;
	UPROPERTY()
	AControllerBase* RightController;
	UPROPERTY()
	class UMaterialInstanceDynamic* BlinkerMaterialInstance;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AControllerBase> ControllerBase;
	UPROPERTY(EditAnywhere)
	class UMaterialInterface* BlinkerMaterialBase;

	void MoveForward(float throttle);
	void MoveRight(float throttle);

};
