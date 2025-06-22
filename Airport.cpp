#include <iostream>
#include <string>
#include "Airport.h"

using namespace std;

Airport::Airport(const string& name, const string& city) : name_(name), city_(city){};

string Airport::name() const{
    return name_;
}

string Airport::city() const{
    return city_;
}


void Airport::land(const airplane& ap){
    airplanes_.push_back(ap);
}


void Airport::takeoff(const string& id){
    int counter = 0;
    for(const auto& ap : airplanes_){
        if(ap.id == id) break;
        counter++;
    }
    airplanes_.erase(airplanes_.begin() + counter);
}



int Airport::count_airplanes(const string& airline) const{
    int counter = 0;
    for(const auto& ap : airplanes_){
        if(ap.airline == airline) counter++;
    }
    return counter;
}