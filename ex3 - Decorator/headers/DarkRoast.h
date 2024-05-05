#ifndef DARKROAST_H
#define DARKROAST_H

#include <iostream>
#include <string>
// #include "Beverage.h"

using namespace std;

class DarkRoast : public Beverage{

    public:

        DarkRoast();
        float cost() override;
};

#endif