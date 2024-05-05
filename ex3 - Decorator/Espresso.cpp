#include "headers/Beverage.h"
#include <iostream>
#include <string>

class Espresso: public Beverage {

    public:

        Espresso() {

            description = "Expresso";

        }

        float cost() {
            return 1.99;
        }

};