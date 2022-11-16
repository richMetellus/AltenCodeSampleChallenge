# Alten Code Sample Challenge

This is my solution provided to Atlen Technology as a work sample. This is to only demonstrate 
my understanding of Object oriented programming concepts. Nothing too fancy.

## Description

**Work Sample Exercise**

As part of our hiring process, we have applicants for software engineering positions develop a 
small “work sample” in an object-oriented language. It's a chance for us to see how you would 
tackle the kind of work we do here at ALTEN Technology.

That said, this is NOT meant to be a full-blown application with UI/database/installer, we're just 
looking for a small demonstration of design approach and coding style that should take you 
no more than a couple hours.

You may use C#, Java, C++ or Python to complete the exercise. Please reply to this email to submit 
your completed work sample, including details of your OS, language and compiler or IDE, 
and instructions on how to build.

**Overview**

The goal of this exercise is 

* to develop a small solution for managing an inventory of vehicles.

.. note::
    This is NOT meant to be a complete application and does't need a database. It does need to 
    be an object-oriented solution that demonstrates design approach, code structure, and coding style. 
    We're looking for things like good use of abstraction, SOLID principles, and design patterns.  

**Application Features**

1. Provide a way to represent vehicles:

    * Each vehicle should have

        * a vehicle identification number (VIN), 
        * manufacturer (such as BMW, Ford, etc.), 
        * model, 
        * year, 
        * and color. 
        
        .. note::
            Other than the manufacturer, these can be simple primitive types (e.g., int, string, enum). 
            We are not designing an actual vehicle inventory system!

    * A vehicle should contain manufacturer information for the vehicle, 

        * consisting of a manufacturer name 
         * and a country.

    * A vehicle should be able to return a string representation of itself that consists of the 
      color, year, manufacturer name, model, and VIN.

    * If the vehicle is a BMW, then the string must end with `© BMW AG, Munich, Germany`.
    * If the vehicle is a Tesla, then the string must end with “(Batteries Included!)”.

2. Create a repository with the following functionality:
    
    - A way to add a vehicle to, and remove a vehicle from, the inventory.
    - A way to fetch a list of vehicles that match a specified year.
    - A way to fetch a list of vehicles that of a given manufacturer.

3. When executed, the application should populate the inventory with a some example 
   vehicles, and then print to the console:

    - A list of all the vehicles in the inventory.
    - A list of vehicles from a specific year or manufacturer.


## Run and Execute

The project provide 2 solution:

1. A make project that can run on any basic linux shell
2.  A basic visual studio project  that will run on windows console

Tested on 

* WSL/ubuntu 20.04 LTS and Centos 8
  * this include gcc 9.4
* Tested on IDE: Visual Studio Community 2019.
  

### Run on Linux or WSL


1. Clone the repository using `git clone https://github.com/richMetellus/AltenCodeSampleChallenge.git`
2. At the top of the project run `make`
3. The build executable will be located at `build/AltenCodeApp`.

### Run on Windows

1. Open the visual studio
2. Click on `open project or solution` and navigate to the project/vs/AltenCodeSampleApp/AltenCodeSampleApp.sln
3. run the solution.


The application will list how to use it and interact with the user.
Follow the instruction on the screen.
