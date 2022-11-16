// AltemTechCodeSample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include "VehicleRepositoryRegistry.h"
#include "VehicleFactory.h"

typedef enum 
{
    eQuit,
    ePrintUsageHelp,
    eList,
    eFetchByYear,
    eFetchByManufacturer,
    eCreateNew,
    eRemove

}CommandOptionEnumType;

void usage()
{
    std::cerr
            << "\n\n================ Usage ============================================\n\n"
            << "The commands that are supported are as followed:\n"
            << eQuit                << " or any key to quit\n"
            << ePrintUsageHelp      << " : print this help message\n"
            << "======= Options for manipulating the inventory: ========\n"
            << eList                << " : List item in the inventory\n"
            << eFetchByYear         << " : Fetch all vehicle by year \n"
            << eFetchByManufacturer << " : Fetch all vehicle by manufacturer name \n"
            << eCreateNew           << " : create new vehicle prototype \n"
                                            << "         0: Generic default vehicle\n"
                                            << "         1: BMW \n"
                                            << "         2: Tesla\n"
            << eRemove              << " : to remove item from the inventory given by the record id\n"
                                            << "       Provide the record id as option:\n"
                                            << "       <id> \n"
            << std::endl;
}

int main()
{
    SetConsoleOutputCP(1252);
    // Demo:
    std::cout << "create vehicle using factory \n " << atcc::eTeslaVehicle <<std::endl;;
    atcc::Vehicle* randomVehicle = atcc::VehicleFactory::createVehicle(atcc::eTeslaVehicle);
    
    std::cout << randomVehicle->toString();


    atcc::VehicleRepositoryRegistry* carInventory = new atcc::VehicleRepositoryRegistry();
    carInventory->addItem(randomVehicle);
    randomVehicle = atcc::VehicleFactory::createVehicle(atcc::eGenericVehicle);
    carInventory->addItem(randomVehicle);
    
    randomVehicle = atcc::VehicleFactory::createVehicle(atcc::eTeslaVehicle);
    carInventory->addItem(randomVehicle);
    randomVehicle = atcc::VehicleFactory::createVehicle(atcc::eBWMVehicle);
    carInventory->addItem(randomVehicle);
    randomVehicle = atcc::VehicleFactory::createVehicle(atcc::eBWMVehicle);
    carInventory->addItem(randomVehicle);

    randomVehicle = atcc::VehicleFactory::createVehicle(atcc::eTeslaVehicle);
    carInventory->addItem(randomVehicle);
    randomVehicle = atcc::VehicleFactory::createVehicle(atcc::eTeslaVehicle);
    carInventory->addItem(randomVehicle);

    randomVehicle = atcc::VehicleFactory::createVehicle(atcc::eGenericVehicle);
    carInventory->addItem(randomVehicle);

    randomVehicle = atcc::VehicleFactory::createVehicle(atcc::eTeslaVehicle);
    carInventory->addItem(randomVehicle);

    // TEST
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

    std::cout << "\nAll entries in the repository by year 2022: \n";
    carInventory->listVehiclesByYear(2022);

    std::cout << "\nAll entries in the repository made by Ford: \n";
    carInventory->listVehiclesByManufacturer("Ford");

    usage();

    unsigned int command, recordId = 0, year = 0;
    std::string manufacturerName = "";
    int userValue;
    atcc::vehicleType userVehicleType = atcc::eTeslaVehicle;
    bool exit = false;
    char userChoiceChar = 'n';

    do
    {
        command = eQuit;

        try
        {
            std::cout << "Enter a command: ";
            std::cin >> command;

            switch(command)
            {
                case eQuit:
                {
                    exit = true;
                    break;
                }

                case ePrintUsageHelp:
                {
                    usage();
                    break;
                }

                case eList:
                {
                    carInventory->listAllItems();
                    break;
                }

                case eFetchByYear:
                {
                    std::cout << "Enter Year: " ;
                    std::cin >> year;
                    carInventory->listVehiclesByYear(year);
                    break;
                } 

                case eFetchByManufacturer:
                {
                    std::cout << "Enter manufacturer name: " ;
                    std::cin >> manufacturerName;
                    carInventory->listVehiclesByManufacturer(manufacturerName);
                    break;
                } 

                case eCreateNew:
                {
                    std::cout << "Enter Vehicle type: " ;
                    std::cin >> userValue;
                    userVehicleType = static_cast<atcc::vehicleType>(userValue);
                    randomVehicle = atcc::VehicleFactory::createVehicle(userVehicleType);
                    std::cout << "vehicle: " << randomVehicle->toString() << " created" <<std::endl;
                    std::cout << "Do you want to add it to the inventory [y/n]?" << std::endl;
                    std::cin >> userChoiceChar;
                    switch (userChoiceChar)
                    {
                        case 'y':
                            carInventory->addItem(randomVehicle);
                            break;
                        case 'n':
                        default:
                            break;
                    }
                    break;
                }
                case eRemove:
                {
                    std::cout << "Enter record id: " ;
                    std::cin >> recordId;
                    carInventory->removeItem(recordId);
                    break;
                } 
                default:
                    std::cout << "Command not implemented" << std::endl;
                    break;                        
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            exit = true;
        }
        catch(...)
        {
            std::cout << "unknown exception" << std::endl;
            exit = true;
        }
        
        
    } while (!exit);
    



}

