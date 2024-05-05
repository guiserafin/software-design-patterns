#ifndef CONDIMENTDECORATOR_H
#define CONDIMENTDECORATOR_H

#include <iostream>
#include <string>
#include "Beverage.h"

class CondimentDecorator: public Beverage {

    public:
        virtual string getDescription() = 0;

};

#endif