#include "GenericVehicle.h"
#include <sstream>    


namespace atcc
{
	GenericVehicle::GenericVehicle(const Manufacturer& make, std::string model, unsigned int year, std::string color,
	std::string vin):
		Vehicle(make, model, year, color, vin)
	{
		_className="GenericVehicle";
	}

	GenericVehicle::~GenericVehicle()
	{
	}

}