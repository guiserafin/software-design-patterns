#include <iostream>
#include <string>
#include <list>

using namespace std;

class Observer{
    public:
        virtual void update() = 0;
};


class Subject: public Observer{

    public:
        // Observer observers[10];
        list<Observer*> observers;

        virtual void registerObserver(Observer * observer) = 0;
        virtual void removeObserver(Observer * observer) = 0;
        virtual void notifyObservers() = 0;
        // for (int i = 0; i < sizeof(observers); i++) {
        //         observers[i].update();
        //     }
};


class WeatherData: public Subject{

    private:

        double temperature;
        double humidity;
        double pressure;

    public:

        void registerObserver(Observer * observer) override{
            observers.push_back(observer);
        }

        void removeObserver(Observer * observer) override{
            observers.remove(observer);
        }

        double getHumidity(){
            return humidity;
        }

        double getTemperature(){
            return temperature;
        }

        double getPressure(){
            return pressure;
        }

        bool measurementsChanged(){
            return true;
        }

};

class DisplayElement{
    virtual void display() = 0;
};

class CurrentConditionsDisplay: public WeatherData, DisplayElement{

    WeatherData * subject;

    void update() override{

    }

    void display() override{
        cout << getHumidity() << endl;
        cout << getPressure() << endl;
        cout << getTemperature() << endl;
    }


};

class StatisticsDisplay: public Observer, public DisplayElement{

    WeatherData * subject;

    void update() override{

    }

    void display() override{

    }

};

class ThirdPartyDisplay: public Observer, DisplayElement{

    WeatherData * subject;
    void update() override{

    }

    void display() override{

    }
};

class ForecastDisplay: public Observer, DisplayElement{

    WeatherData * subject;

    void update() override{

    }

    void display() override{

    }

};

int main(){

    cout << "Hello world" << endl;

    return 0;
}