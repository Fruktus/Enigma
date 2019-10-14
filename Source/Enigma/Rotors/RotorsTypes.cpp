// Fill out your copyright notice in the Description page of Project Settings.


#include "RotorsTypes.h"

RotorsTypes::RotorsTypes() {}

RotorsTypes::~RotorsTypes() {}

const char RotorsTypes::IC[] = "DMTWSILRUYQNKFEJCAZBPGXOHV";
const char RotorsTypes::IIC[] = "HQZGPJTMOBLNCIFDYAWVEUSRKX";
const char RotorsTypes::IIIC[] = "UQNTLSZFMREHDPXKIBVYGJCWOA";

const std::vector<RotorType> RotorsTypes::rotorTypes = {
	{ PossibleRotors::IC, RotorsTypes::IC },
	{ PossibleRotors::IIC, RotorsTypes::IIC },
	{ PossibleRotors::IIIC, RotorsTypes::IIIC },
};