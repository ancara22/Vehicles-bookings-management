#include "vehicles.h"
#include "functions.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>



int main() {
  std::vector<Vehicle*> vehiclesBase;
  std::string file_path;
  bool isPathIncorrect = true;
  bool toContinue = true;
  
  std::cout << "\n\n---------------------------------------------------------------------------------";
  std::cout << "\n------------------------------  Parking Management ------------------------------\n";
  std::cout << "---------------------------------------------------------------------------------\n\n";

  //Read data from file
  while(isPathIncorrect)  {
    std::cout << "Enter absolute/relative file path(or enter Y to read the default file): ";
    std::cin >> file_path;
    if(file_path == "Y") {
      file_path = "/Users/dinisbarcari/Documents/coursework1SOFT/vehicles.dat";
    }

    createVehiclesFromFile(file_path, &vehiclesBase);

    if(vehiclesBase.size() == 0) {
      std::cout << "\n----------------------- Incorrect file path! Try again! -------------------------\n\n";
    } else  {
      std::cout << "\n-----------------------------------  Succes! ------------------------------------";
      isPathIncorrect = false;
    }

  }

  
  //Menu options
  while(toContinue) {
    std::string operation;
    std::cout << "\n---------------------------------------------------------------------------------\n\n";
    std::cout << "                                      MENU\n\n";
    std::cout << "           1. Print List(All detailes)               4. Find Vehicle\n";
    std::cout << "           2. Print List(Short)                      5. Add Vehicle\n";
    std::cout << "           3. Save File                              6. Remove Vehicle \n";
    std::cout << "                                                     7. Exit \n";

    std::cout << "\nSelect operation: ";
    std::cin >> operation;

    if(operation == "1") {
      printVehiclesList("L", vehiclesBase);        //Print vehicles data, Long form
    } else if(operation == "2")  {
      printVehiclesList("S", vehiclesBase);        //Print vehicle data, Short form
    } else if(operation == "3")  {                 //Save data in a file
      std::string fileName;
      std::cout << "Enter file name (<file name>.dat): ";
      std::cin >> fileName;
      saveFile(fileName, vehiclesBase);           //!!!!
    } else if(operation == "4")  {                 
      std::string regNumber;                       //Find a vehicle by registration number
      std::cout << "Enter Registration Number: ";
      std::cin >> regNumber;
      
      std::vector<Vehicle*> tempV = findVehicle(vehiclesBase, regNumber) ;

      if(tempV.size() != 0) {
	printVehiclesList("L", tempV);
      } else {
	std::cout << "\n------------------------------  No Results Found! -------------------------------";
      }
  
    } else if(operation == "5")  {                 //Add Vehicle
      std::string type, make, model, reg_id, motor, seats, luggage, color, available, price, return_date;
      std::cout << "\n---------------------------------------------------------------------------------\n\n";
      std::cout << "                                      NEW VEHICLE\n\n";

      bool isIncorrectType = true;
	
      while(isIncorrectType) {
	std::cout << "Type(car, van, bike): ";
	std::cin >> type;
	
	if(type == "car" || type == "van" || type == "bike") {
	  isIncorrectType = false;
	} else {
	  std::cout << "Incorect Type!!! Try again.\n";
	}

      }
      
      std::cout << "Make: ";
      std::cin >> make;
      std::cout << "Model: ";
      std::cin >> model;
      std::cout << "Registration Number(Uppercase): ";
      std::cin >> reg_id;
      std::cout << "Engine size: ";
      std::cin >> motor;
      std::cout << "Seats: ";
      std::cin >> seats;
      std::cout << "Luggage: ";
      std::cin >> luggage;
      std::cout << "Color: ";
      std::cin >> color;
      std::cout << "Availability(Yes/No): ";
      std::cin >> available;
      std::cout << "Price(£): ";
      std::cin >> price;
      std::cout << "Return Date(Date/ N/A): ";
      std::cin >> return_date;
      
      addNewVehicle(type, make, model, reg_id, motor, seats, luggage, color, available,price, return_date, &vehiclesBase);

      std::cout << "\n------------------- A New Vehicle is added in the Database! ---------------------\n";
      
    } else if(operation == "6") {
      //delete item
      std::string toRemove;
      std::cout << "Enter Registration Number(Uppercase): ";
      std::cin >> toRemove;

      removeVehicle(toRemove, &vehiclesBase);
      
    } else if(operation == "7") {
      std::cout << "\n----------------------------------- Goodbye! ------------------------------------\n\n";
      toContinue = false;                          //Exit
    } else  {
      std::cout << "\n----------------------- Incorrect Operation! Try again! -------------------------\n";
    }
  }
  
  return 0;
 
 
}
