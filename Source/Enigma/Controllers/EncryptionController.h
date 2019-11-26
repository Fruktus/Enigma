// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "./RotorsController.h"
#include "../Rotors/Rotor.h"
#include "../Rotors/RotorsTypes.h"
#include "../Helpers/EnigmaLetter.h"
#include "EncryptionController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLightLampDelegate, ELetter, letter);

UCLASS()
class ENIGMA_API AEncryptionController : public AActor
{
	GENERATED_BODY()
private:
	ARotorsController* rotorsController;

public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FLightLampDelegate onLightLamp;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this actor's properties
	AEncryptionController();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Setter")
	void setRotorsController(ARotorsController* controller);

	UFUNCTION(BlueprintCallable, Category = "Controller")
	void encryptLetter(ELetter letterToEncode);

private:
	int encodeLetter(int index, ARotor *rotor);
	int reverseEncodeLetter(int index, ARotor *rotor);
	int reflectLetter(int index);
	int letterToIndex(char letter);
	char indexToLetter(int index);
	void printChar(char charToPrint);
};
