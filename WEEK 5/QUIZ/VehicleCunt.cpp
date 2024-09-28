#include <iostream>
using namespace std;

class Vehicle{
    private:
        int reg_no;
        string type;

    public:
        Vehicle(int reg_no_, string type_) : reg_no(reg_no_), type(type_) {}
        void showDetails()
        {
            cout << reg_no << ":" << type <<":";
        }
};

class Car : public Vehicle{
    private:
        int owner_id;
        string owner_name;

    public:
        Car(int owner_id_, string owner_name_, int reg_no_, string type_) : 
            owner_id(owner_id_), owner_name(owner_name_),Vehicle(reg_no_,type_) {}

        void showDetails(){
            Vehicle::showDetails(); // LINE-1
            cout << owner_id << ":" <<owner_name;
        }
};

int main(){

    Car* carObj = new Car(101,"Rahul",12345,"Sedan");
    // display(carObj); // LINE-2

    carObj->showDetails(); // this is the right way to use a pointer 
    delete carObj;

    return 0;
}