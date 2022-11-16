#pragma once
#include <unordered_map>
#include "IVehicleRepository.h"


namespace atcc
{

    class VehicleRepositoryRegistry:  public IVehicleRepository
    {
	public:

		 VehicleRepositoryRegistry();
		 ~VehicleRepositoryRegistry();

		 void addItem(Vehicle* vehicle_ptr) ;
		 void removeItem(unsigned int key) ;
		 void listAllItems() const ;
		 void listVehiclesByYear(unsigned int year) const ;
		 void listVehiclesByManufacturer(std::string make) const ;

		 // utility methods
		 /*
		 * Method that will populate the inventory with
		 */
		//  void makeCache();
		//  void loadCache();

	private:  // members

		std::unordered_map<unsigned int, Vehicle* > _inventoryMap; // a map of vehicle record
        unsigned int _recordId;

    };

}

