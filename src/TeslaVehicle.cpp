#include "TeslaVehicle.h"
#include <sstream>    
#include <iostream>

namespace atcc
{
    TeslaVehicle::TeslaVehicle(std::string model, unsigned int year, std::string color,
	std::string vin):
		Vehicle(model, year, color, vin)
	{
        this->_make = {"Tesla", "USA"};
		_className = "TeslaVehicle";
	}   

	TeslaVehicle::~TeslaVehicle()
	{
	}

	// This violates the Single Responsibility Principle but it's convenient for now.
	std::string TeslaVehicle::toString() const
	{
		return Vehicle::toString().append(magicString);
	}

}