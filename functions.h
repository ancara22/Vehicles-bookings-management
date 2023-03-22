#ifndef _PARKING_H_
#define _PARKING_H_

void addNewVehicle(std::string type, std::string make, std::string model, std::string reg_id, std::string motor, std::string seats, std::string luggage, std::string color, std::string available, std::string price, std::string return_date, std::vector<Vehicle*> *vehiclesBase);

void printVehiclesList(std::string oper, std::vector<Vehicle*> vehiclesBase);

void createVehiclesFromFile(std::string file_path, std::vector<Vehicle*> *saveInVector);

std::vector<Vehicle*> findVehicle(std::vector<Vehicle*> database, std::string regNumber);

void saveFile(std::string fileName, std::vector<Vehicle*> database);

void removeVehicle(std::string vehicleRegNr, std::vector<Vehicle*> *database);



#endif
