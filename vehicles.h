#ifndef _VEHICLES_H_
#define _VEHICLES_H_

#include <string>

class Vehicle {
private:
  std::string type;
  std::string make;
  std::string model;
  std::string registration_number;
  std::string color;
  std::string engine_size;
  std::string price;
  std::string available;
  std::string return_date;
        

public:
  Vehicle(std::string type, std::string make, std::string model, std::string registration_number, std::string engine_size, std::string color, std::string price, std::string available, std::string return_date);
  virtual ~Vehicle();
  std::string getMake();
  std::string getModel();
  std::string getEngineSize();
  std::string getColor();
  std::string getPrice();
  std::string getAvailability();
  std::string getReturnDate();
  std::string getType();
  std::string getRegistrationNumber();
  virtual void printVehicleData()= 0;

};


class Car : public Vehicle {
private: 
  std::string number_of_seats;
  std::string number_of_doors;

public:
  Car(std::string type, std::string make, std::string model, std::string registration_number, std::string engine_size, std::string number_of_seats, std::string number_of_doors, std::string color, std::string price, std::string available, std::string return_date);
  void printVehicleData() override;
  std::string getNumberOfSeats();
  std::string getNumberOfDoors();

};

class Van : public Vehicle {
private:
  std::string passenger_seats;
  std::string luggage_space;

public:
  Van(std::string type, std::string make, std::string model, std::string registration_number, std::string engine_size, std::string passenger_seats, std::string luggage_space, std::string color, std::string price, std::string available, std::string return_date);
  void printVehicleData() override;
  std::string getPassengerSeats();
  std::string getLuggageSpace();

};

class Motorcycle : public Vehicle {
private:
  std::string passenger_seat;
  std::string luggage_space;

public:
  Motorcycle(std::string type, std::string make, std::string model, std::string registration_number, std::string engine_size, std::string  passenger_seat, std::string luggage_space, std::string color, std::string price, std::string available, std::string return_date);
  void printVehicleData() override;
  std::string getPassengerSeat();
  std::string getLuggageSpace();
	
};


#endif
