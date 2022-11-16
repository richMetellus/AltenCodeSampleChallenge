#pragma once
#include <string>
#include "AbstractVehicle.h"

namespace atcc
{

	class GenericVehicle:  virtual public Vehicle
	{
	public: // Method
	
		GenericVehicle(const Manufacturer& make, std::string model, unsigned int year, std::string color,
		std::string vin );
		~GenericVehicle();

	};
}

