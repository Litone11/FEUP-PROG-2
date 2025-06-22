#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

class Car {
public:
  Car(std::string driver, int fuel) : driver(driver), fuel(fuel) {}

  // returns true if successful, false if not enough fuel
  bool drive(int miles) {
    if (miles > fuel) return false;

    this->miles += miles;
    this->fuel -= miles;
    return true;
  }

  void refuel(int fuel) {
    this->fuel += fuel;
  }

  void print() const {
    std::cout << driver << "'s car: " << miles << " miles driven, " << fuel << " gallons left\n";
  }

protected:
  std::string driver;
  int miles;
  int fuel;
};

#endif // CAR_H