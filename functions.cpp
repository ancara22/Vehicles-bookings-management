#include "vehicles.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>


// Create a new vehicle
// @params,  takes all params for a vehicle creation and a vector to save the results
void addNewVehicle(std::string type, std::string make, std::string model, std::string reg_id, std::string motor, std::string seats, std::string luggage, std::string color, std::string available, std::string price, std::string return_date, std::vector<Vehicle*> *vehiclesBase) {
  
  if(type == "van") {
    vehiclesBase->push_back(new Van(type, make, model, reg_id, motor, seats, luggage, color, price, available, return_date));
    
  } else if(type == "car") {
    std::string nrOfDoors = luggage;
    vehiclesBase->push_back(new Car(type, make, model, reg_id, motor, seats, nrOfDoors, color, price, available, return_date));
      
  } else if(type == "bike") {
    vehiclesBase->push_back(new Motorcycle(type, make, model, reg_id, motor, seats, luggage, color, price, available, return_date));
      
  } else {
    std::cout << "Incorrect data format!";
  }

}


// Print vehicles in long and short format
// @params, a vector vehiclesBase with pointers to Vehicles
void printVehiclesList(std::string oper, std::vector<Vehicle*> vehiclesBase) {
  int idx = 1;
  
  if(oper == "L") {
    for(Vehicle* v: vehiclesBase) {
      v->printVehicleData();
    }
  } else if(oper == "S") {
    for(Vehicle* v: vehiclesBase) {
      std::cout << "\n---------------------------------------------------------------------------------\n\n";
      std::cout << idx  << ".  Type: " << v->getType() << ", Make: " + v->getMake() + ", Model: " + v->getModel() + ", Registration Number: " + v->getRegistrationNumber();
      std::cout << "\n";
      idx++;
    }
  }
 
}



// Read a file, and create vehicles from each line
// @params, string file_path - a path to a file, and a vector* *saveInVector - pointer to a vector where to save the result
void createVehiclesFromFile(std::string file_path, std::vector<Vehicle*> *saveInVector) {
  std::ifstream dataFile;
  dataFile.open (file_path);
  
  std::string line, temp;
  std::string arrLines[10000];
  int i = 0, r;

  //split by lines
  while (std::getline(dataFile, line))  {
    arrLines[i] = line;
    i++;
  }
  
  //Split the line using delimiter
  for(int s = 0; s < i-1; s++) {
    std::string *oneLineArray;
    oneLineArray = new std::string[11];
    std::istringstream istream(arrLines[s]);
    r=0;
    
    while (std::getline(istream, temp, ':'))  {
      oneLineArray[r] = temp;
      r++;
    }
    
    //Create Objects
    std::string type = oneLineArray[0];
    std::string make =  oneLineArray[1];
    std::string model =  oneLineArray[2];
    std::string reg_id =  oneLineArray[7];
    std::string motor =  oneLineArray[4];
    std::string seats =  oneLineArray[5];
    std::string unnic1 =  oneLineArray[6];
    std::string color =  oneLineArray[8];
    std::string available =  oneLineArray[9];
    std::string price =  oneLineArray[3];
    std::string return_date =  oneLineArray[10];

 
    addNewVehicle(type, make, model, reg_id, motor, seats, unnic1, color, available,price, return_date, saveInVector);

    delete[] oneLineArray;
  }
}



// Find a vehicle by registration number
// @params, vector* database - pointer to vehicles database, and a string regNUmber - registration number
std::vector<Vehicle*> findVehicle(std::vector<Vehicle*> database, std::string regNumber) {
  std::vector<Vehicle*> vehicle;
  for(Vehicle* v: database) {
    if(v->getRegistrationNumber() == regNumber){
      vehicle.push_back(v);
      return vehicle;
    }
  }
  return vehicle;
}



// Save file
// @params, fileName - string, and a vector  
void saveFile(std::string fileName, std::vector<Vehicle*> database) {
  std::ofstream file;
  file.open(fileName);
  std::string oneLine = "";
  for(Vehicle* v: database) {
    oneLine = "";
    oneLine += v->getType() + ":" + v->getMake() + ":" + v->getModel() + ":" + v->getPrice() + ":" +
      v->getEngineSize() + ":";

    if(v->getType()=="bike"){
      Motorcycle *bike = (Motorcycle*)v; 
      oneLine +=  bike->getPassengerSeat() + ":" + bike->getLuggageSpace() + ":";
    } else if(v->getType()=="car") {
      Car *car = (Car*)v;
      oneLine += car->getNumberOfSeats() + ":" + car->getNumberOfDoors() + ":";
    } else if(v->getType()=="van") {
      Van *van = (Van*)v;
      oneLine += van->getPassengerSeats() + ":" + van->getLuggageSpace() + ":";
    }

    oneLine += v->getRegistrationNumber() + ":" + v->getColor() + ":" + v->getAvailability() + ":" + v->getReturnDate(); 
    file << oneLine <<std::endl;
  }


  file.close();

}



// Remove a vehicle
// @params, vehicle registration number - string, ppointer to a vector
void removeVehicle(std::string vehicleRegNr, std::vector<Vehicle*> *database) {

  std::vector<Vehicle*> toRemove = findVehicle(*database, vehicleRegNr);

  if(toRemove.size()>0) {
    database->erase(std::remove(database->begin(), database->end(), toRemove[0]));
    std::cout << "\n------------------------------  Vehicle is Removed  -----------------------------\n";
  } else {
    std::cout << "Incorrect Registration Number!!!" << std::endl;
  }

}









