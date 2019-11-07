// Fill out your copyright notice in the Description page of Project Settings.


#include "Rotor.h"

Rotor::Rotor()
{}

Rotor::Rotor(PossibleRotors rotorType):
	rotorType(rotorType)
{}

Rotor::~Rotor()
{}

int Rotor::getOutputIndex(int16 index)
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

int Rotor::getReversedOutputIndex(int16 index)
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

std::string Rotor::getRotor()
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

int Rotor::withOverflow(int val)
{
	return val > Rotor::MAX_OFFSET ? 0 : val;
}

int Rotor::withUnderflow(int val)
{
	return val < 0 ? Rotor::MAX_OFFSET : val;
}

void Rotor::increaseOffset()
{
	this->offset++;
	if (this->offset > Rotor::MAX_OFFSET) {
		this->offset = 0;
	}
}

void Rotor::setOffset(int offset)
{
	this->offset = this->withOverflow(offset);
}

int Rotor::getOffset()
{
	return this->offset;
}