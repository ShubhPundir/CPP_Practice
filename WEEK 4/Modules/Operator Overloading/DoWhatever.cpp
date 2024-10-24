#include <iostream>
using namespace std;
    class MyClass { int data;
    public:
        MyClass(int d) : data(d) { }
        MyClass& operator++() { // Pre-Operator
            data *= 2;
            return *this;
        }
    MyClass operator++(int) { // Post-Operator
        MyClass t(data);
        data /= 3;
        return t;
        }
    void disp() { cout << "Data = " << data << endl; }
};
int main() {
    MyClass obj1(12); obj1.disp();
    MyClass obj2 = obj1++; obj2.disp(); obj1.disp();
    obj2 = ++obj1;
    obj2.disp(); obj1.disp();
}