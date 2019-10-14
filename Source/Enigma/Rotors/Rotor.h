// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <string>

#include "RotorsTypes.h"
#include "CoreMinimal.h"

/**
 * 
 */
class ENIGMA_API Rotor
{
public:
	PossibleRotors rotorType;

public:
	Rotor();
	Rotor(PossibleRotors rotorType);
	~Rotor();

	char getEncodedLetter(int16 index);
};
