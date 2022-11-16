#pragma once
#include <string>
#include "AbstractVehicle.h"


namespace atcc
{

	// similate interface in C++
	class IVehicleRepository
	{
	public:

		virtual void addItem(Vehicle* vehicle_ptr) = 0;
		virtual void removeItem(unsigned int key) = 0;
		virtual void listAllItems() const = 0;
		virtual void listVehiclesByYear(unsigned int year) const = 0;
		virtual void listVehiclesByManufacturer(std::string make) const = 0;

	protected:

		IVehicleRepository() {}
		virtual ~IVehicleRepository() {}

	};
}

