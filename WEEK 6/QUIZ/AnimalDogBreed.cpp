#include <iostream>
using namespace std;

class Animal{
    string type;
    public:
        Animal(string t) : type(t) {}
        void displayType(){ cout << type << " ";}
};

class Dog : public Animal{
    string breed;
    public:
        Dog(string t, string b) : Animal(t), breed(b) {}
        void displayBreed(){ cout << breed << " ";}
};

int main(){
    Dog d1("Mammal", "Labrador");
    Animal *a = &d1;
    a->displayType();
    a->displayBreed(); // ERROR
}