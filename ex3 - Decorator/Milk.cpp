#include <iostream>
#include <string>
#include <CondimentDecorator.h>

using namespace std;


class Milk: public CondimentDecorator {

    public:

        Beverage beverage;

        Milk(Beverage beverage) {
            beverage = beverage;
        }

        string getDescription(){
            return beverage.getDescription() + ", Milk";
        }

        float cost() {
            return beverage.cost() + 0.20;
        }

};