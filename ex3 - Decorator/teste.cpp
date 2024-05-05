#include <iostream>
#include <string>

using namespace std;

class Beverage {
public:
    string description;

    virtual string getDescription() {
        return description;
    }

    virtual double cost() = 0;
};

class HouseBlend : public Beverage {
public:
    HouseBlend() {
        description = "House Blend Coffee";
    }

    double cost() override {
        return 0.89;
    }
};

class Espresso : public Beverage {
public:
    Espresso() {
        description = "Espresso";
    }

    double cost() override {
        return 1.99;
    }
};

class Decaf : public Beverage {
public:
    Decaf() {
        description = "Decaf Coffee";
    }

    double cost() override {
        return 1.05;
    }
};

class CondimentDecorator : public Beverage {
public:
    virtual string getDescription() = 0;
};

class Milk : public CondimentDecorator {
public:
    Beverage* beverage;

    Milk(Beverage* beverage) {
        this->beverage = beverage;
    }

    string getDescription() override {
        return beverage->getDescription() + ", Milk";
    }

    double cost() override {
        return 0.10 + beverage->cost();
    }
};

class Mocha : public CondimentDecorator {
public:
    Beverage* beverage;

    Mocha(Beverage* beverage) {
        this->beverage = beverage;
    }

    string getDescription() override {
        return beverage->getDescription() + ", Mocha";
    }

    double cost() override {
        return 0.20 + beverage->cost();
    }
};

class StarbuzzCoffee {
public:
    static void main() {
        Beverage* beverage = new Espresso();
        cout << beverage->getDescription() << " $" << beverage->cost() << endl;

        Beverage* beverage2 = new HouseBlend();
        beverage2 = new Mocha(beverage2);
        beverage2 = new Mocha(beverage2);
        beverage2 = new Milk(beverage2); // Adicionando Milk para demonstração
        cout << beverage2->getDescription() << " $" << beverage2->cost() << endl;

        delete beverage;
        delete beverage2;
    }
};

int main() {
    StarbuzzCoffee::main();
    return 0;
}
