// Fill out your copyright notice in the Description page of Project Settings.

#include "EncryptionController.h"

// Sets default values
AEncryptionController::AEncryptionController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AEncryptionController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEncryptionController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEncryptionController::setRotorsController(ARotorsController* controller)
{
	this->rotorsController = controller;
}

ELetter AEncryptionController::encryptLetter(ELetter letterToEncode)
{
	this->rotorsController->doRotation();

	RotorsSetting rotors = this->rotorsController->getCurrentRotors();
	int index = (int)letterToEncode;

	index = this->encodeLetter(index, rotors.rightRotor);
	index = this->encodeLetter(index, rotors.middleRotor);
	index = this->encodeLetter(index, rotors.leftRotor);

	index = this->reflectLetter(index);

	index = this->reverseEncodeLetter(index, rotors.leftRotor);
	index = this->reverseEncodeLetter(index, rotors.middleRotor);
	ELetter result = (ELetter) this->reverseEncodeLetter(index, rotors.rightRotor);
	
	UE_LOG(LogTemp, Warning, TEXT("[[-- log index %d --]]"), result)

	onLightLampOn.Broadcast(result);
	updateUIText.Broadcast(letterToEncode, result);

	return result;
}

int AEncryptionController::encodeLetter(int index, ARotor *rotor)
{
	return rotor->getOutputIndex(index);
}

int AEncryptionController::reverseEncodeLetter(int index, ARotor *rotor)
{
	return rotor->getReversedOutputIndex(index);
}

int AEncryptionController::reflectLetter(int index)
{
	return EnigmaLetter::getIndex( RotorsTypes::Reflector[index] );
}

void AEncryptionController::printChar(char charToPrint)
{
	char arr[1] = { charToPrint };
	FString tmp(arr);

	UE_LOG(LogTemp, Warning, TEXT("[[-- log %s --]]"), *tmp)
}

void AEncryptionController::turnOffLamp(ELetter letter)
{
	onLightLampOff.Broadcast(letter);
}
