#pragma once
#include <string>
#include "AbstractVehicle.h"

namespace atcc
{

	class BMWVehicle:  virtual public Vehicle
	{
	public: // Method

		BMWVehicle(std::string model, unsigned int year, std::string color, std::string vin );
		~BMWVehicle();

		
        // This violate the S in SOLID but it shows override
        std::string toString() const override;
    
    private: // member
        std::string magicString;
    
	};
}



