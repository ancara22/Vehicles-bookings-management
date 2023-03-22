#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "vehicles.h"
#include "functions.h"
#include <fstream>
#include <string>



std::string type = "car";
std::string make = "BMW";
std::string model = "X5";
std::string reg_nr = "CG4DS5E";
std::string engine =  "2.0L";
std::string seats =  "3 seats";
std::string doors =  "5 doors";
std::string color =  "black";
std::string price =  "120$";
std::string avail =  "Yes";
std::string return_d = "N/A";
std::string space = "10.5";



TEST_CASE("test_car", "[class]") {
  Car car(type, make, model, reg_nr, engine, seats, doors, color, price, avail, return_d);

  REQUIRE(car.getType() == type);
  REQUIRE(car.getMake() == make);
  REQUIRE(car.getModel() == model);
  REQUIRE(car.getRegistrationNumber() == reg_nr);
  REQUIRE(car.getEngineSize() == engine);
  REQUIRE(car.getColor() == color);
  REQUIRE(car.getPrice() == price);
  REQUIRE(car.getAvailability() == avail);
  REQUIRE(car.getReturnDate() == return_d);
   
  REQUIRE(car.getNumberOfSeats() == seats);
  REQUIRE(car.getNumberOfDoors() == doors);

}


TEST_CASE("test_van", "[class]") {
   Van van(type, make, model, reg_nr, engine, seats, space, color, price, avail, return_d);
    
   REQUIRE(van.getType() == type);
   REQUIRE(van.getMake() == make);
   REQUIRE(van.getModel() == model);
   REQUIRE(van.getRegistrationNumber() == reg_nr);
   REQUIRE(van.getEngineSize() == engine);
   REQUIRE(van.getColor() == color);
   REQUIRE(van.getPrice() == price);
   REQUIRE(van.getAvailability() == avail);
   REQUIRE(van.getReturnDate() == return_d);
   
   REQUIRE(van.getPassengerSeats() == seats);
   REQUIRE(van.getLuggageSpace() == space);

}


TEST_CASE("test_bike", "[class]") {
   Motorcycle bike(type, make, model, reg_nr, engine, seats, space, color, price, avail, return_d);
   
   REQUIRE(bike.getType() == type);
   REQUIRE(bike.getMake() == make);
   REQUIRE(bike.getModel() == model);
   REQUIRE(bike.getRegistrationNumber() == reg_nr);
   REQUIRE(bike.getEngineSize() == engine);
   REQUIRE(bike.getColor() == color);
   REQUIRE(bike.getPrice() == price);
   REQUIRE(bike.getAvailability() == avail);
   REQUIRE(bike.getReturnDate() == return_d);
   
   REQUIRE(bike.getPassengerSeat() == seats);
   REQUIRE(bike.getLuggageSpace() == space);
}





TEST_CASE("test_add", "[funct]") {
  std::vector<Vehicle*> vect;
  addNewVehicle(type, make, model, reg_nr, engine, seats, space, color, avail, price, return_d,  &vect);

  REQUIRE(vect.size() == 1);
  REQUIRE(vect[0]->getType() == type);

  addNewVehicle("incorrect type", make, model, reg_nr, engine, seats, space, color, avail, price, return_d,  &vect);
   
  REQUIRE(vect.size() == 1);   

  std::vector<Vehicle*> saveInVector;
  
  createVehiclesFromFile("./vehicles.dat", &saveInVector);
  REQUIRE(saveInVector.size() > 0);

  std::vector<Vehicle*> saveInVector2;
  createVehiclesFromFile("./incorrect.dat", &saveInVector2);
  REQUIRE(!(saveInVector2.size() > 0));

  std::vector<Vehicle*> veh = findVehicle(saveInVector, "NNN....N");
  REQUIRE(veh.size() == 0);

  std::string reg_nr;
  for(unsigned long  i=0; i<saveInVector.size(); i++) {
    reg_nr = saveInVector[i]->getRegistrationNumber();
    veh = findVehicle(saveInVector, reg_nr);
    REQUIRE(veh.size() == 1);
    REQUIRE(veh[0]->getRegistrationNumber() == reg_nr);

    std::vector<Vehicle*> emptyVector;
    veh = findVehicle(emptyVector, reg_nr);
    REQUIRE(veh.size() == 0);
  }
  
  unsigned long v_size = saveInVector.size();
  removeVehicle(reg_nr, &saveInVector);
  REQUIRE(saveInVector.size() < v_size);
  
  veh = findVehicle(saveInVector, reg_nr);
  REQUIRE(veh.size() == 0);

  std::string name = "newFile.dat";
  saveFile(name, saveInVector);

  std::ifstream file(name.c_str());
  REQUIRE(file.good());

 

}
  

 
