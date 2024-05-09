// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	SetVelocity();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ClimbingPlatform(DeltaTime);
	ScrollingPlatform(DeltaTime);
	RotatingPlatform(DeltaTime);
}

void AMovingPlatform::SetVelocity()
{
	ClimbVelocity = FVector(0, 0, ClimbSpeed);

	if (XAxis == true)
	{
		ScrollingVelocity = FVector(ScrollingSpeed, 0, 0);
	}
	else 
	{
		ScrollingVelocity = FVector(0, ScrollingSpeed, 0);
	}
	
	RotatingVelocity = FRotator(0, RotateSpeed, 0);
}

void AMovingPlatform::ClimbingPlatform(float DeltaTime)
{
	if (ClimbEnabled == true)
	{
		FVector ClimbLocation = GetActorLocation();
		ClimbLocation = ClimbLocation + (ClimbVelocity * DeltaTime);

		SetActorLocation(ClimbLocation);

		float DistanceClimbed = FVector::Dist(StartLocation, ClimbLocation);

		if (DistanceClimbed > ClimbDistance)
		{
			FVector ClimbDirection = ClimbVelocity.GetSafeNormal();
			StartLocation = StartLocation + ClimbDirection * ClimbDistance;
			SetActorLocation(StartLocation);
			ClimbVelocity = -ClimbVelocity;
		}
	}
}

void AMovingPlatform::ScrollingPlatform(float DeltaTime)
{
	if (ScrollingEnabled == true)
	{
		FVector ScrollingLocation = GetActorLocation();
		ScrollingLocation = ScrollingLocation + (ScrollingVelocity * DeltaTime);

		SetActorLocation(ScrollingLocation);

		float DistanceScrolled = FVector::Dist(StartLocation, ScrollingLocation);

		if (DistanceScrolled > ScrollingDistance)
		{
			FVector ScrollingDirection = ScrollingVelocity.GetSafeNormal();
			StartLocation = StartLocation + ScrollingDirection * ScrollingDistance;
			SetActorLocation(StartLocation);
			ScrollingVelocity = -ScrollingVelocity;
		}
	}
}

void AMovingPlatform::RotatingPlatform(float DeltaTime)
{
	if (RotatingEnabled == true)
	{
		FRotator ActorRotation = GetActorRotation();
		ActorRotation = ActorRotation + (RotatingVelocity * DeltaTime);

		SetActorRotation(ActorRotation);
	}
}

