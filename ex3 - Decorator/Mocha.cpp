#include <iostream>
#include <string>
#include "headers/Mocha.h"

using namespace std;


Mocha::Mocha(Beverage * beverage) {

    cout << beverage << endl;

    this->beverage = beverage;
    cout << this->beverage << endl;
}

string Mocha::getDescription(){
    return beverage->getDescription() + ", Mocha";
}

float Mocha::cost() {
    return beverage->cost() + 0.15;
}
