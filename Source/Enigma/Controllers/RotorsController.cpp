// Fill out your copyright notice in the Description page of Project Settings.


#include "RotorsController.h"

// Sets default values
ARotorsController::ARotorsController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ARotorsController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ARotorsController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

RotorsSetting ARotorsController::getCurrentRotors()
{
	RotorsSetting settings = {
		leftRotor,
		middleRotor,
		rightRotor
	};

	return settings;
}

void ARotorsController::doRotation()
{
	rightRotor->increaseOffset(true);

	if (rightRotor->getOffset() == 0) {
		middleRotor->increaseOffset(true);
		
		if (middleRotor->getOffset() == 0) {
			leftRotor->increaseOffset(true);
		}
	}
}
