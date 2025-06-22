#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "Floatable.h"
#include <iostream>
#include <string>

class Submarine : public Floatable{

    public: 
    Submarine(int id, const double mass, std::string captain) : Floatable(id, mass), captain_(captain){};
    
    ~Submarine() override = default;

    std::string captain()const{
        return captain_;
    }

    double buoyancy() const override{
        return mass()*9.81*1025.0;
    }

    private:
    std::string captain_;

};

#endif