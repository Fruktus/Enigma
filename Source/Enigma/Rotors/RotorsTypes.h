// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <string>
#include <vector>

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EPossibleRotors : uint8 { IC, IIC, IIIC };

typedef struct {
	EPossibleRotors type;
	std::string rotorWiring;
} RotorType;


/**
 * 
 */
class ENIGMA_API RotorsTypes
{
private:
	// 1924 - Commercial Engima A, B
	static const std::string IC;
	static const std::string IIC;
	static const std::string IIIC;

public:
	static const std::string Reflector;
	static const std::vector<RotorType> rotorTypes;

public:
	RotorsTypes();
	~RotorsTypes();
};
