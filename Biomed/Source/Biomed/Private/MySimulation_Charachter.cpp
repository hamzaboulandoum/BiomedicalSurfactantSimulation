// Fill out your copyright notice in the Description page of Project Settings.


#include "MySurfactant.h"
#include "MySimulation_Charachter.h"

// Sets default values
AMySimulation_Charachter::AMySimulation_Charachter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}


// Called when the game starts or when spawned

void AMySimulation_Charachter::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("hola nino"));
}

void AMySimulation_Charachter::Shoot()
{// nice

}

// Called every frame
void AMySimulation_Charachter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMySimulation_Charachter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Shoot", IE_Pressed,this,&AMySimulation_Charachter::Shoot);

}

