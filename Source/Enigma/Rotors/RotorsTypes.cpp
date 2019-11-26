// Fill out your copyright notice in the Description page of Project Settings.


#include "RotorsTypes.h"

RotorsTypes::RotorsTypes() {}

RotorsTypes::~RotorsTypes() {}

const std::string RotorsTypes::IC = "DMTWSILRUYQNKFEJCAZBPGXOHV";
const std::string RotorsTypes::IIC = "HQZGPJTMOBLNCIFDYAWVEUSRKX";
const std::string RotorsTypes::IIIC = "UQNTLSZFMREHDPXKIBVYGJCWOA";
const std::string RotorsTypes::Reflector = "EJMZALYXVBWFCRQUONTSPIKHGD";

const std::vector<RotorType> RotorsTypes::rotorTypes = {
	{ EPossibleRotors::IC, RotorsTypes::IC },
	{ EPossibleRotors::IIC, RotorsTypes::IIC },
	{ EPossibleRotors::IIIC, RotorsTypes::IIIC },
};