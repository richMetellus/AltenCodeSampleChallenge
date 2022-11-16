#include <sstream>    
#include "AbstractVehicle.h"

namespace atcc
{

	Vehicle::Vehicle(std::string model, unsigned int year, std::string color,
	std::string vin) :
		_model(model),
		_year(year),
		_color(color),
		_vin(vin)
	{

	}

	Vehicle::Vehicle(const Manufacturer& make, std::string model, unsigned int year, std::string color,
	std::string vin) :
		Vehicle(model, year, color, vin)
	{
		this->_make = make;
	}

	Vehicle::~Vehicle() 
	{
	}

	std::string Vehicle::getVIN() const
	{
		return _vin;
	}

	std::string Vehicle::getModel() const
	{
		return _model;
	}

	unsigned int Vehicle::getYear() const
	{
		return _year;
	}

	std::string Vehicle::getColor() const
	{
		return _color;
	}

	void Vehicle::setVIN(std::string vin)
	{
		this->_vin = vin;
	}

	void Vehicle::setModel(std::string model)
	{
		this->_model = model;
	}

	void Vehicle::setYear(unsigned int year)
	{
		_year = year;
	}
	void Vehicle::setColor(std::string color)
	{
		_model = color;
	}

	Manufacturer Vehicle::getManufacturer() const
	{
		return _make;
	}

	void Vehicle::setManufacturer(const Manufacturer& make)
	{
		_make = make;
	}

	// This violates the Single Responsibility Principle but it's convenient for now.
	// I can provide another abstract Logger whose sole responsibility is to print the class info
	std::string Vehicle::toString() const
	{
		std::ostringstream vehicleInfoStream;
		vehicleInfoStream << _color <<" " << _year << " " << _make.name << " " << _model <<
						  " " << _vin << " ";
		
		return vehicleInfoStream.str();

	}


}