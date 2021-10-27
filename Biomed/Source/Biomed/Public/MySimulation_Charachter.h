// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MySimulation_Charachter.generated.h"

UCLASS()
class BIOMED_API AMySimulation_Charachter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMySimulation_Charachter();

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void Shoot();

public:	

	
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
