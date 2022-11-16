#include "BMWVehicle.h"
#include <sstream>    

namespace atcc
{
	BMWVehicle::BMWVehicle(std::string model, unsigned int year, std::string color,
	std::string vin):
		Vehicle(model, year, color, vin)
	{
        this->_make = {"BMW", "Germany"};
		_className = "BMWVehicle";
		magicString = "\u00A9 BMW AG, Munich, Germany";
	}   

	BMWVehicle::~BMWVehicle()
	{
	}

	// This violates the Single Responsibility Principle but it's convenient for now.
	std::string BMWVehicle::toString() const
	{
	
		return Vehicle::toString().append(magicString);
	}

}