// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <string>

#include "../Helpers/EnigmaLetter.h"
#include "RotorsTypes.h"
#include "CoreMinimal.h"


class ENIGMA_API Rotor
{
private:
	static const int MAX_OFFSET = 25;
	int8 offset = 0;

public:
	PossibleRotors rotorType;

private:
	std::string getRotor();
	int withOverflow(int val);
	int withUnderflow(int val);

public:
	Rotor();
	Rotor(PossibleRotors rotorType);
	~Rotor();

	int getOutputIndex(int16 index);
	int getReversedOutputIndex(int16 index);

	void increaseOffset();
	void setOffset(int offset);
};
