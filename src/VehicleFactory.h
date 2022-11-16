#pragma once
#include "AbstractVehicle.h"
#include <iostream>
#include "GenericVehicle.h"
#include "BMWVehicle.h"
#include "TeslaVehicle.h"

namespace atcc
{
	//forward class declaration

	typedef enum 
	{
		eGenericVehicle,
		eBWMVehicle,
		eTeslaVehicle

	}vehicleType;
	// creator/ factory for Vehicle
	// base class
	class VehicleFactory
	{
	public:

		// factory method to create different type of objects
		    // provide an extra level of abstraction so client code doesn't have to create their own object
		static Vehicle* createVehicle(vehicleType type)
		{
			Vehicle* aVehicle = NULL;
			Manufacturer defaultManufacturer;

			switch (type)
			{
				case eGenericVehicle:
					defaultManufacturer = {"Ford", "USA"};
					aVehicle = new GenericVehicle(defaultManufacturer, "Bronco", 2016, "Red", "AFCD23doa");
					break;
			
				case eBWMVehicle:
					aVehicle = new BMWVehicle("X3", 2022, "Black", "SBMWDBOD-DSO-EO894JD");
					break;
			
				case eTeslaVehicle:
					aVehicle = new TeslaVehicle("Model S", 2022, "Silver", "TDOWLD-DSO-EO894JD");
					break;
			
				default:
					std::cout << "Invalid type entry";
					break;
			}
			//TODO: WARNING: after the function exit, the variable is destroyed but the memory will
			// not be deallocated. So I might have to use some kind of smart pointer instead.
			return aVehicle;

		}
	};
}

