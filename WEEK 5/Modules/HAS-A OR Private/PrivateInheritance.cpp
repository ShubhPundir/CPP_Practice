#include <iostream>
using namespace std;

/*
--> Private inheritance means nothing during software design, only during software
implementation

--> Private inheritance means is-implemented-in-terms of. It is usually infe-
rior to composition, but it makes sense when a derived class needs access to
protected base class members or needs to redefine inherited virtual functions
{ Scott Meyers in Item 32, Effective C++ (3rd. Edition)
*/

class Engine{
    public:
        Engine(int numCylinders): n(numCylinders) {}
        void start() {cout << "VROOOOMM with "<< n << " Cylinders" << endl;}
    private:
        int n;
};

class Car: private Engine{
    public:
        Car() : Engine(8) {}
        // void start() {e.start();}
        using Engine::start;
};

int main(){
    Car c;
    c.start();
}