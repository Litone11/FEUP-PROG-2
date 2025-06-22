#ifndef TAXI_H
#define TAXI_H

#include "car.h"
#include <iostream>
#include <string>

class Taxi : private Car {
public:
    Taxi(std::string driver, int fuel, int rate)
        : Car(driver, fuel), rate(rate), profit(0) {}

    bool drive(int miles) {
        if (!Car::drive(miles)) return false;
        profit += miles * rate;
        return true;
    }

    void refuel(int fuel) {
        Car::refuel(fuel);
    }

    void print() {
        std::cout << driver << "'s taxi: "
                  << miles << " miles driven, "
                  << fuel << " gallons left, "
                  << "made " << profit << "$" << std::endl;
    }

private:
    int rate;
    int profit;
};

#endif // TAXI_H