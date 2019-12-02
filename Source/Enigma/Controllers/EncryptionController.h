// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "./RotorsController.h"
#include "../Rotors/Rotor.h"
#include "../Rotors/RotorsTypes.h"
#include "../Helpers/EnigmaLetter.h"
#include "EncryptionController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLightLampOnDelegate, ELetter, letter);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLightLampOffDelegate, ELetter, letter);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUpdateTextsDelegate, ELetter, typedLetter, ELetter, codedLetter);

UCLASS()
class ENIGMA_API AEncryptionController : public AActor
{
	GENERATED_BODY()
private:
	ARotorsController* rotorsController;

public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FLightLampOnDelegate onLightLampOn;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FLightLampOffDelegate onLightLampOff;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FUpdateTextsDelegate updateUIText;

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
	ELetter encryptLetter(ELetter letterToEncode);

	UFUNCTION(BlueprintCallable, Category = "Controller")
	void turnOffLamp(ELetter letter);

private:
	int encodeLetter(int index, ARotor *rotor);
	int reverseEncodeLetter(int index, ARotor *rotor);
	int reflectLetter(int index);
	int letterToIndex(char letter);
	char indexToLetter(int index);
	void printChar(char charToPrint);
};
