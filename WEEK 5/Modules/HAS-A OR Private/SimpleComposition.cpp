#include <iostream>
using namespace std;

class Engine{
    public:
        Engine(int numCylinders): n(numCylinders) {}
        void start() {cout << "VROOOOMM with "<< n << " Cylinders" << endl;}
    private:
        int n;
};

class Car{
    public:
        Car() : e(8) {}
        void start() {e.start();}
    private:
        Engine e;
};

int main(){
    Car c;
    c.start();
} 