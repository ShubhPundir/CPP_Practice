#include <iostream>
using namespace std;

class Person{
    public:
        Person() {cout <<"Person Constructor" << endl;}
};
class Student : private Person{
    public:
        Student() {cout << "Student Constructor"<< endl;}
};

void eat(const Person& p){
    cout << "Person is eating" << endl;
}
void study(const Student& s){
    cout << "Student is studying" << endl;
}

int main(){
    Person p;
    Student s;

    cout << "Time table started" << endl << endl; 
    // eat(s); // Compiler won't convert a derived class object (Student) 
    // into a Base Object (Person) since the inheritance relationship is private 
    study(s);

    eat(p);
    // study(p); //not possible ever

}