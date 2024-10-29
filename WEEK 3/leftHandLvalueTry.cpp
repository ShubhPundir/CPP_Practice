#include <iostream>
using namespace std;

class Car{
    int id;
    string model;
    Car(){} // LINE-1
    public:
    Car(int id_, string model_) : id(id_), model(model_) {}
    Car& updateCar(Car &c){
        this->id = c.id;
        this->model = c.model;
        return *this;
    } // LINE-2
    void display()
    {
        cout << id << ", " << model << endl;
    }
};

int main()
{
    Car car1(101, "Sedan");
    Car car2(202, "SUV");
    car1.updateCar(car2) = Car(303, "WOWOWHOOO"); // Corrected the function call
    car1.display();
    return 0;
}
