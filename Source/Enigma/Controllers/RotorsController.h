// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <string>

#include "../Rotors/Rotor.h"
#include "../Rotors/RotorsTypes.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotorsController.generated.h"

typedef struct {
	Rotor* leftRotor;
	Rotor* middleRotor;
	Rotor* rightRotor;
} RotorsSetting;

UCLASS()
class ENIGMA_API ARotorsController : public AActor
{
	GENERATED_BODY()
private:
	Rotor leftRotor;
	Rotor middleRotor;
	Rotor rightRotor;

public:
	// Sets default values for this actor's properties
	ARotorsController();

	RotorsSetting getCurrentRotors();
	void doRotation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
