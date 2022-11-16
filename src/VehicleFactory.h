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
		// right now it only create default , but it can change to allow user input.
		// this is convenient for now as a demonstration
		static Vehicle* createVehicle(vehicleType type)
		{
			Vehicle* aVehicle = NULL;
			Manufacturer defaultManufacturer;

			switch (type)
			{
				case eGenericVehicle:
					defaultManufacturer = {"Ford", "USA"};
					aVehicle = new GenericVehicle(defaultManufacturer, "Bronco", 2020, "Red", "AJLDOE-8424DO2-AKOAJ");
					break;
			
				case eBWMVehicle:
					aVehicle = new BMWVehicle("X3", 2021, "Black", "SBMWDB-ODDSOEO8-94JD");
					break;
			
				case eTeslaVehicle:
					aVehicle = new TeslaVehicle("Model S", 2022, "Silver", "TDOWLD-DSO-EO894JD");
					break;
			
				default:
					std::cout << "Invalid type entry";
					break;
			}
			return aVehicle;

		}
	};
}

