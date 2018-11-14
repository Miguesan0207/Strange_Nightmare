// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/World.h"
#include "Engine.h"


// Sets default values

void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &AMyCharacter::RotateYaw);
	PlayerInputComponent->BindAxis("LookUp", this, &AMyCharacter::RotatePitch);
	PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &AMyCharacter::StartJump);
	PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Released, this, &AMyCharacter::StopJump);
	PlayerInputComponent->BindAction("Sprint", EInputEvent::IE_Pressed, this, &AMyCharacter::StartSprint);
	PlayerInputComponent->BindAction("Sprint", EInputEvent::IE_Released, this, &AMyCharacter::StopSprint);

}

void AMyCharacter::MoveForward(float value)
{
	if (bIsSprinting)
	{
		value *= 2;
	}
	AddMovementInput(GetActorForwardVector(), value / 2);
}
void AMyCharacter::MoveRight(float value)
{
	if (bIsSprinting)
	{
		value *= 2;
	}
	AddMovementInput(GetActorRightVector(), value / 2);
}
void AMyCharacter::RotateYaw(float value)
{
	AddControllerYawInput(value * rotationSpeed * GetWorld()->GetDeltaSeconds());

}
void AMyCharacter::RotatePitch(float value)
{
	AddControllerPitchInput(value * rotationSpeed * GetWorld()->GetDeltaSeconds());
}

void AMyCharacter::StartJump()
{
	Jump();
}

void AMyCharacter::StopJump()
{
	StopJumping();
}

void AMyCharacter::StartSprint()
{
	bIsSprinting = true;
}

void AMyCharacter::StopSprint()
{
	bIsSprinting = false;
}



