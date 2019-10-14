// Fill out your copyright notice in the Description page of Project Settings.


#include "Rotor.h"

Rotor::Rotor()
{}

Rotor::Rotor(PossibleRotors rotorType):
	rotorType(rotorType)
{}

Rotor::~Rotor()
{}

char Rotor::getEncodedLetter(int16 index)
{
	RotorType* searched;

	for (RotorType type : RotorsTypes::rotorTypes) {
		if (type.type == this->rotorType) {
			searched = &type;
			break;
		}
	}

	return searched->rotorWiring[index];
}
