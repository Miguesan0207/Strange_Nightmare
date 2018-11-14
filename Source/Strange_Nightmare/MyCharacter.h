// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class STRANGE_NIGHTMARE_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()
private:
	void MoveForward(float value);
	void MoveRight(float value);
	void RotateYaw(float value); //Rotar quijada, izq, der
	void RotatePitch(float value); //rotar vertical
	void StartJump();
	void StopJump(); //jumping ya existe
	void StartSprint();
	void StopSprint();

	bool bIsSprinting = false;

public:
	UPROPERTY(EditAnywhere) float rotationSpeed = 45;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



};
