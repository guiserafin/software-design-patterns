#include <iostream>
#include <string>
#include <CondimentDecorator.h>

using namespace std;


class Whip: public CondimentDecorator {

    public:

        Beverage beverage;

        Whip(Beverage beverage) {
            beverage = beverage;
        }

        string getDescription(){
            return beverage.getDescription() + ", Whip";
        }

        float cost() {
            return beverage.cost() + 0.10;
        }

};