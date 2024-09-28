#include <iostream>
using namespace std;

class Vehicle{
    public: Vehicle(){
        cout << "Vehicle created ";
    }
    ~Vehicle(){
        cout << "Vehicle destroyed ";
    }
};

class Car: public Vehicle{
    public: Car(){
        cout << "Car created ";
    }
    ~Car(){
        cout << "Car destroyed ";
    }
};
class Bike: public Vehicle{
    public: Bike(){
        cout << "Bike created ";
    }
    ~Bike(){
        cout << "Bike destroyed ";
    }
};
class SportsCar : public Car{
    Bike b;
    public: SportsCar(){
        cout << "SportsCar created ";
    }
    ~SportsCar(){
        cout << "SportsCar destroyed ";
    }
};

int main(){
    SportsCar sc;
    return 0;

}