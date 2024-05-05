#ifndef MOCHA_H
#define MOCHA_H

#include <iostream>
#include <string>
#include "CondimentDecorator.h"

using namespace std;


class Mocha: public CondimentDecorator {

    public:

        Beverage* beverage;

        Mocha(Beverage* beverage);

        string getDescription() override;

        float cost() override;

};

#endif