// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <string>
#include <vector>

#include "CoreMinimal.h"

enum PossibleRotors { IC, IIC, IIIC };

typedef struct {
	PossibleRotors type;
	std::string rotorWiring;
} RotorType;


/**
 * 
 */
class ENIGMA_API RotorsTypes
{
private:
	// 1924 - Commercial Engima A, B
	static const char IC[];
	static const char IIC[];
	static const char IIIC[];

public:
	static const std::vector<RotorType> rotorTypes;

public:
	RotorsTypes();
	~RotorsTypes();
};
