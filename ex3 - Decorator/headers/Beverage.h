#ifndef BEVERAGE_H
#define BEVERAGE_H

#include <iostream>
#include <string>

using namespace std;

class Beverage{

    public:
        string description;
        string getDescription() {
            return description;
        }
        virtual float cost() = 0;
};

#endif