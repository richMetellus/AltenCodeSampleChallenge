#include <iostream>
#include "VehicleRepositoryRegistry.h"

namespace atcc
{   
    VehicleRepositoryRegistry::VehicleRepositoryRegistry()
    {
        this->_recordId = 0; // unique key
    }

    VehicleRepositoryRegistry::~VehicleRepositoryRegistry()
    {

    }

    void VehicleRepositoryRegistry::addItem(Vehicle* vehicle_ptr)
    {
        _recordId++; // start at 1 and always increasing.
        _inventoryMap[_recordId] = vehicle_ptr;
    }

    void VehicleRepositoryRegistry::removeItem(unsigned int key)
    {
        _inventoryMap.erase(key); //erase record by key
        // could probably delete the object to by getting the object at the key
        // and call delete. but that is not a requirement. Keep it simple.
        // leave it to the class/object to delete it. is this safe?
    }
    
    void VehicleRepositoryRegistry::listAllItems() const
    {   
        std::cout << "record Id : Item" << std::endl;

        for (auto& item: _inventoryMap)
        {
            std::cout << item.first << " : " << item.second->toString() << std::endl;
        }

    }

    void VehicleRepositoryRegistry::listVehiclesByYear(unsigned int year) const
    {
        bool recordFound = false;
        for (auto& item: _inventoryMap)
        {
            if(item.second->getYear() == year)
            {
                recordFound = true;
                std::cout << item.first << " : " << item.second->toString() << std::endl;
            }
        }
        if(!recordFound)
            std::cout << "No Record Found" << std::endl;

    }

    void VehicleRepositoryRegistry::listVehiclesByManufacturer(std::string make) const
    {
        bool recordFound = false;
        for (auto& item: _inventoryMap)
        {
            if(item.second->getManufacturer().name == make)
            {
                recordFound = true;
                std::cout << item.first << " : " << item.second->toString() << std::endl;
            }
        }

        if(!recordFound)
            std::cout << "No Record Found" << std::endl;

    }

}
