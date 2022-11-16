// AltemTechCodeSample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include <fcntl.h>
//#include <io.h>
#include "GenericVehicle.h"
#include "BMWVehicle.h"
#include "TeslaVehicle.h"
#include "IVehicleRepository.h"
#include "VehicleRepositoryRegistry.h"
#include "VehicleFactory.h"

void usage()
{
    
}
int main()
{
   

    std::cout << "create vehicle using factory \n " << atcc::eTeslaVehicle <<std::endl;;
    atcc::Vehicle* randomVehicle = atcc::VehicleFactory::createVehicle(atcc::eTeslaVehicle);
    
    std::cout << randomVehicle->toString();


    atcc::VehicleRepositoryRegistry* carInventory = new atcc::VehicleRepositoryRegistry();
    carInventory->addItem(randomVehicle);
    randomVehicle = atcc::VehicleFactory::createVehicle(atcc::eGenericVehicle);
    carInventory->addItem(randomVehicle);
    
    randomVehicle = atcc::VehicleFactory::createVehicle(atcc::eBWMVehicle);
    carInventory->addItem(randomVehicle);
    randomVehicle = atcc::VehicleFactory::createVehicle(atcc::eBWMVehicle);
    carInventory->addItem(randomVehicle);
    randomVehicle = atcc::VehicleFactory::createVehicle(atcc::eBWMVehicle);
    carInventory->addItem(randomVehicle);
    // _setmode(_fileno(stdout), _O_U16TEXT);
    // wchar_t* copyright = L"Copyright ©\r\n";
    // wprintf(copyright);


    std::cout << "\nAll entries in the repository: \n";
    carInventory->listAllItems();

    std::cout << "\nlist of vehicle made by BMW in the repository: \n";
    carInventory->listVehiclesByManufacturer("BMW");

    std::cout << "\nlist of vehicle made by Tesla in the repository: \n";
    carInventory->listVehiclesByManufacturer("Tesla");

    std::cout << "\nlist of vehicle made by Vhe in the repository: \n";
    carInventory->listVehiclesByManufacturer("Vhe");

    std::cout << "\n Remove record id 1, 3 \n";
    carInventory->removeItem(1);
    carInventory->removeItem(3);

    std::cout << "\n Attempt to remove non-existing key entry id:100 \n";
    carInventory->removeItem(100);  // this doest not cause program to crash

    std::cout << "\nAll entries in the repository: \n";
    carInventory->listAllItems();



}

