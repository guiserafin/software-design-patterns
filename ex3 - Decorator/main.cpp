#include <iostream>
#include <string>
#include "headers/Beverage.h"
#include "headers/DarkRoast.h"
#include "headers/Mocha.h"

using namespace std;

int main() {

    Beverage* beverage2 = new DarkRoast();

    cout << beverage2->getDescription() << endl;

    cout << beverage2 << endl;

    beverage2 = new Mocha(beverage2);

    // cout << beverage2->beverage << endl;

    cout << beverage2->getDescription() << endl;


    return 0;
}