#include "vehicles.h"
#include <string>
#include <iostream>


Vehicle::Vehicle(std::string type, std::string make, std::string model, std::string registration_number, std::string engine_size, std::string color, std::string price, std::string available, std::string return_date) {
        this->type = type;
        this->make = make;
        this->model = model;
        this->registration_number = registration_number;
        this->color = color;
        this->price = price;
        this->engine_size = engine_size;
	this->return_date = return_date;
	this->available = available;
}

Vehicle::~Vehicle() { }


Car::Car(std::string type, std::string make, std::string model, std::string registration_number, std::string engine_size, std::string number_of_seats, std::string number_of_doors, std::string color, std::string price, std::string available, std::string return_date) : Vehicle(type, make, model, registration_number, engine_size, color, price, available, return_date)  {
        this->number_of_seats = number_of_seats;
        this->number_of_doors = number_of_doors;

}

Van::Van(std::string type, std::string make, std::string model, std::string registration_number, std::string engine_size, std::string passenger_seats, std::string luggage_space, std::string color, std::string price, std::string available, std::string return_date) : Vehicle(type, make, model, registration_number, engine_size, color, price, available, return_date) {
        this->passenger_seats = passenger_seats;
        this->luggage_space = luggage_space;

}

Motorcycle::Motorcycle(std::string type, std::string make, std::string model, std::string registration_number, std::string engine_size, std::string passenger_seat, std::string luggage_space, std::string color, std::string price, std::string available, std::string return_date) : Vehicle(type, make, model, registration_number, engine_size, color, price, available, return_date) {
        this->passenger_seat = passenger_seat;
        this->luggage_space = luggage_space;
}


std::string Vehicle::getEngineSize() {
    return this->engine_size;
}

std::string Vehicle::getColor() {
    return this->color;
}

std::string Vehicle::getMake() {
    return this->make;
}

std::string Vehicle::getModel() {
    return this->model;
}

std::string Vehicle::getPrice() {
    return this->price;
}

std::string Vehicle::getAvailability() {
    return this->available;
}

std::string Vehicle::getReturnDate() {
    return this->return_date;
}

std::string Vehicle::getType() {
    return this->type;
}

std::string Vehicle::getRegistrationNumber() {
    return this->registration_number;
}

std::string Car::getNumberOfSeats() {
    return this->number_of_seats;
}

std::string Car::getNumberOfDoors() {
    return this->number_of_doors;
}


std::string  Motorcycle::getPassengerSeat() {
    return this->passenger_seat;
}

std::string  Motorcycle::getLuggageSpace() {
    return this->luggage_space;
}


std::string Van::getPassengerSeats() {
    return this->passenger_seats;
}

std::string Van::getLuggageSpace() {
    return this->luggage_space;
}


void Car::printVehicleData() {
  std::cout << "\n\n_________________________________________________________________________" << std::endl;
  std::cout << "Type: " << this->getType() << ", "<< "Make: " + this->getMake() + ", Model: " + this->getModel() + ", Registration Number: " + this->getRegistrationNumber() << std::endl;
  std::cout << "Engine size: " << this->getEngineSize() << " (litres)" << ", Color: " << this->getColor() << std::endl;
  std::cout << "Number of seats: " << this->getNumberOfSeats() << ", Number of doors: " << this->getNumberOfDoors() << std::endl;
  std::cout << std::endl;
  std::cout << "Price per day: " << this->getPrice() << ", Available: " << this->getAvailability() << std::endl;
  std::cout << "Return date: " << this->getReturnDate() << std::endl;    
}


void Van::printVehicleData() {
  std::cout << "\n\n_________________________________________________________________________" << std::endl;
  std::cout << "Type: "  << this->getType() << ", "<< "Make: " + this->getMake() + ", Model: " + this->getModel() + ", Registration Number: " + this->getRegistrationNumber() << std::endl;
  std::cout << "Engine size: " << this->getEngineSize() << " (litres)" << ", Color: " << this->getColor() << std::endl;
  std::cout << "Number of seats: " << this->getPassengerSeats() << ", Luggage space: " << this->getLuggageSpace() << std::endl;
  std::cout << std::endl;
  std::cout << "Price per day: " << this->getPrice() << ", Available: " << this->getAvailability() << std::endl;
  std::cout << "Return date: " << this->getReturnDate() << std::endl;
}


void Motorcycle::printVehicleData() {
  std::cout << "\n\n_________________________________________________________________________" << std::endl;
  std::cout << "Type: " << this->getType() << ", "<< "Make: " + this->getMake() + ", Model: " + this->getModel() + ", Registration Number: " + this->getRegistrationNumber() << std::endl;
  std::cout << "Engine size: " << this->getEngineSize() << "(cm3)" << ", Color: " << this->getColor() << std::endl;
  std::cout << "Passenger seat: " << this->getPassengerSeat() << ", Luggage space: " << this->getLuggageSpace() << std::endl;
  std::cout << std::endl;
  std::cout << "Price per day: " << this->getPrice() << ", Available: " << this->getAvailability() << std::endl;
  std::cout << "Return date: " << this->getReturnDate() << std::endl; 
}
