// Fill out your copyright notice in the Description page of Project Settings.


#include "MySurfactant.h"
#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"
#include "Engine/EngineTypes.h"
#include "Components/PrimitiveComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

//adding some varibales
FRandomStream randomStream;
FTimerDelegate TimerDel;
FTimerHandle TimerHandle;
// Sets default values

AMySurfactant::AMySurfactant()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Creating a mesh subobject
	SurfactantMesh = CreateDefaultSubobject<UStaticMeshComponent>("Sphere Mesh");
	SetRootComponent(SurfactantMesh);
}

// Called when the game starts or when spawned
void AMySurfactant::BeginPlay()
{
	Super::BeginPlay();
	GoToRandomPosition();
	
}


void AMySurfactant::GoToRandomPosition() {
	//Starting By Setting All the speeds to zero 
	SetSpeedToZero();
	//start chosing random positoin
	auto random = randomStream.RandRange(1, 4);
	
	if (random == 1) {
		Speed.X = SpeedMaximum;
		//UE_LOG(LogTemp, Warning, TEXT("%s"),*Speed.ToString());

		SurfactantMesh->SetPhysicsLinearVelocity(Speed); // that works because i actually use the functions realted to the surfactant Mesh from now on
	}
	else if (random == 2)
	{
		Speed.X = -SpeedMaximum;
		//UE_LOG(LogTemp, Warning, TEXT("%s"), *Speed.ToString());
		SurfactantMesh->SetPhysicsLinearVelocity(Speed);
	}
	else if (random == 3)
	{
		Speed.Y = SpeedMaximum;
		//UE_LOG(LogTemp, Warning, TEXT("%s"), *Speed.ToString());
		SurfactantMesh->SetPhysicsLinearVelocity(Speed);
	}
	else if (random == 4) {
		Speed.Y = -SpeedMaximum;
		//UE_LOG(LogTemp, Warning, TEXT("%s"), *Speed.ToString());
		SurfactantMesh->SetPhysicsLinearVelocity(Speed);
	}

	//This is a delay that waits for Delay then triggers the goToRandomPositionFunctionAgain
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AMySurfactant::GoToRandomPosition, Delay, false);

}


void AMySurfactant::ClearAll()
{
	//this clears the timer and sets the speed to zero
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
	SetSpeedToZero();
}

void AMySurfactant::SetSpeedToZero()
{
	//We Set the SpeedToZero
	Speed.X = 0;
	Speed.Y = 0;
	SurfactantMesh->SetPhysicsLinearVelocity(Speed);
	SurfactantMesh->SetPhysicsAngularVelocity(Speed	);

}

void AMySurfactant::SurfactantMovementHandle()
{
	GoToRandomPosition();
}


// Called every frame
void AMySurfactant::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


//What this does is that it clears all the timers
void AMySurfactant::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
	//We do clear all timers before we quit
}

// tomorrow then we see how to implement these basic functionnalities and how also to make the best out of it
