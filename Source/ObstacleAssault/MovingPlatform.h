// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FVector StartLocation;

	void SetVelocity();
	FVector ClimbVelocity;

	void ClimbingPlatform(float DeltaTime);
	UPROPERTY(EditAnywhere, Category = "Climbing")
	bool ClimbEnabled = false;
	UPROPERTY(EditAnywhere, Category = "Climbing")
	float ClimbSpeed = 100.f;
	UPROPERTY(EditAnywhere, Category = "Climbing", meta = (ClampMin = "0.0", ClampMax = "1200.0"))
	float ClimbDistance = 1189.f;

};
