// Fill out your copyright notice in the Description page of Project Settings.

#include "Rotor.h"

// Sets default values
ARotor::ARotor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ARotor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int ARotor::getOutputIndex(int16 index)
{
	std::string rotor = this->getRotor();

	if (rotor.empty()) {
		return -1;
	} else {
		char outputLetter = rotor[this->withOverflow(index + this->offset)];
		int outputIndex = EnigmaLetter::getIndex(outputLetter) - this->offset;

		return this->withUnderflow(outputIndex);
	}
}

int ARotor::getReversedOutputIndex(int16 index)
{
	std::string rotor = this->getRotor();

	if (rotor.empty()) return -1;

	char letter = EnigmaLetter::getLetter(this->withOverflow(index + this->offset));

	for (int i = 0; i < rotor.length(); i++) {
		if (rotor[i] == letter) {
			return this->withUnderflow(i - this->offset);
		}
	}

	return -1;
}

std::string ARotor::getRotor()
{
	std::string searched;

	for (RotorType type : RotorsTypes::rotorTypes) {
		if (type.type == this->rotorType) {
			searched = type.rotorWiring;
			break;
		}
	}

	return searched;
}

int ARotor::withOverflow(int val)
{
	return val % (MAX_OFFSET + 1);
}

int ARotor::withUnderflow(int val)
{
	while (val < 0) {
		val = val + (MAX_OFFSET + 1);
	}

	return val % (MAX_OFFSET + 1);
}

void ARotor::increaseOffset(bool applyOffset)
{
	this->offset++;
	if (this->offset > ARotor::MAX_OFFSET) {
		this->offset = 0;
	}

	if (applyOffset) {
		animateNewOffset(stepDegree * offset);
	}
}

int ARotor::getOffset()
{
	return this->offset;
}

void ARotor::setOffset(int newOffset)
{
	if (newOffset >= 0 && newOffset <= MAX_OFFSET) {
		this->offset = newOffset;
	}
}
