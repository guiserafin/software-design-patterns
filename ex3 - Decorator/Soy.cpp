#include <iostream>
#include <string>
#include <CondimentDecorator.h>

using namespace std;


class Soy: public CondimentDecorator {

    public:

        Beverage beverage;

        Soy(Beverage beverage) {
            beverage = beverage;
        }

        string getDescription(){
            return beverage.getDescription() + ", Soy";
        }

        float cost() {
            return beverage.cost() + 0.15;
        }

};