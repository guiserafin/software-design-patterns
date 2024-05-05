#include "headers/Beverage.h"
#include <iostream>
#include <string>

class HouseBlend: public Beverage {

    public:
        
        HouseBlend() {
            description = "Blend da casa";
        }

        float cost() {
            return 0.89;
        }

};