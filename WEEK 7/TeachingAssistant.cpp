#include <iostream>
using namespace std;

class Person {
    public: 
        // Person() {cout << "Person::Person()" << endl;}
        Person(int x) { cout << "Person::Person(int)" << endl; }
};

class Faculty : virtual public Person {
    public: 
        Faculty(int x) : Person(x) { cout << "Faculty::Faculty(int)" << endl; }
};

class Student : virtual public Person {
    public: 
        Student(int x) : Person(x) { cout << "Student::Student(int)" << endl; }
};
/*
The Person constructor needs to be explicitly called in the TeachingAssistant constructor
initialization list. Otherwise, it tries to call a default constructor Person::Person(), 
which doesn't exist (only Person::Person(int) is defined).*/
class TeachingAssistant : public Student, public Faculty {
    public: 
        TeachingAssistant(int x) : Person(x), Student(x), Faculty(x) { 
            cout << "TeachingAssistant::TeachingAssistant(int)" << endl; 
        }
};
int main() {
    TeachingAssistant ta(1);
}

/*
Virtual Inheritance: The keyword virtual is added to both Faculty and Student 
in their inheritance of Person. This ensures that Person is only constructed once,
regardless of how many times it is inherited.

Constructor of TeachingAssistant: Now, since Person is a virtual base class, it must be directly initialized by TeachingAssistant. So, Person(x) is explicitly included in the initialization list of TeachingAssistant.
*/