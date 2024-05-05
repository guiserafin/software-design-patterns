#include "headers/Beverage.h"
#include <iostream>
#include <string>

class Decaf: public Beverage {

    public:

        Decaf() {
            description = "Descafeínado";
        } 

        float cost() {
            return 1.05;
        }

};