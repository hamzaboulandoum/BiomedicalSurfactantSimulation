// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

using namespace std;
#include <iostream>

#include "Math/Vector.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MySurfactant.generated.h"


UCLASS()
class BIOMED_API AMySurfactant : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMySurfactant(); // This is the class constructor;

	//adding some variables 
	UPROPERTY(EditAnywhere,Category="Components")
	class UStaticMeshComponent* SurfactantMesh;

	UPROPERTY(EditAnywhere,Category="Variables")
	float SpeedMaximum = 2000;

	UPROPERTY(EditAnywhere, Category = "Variables")
	FVector Speed;

	UPROPERTY(EditAnywhere, Category = "Variables")
	float Delay = 0.2;


protected: 
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//End Play function
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason)override;
	//Foing into a random postition
	void GoToRandomPosition();
	//it stops everything
	UFUNCTION(BlueprintCallable, Category = "SpeedFunctions", meta = (Keywords = "ClearAll"))
		void ClearAll();
	//it sets the speed to zero
	void SetSpeedToZero();
	//it handles the movement of the surfactant
	void SurfactantMovementHandle();
};
