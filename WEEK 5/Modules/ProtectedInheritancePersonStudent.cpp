#include <iostream>
using namespace std;

class Person {
public:
    Person() { cout << "Person Constructor" << endl; }
    void introduce() const { cout << "I am a Person." << endl; }
};

class Student : protected Person { // Protected inheritance
public:
    Student() { cout << "Student Constructor" << endl; }

    void introduceStudent() const {
        introduce(); // Accessing Person's public method
        cout << "I am a Student." << endl;
    }
};

void eat(const Person& p) {
    cout << "Person is eating." << endl;
}

void study(const Student& s) {
    cout << "Student is studying." << endl;
}

int main() {
    Person p;           // Creates a Person object
    Student s;         // Creates a Student object (calls Person's constructor)

    cout << "Time table started" << endl << endl; 

    // eat(s); // Compiler error: cannot convert derived class object (Student) into a base class object (Person)
    study(s); // This works since study expects a Student object

    eat(p); // This works as p is a Person object
    // s.introduce(); // Compiler error: cannot access introduce() because it's protected

    s.introduceStudent(); // Calls the method to introduce Student
    // s.Person::introduce(); // ERROR
    return 0;
}
