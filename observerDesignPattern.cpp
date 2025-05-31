#include <iostream>
#include <vector>
using namespace std;


//Iplementing observer design pattern
// It has Subject and Observers: Change in state of subject causes change in observers

//Observers interface
class Observer {
    public:
    
    virtual void update(float t, float h) = 0;
};

//Subject interface : not necessarily required as only one subject is present

//Concrete Subject
class WeatherStation {
    private:
    
    float temp;
    float humidity;
    vector<Observer*> observers;
    
    public:
    
    void registerObserver(Observer* obs) {
        observers.push_back(obs);
    }
    
    
    void notifyObservers() {
        for(obs: observers) {
            obs->update(temp, humidity);
        }
    }
    
    void setValues(float t, float h) {
        temp = t;
        humidity = h;
        notifyObservers();
    }
};

//Concrete Observers
class Display : public Observer {
    private:
    
    float temp;
    float humidity;
    
    public:
    
    void update(float t, float h) override {
        temp = t;
        humidity = h;
        cout << "Temperature is: " << temp << endl;
        cout << "Humidity is :" << humidity << endl;
    }
};

//Concrete Observers
class Display2 : public Observer {
    private:
    
    float temp;
    float humidity;
    
    public:
    
    void update(float t, float h) override {
        temp = t;
        humidity = h;
        cout << "Temperature2 is: " << temp << endl;
        cout << "Humidity2 is :" << humidity << endl;
    }
};


//main function to test
int main() {
    WeatherStation* ws = new WeatherStation();
    
    Observer* obs1 = new Display();
    Observer* obs2 = new Display2();
    
    ws->registerObserver(obs1);
    ws->registerObserver(obs2);
    
    ws->setValues(2.0, 3.0);
}


