#include "headers/Beverage.h"
#include <iostream>
#include <string>
#include "headers/DarkRoast.h"


DarkRoast::DarkRoast() {
    description = "Dark Roast";
}

float DarkRoast::cost() {
    return 0.99;
}

