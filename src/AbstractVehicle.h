#pragma once
#include <string>

// #include <memory> // for unique_ptr

// atcc : Altem Technology code challenge
namespace atcc
{
	typedef struct
	{
		std::string name;
		std::string country;

	}Manufacturer;

	// this is the base class for Vehicle
	class Vehicle	// abstract class
	{

	public: // Method

		// virtual std::unique_ptr<Vehicle> create() = 0;
		// virtual std::unique_ptr<Vehicle> clone() = 0;

		// pure virtual desctructor 	// need to have a body in base to make linker happy
		virtual ~Vehicle() = 0;			// this make the class abstract

		// don't make pure virtual as common betwen type.
		// derive don't have to implement their own
		virtual std::string getVIN() const;
		virtual std::string getModel() const;
		virtual unsigned int getYear() const;
		virtual std::string getColor() const;
		virtual Manufacturer getManufacturer() const;

		virtual void setVIN(std::string vin);
		virtual void setModel(std::string model);
		virtual void setYear(unsigned int year) ;
		virtual void setColor(std::string color);
		virtual void setManufacturer(const Manufacturer& make);

		virtual std::string toString() const;


	protected: // method. // client to intentiate through factory method
	
		Vehicle(std::string model, unsigned int year, std::string color, std::string vin);
		Vehicle(const Manufacturer& make, std::string model, unsigned int year, std::string color, std::string vin);

	protected: // members
		Manufacturer _make;
		std::string _vin;
		std::string _model;
		unsigned int _year;
		std::string _color;
		std::string _className;

	};
}

