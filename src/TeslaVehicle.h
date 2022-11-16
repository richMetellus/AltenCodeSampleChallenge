#pragma once
#include <string>
#include "AbstractVehicle.h"

namespace atcc
{

	class TeslaVehicle : virtual public Vehicle
	{
	public: // Method

		TeslaVehicle(std::string model, unsigned int year, std::string color, std::string vin);
		~TeslaVehicle();


		// This violate the S in SOLID but it shows override
		std::string toString() const override;

	private: // member
		const std::string magicString = "Battery Included!";

	};
}

