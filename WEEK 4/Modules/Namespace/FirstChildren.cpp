#include <iostream>
using namespace std;

namespace MyNameSpace{
    int myData;
    void myFunction(){
        cout << "MyNameSpace myFunction" << endl;
    }
    class MyClass{
        int data;
        public:
            MyClass(int d) : data(d) { }
            void display() { cout << "MyClass data = " << data << endl;}
    };
}

int main(){
    MyNameSpace::myData = 10;
    cout << "MyNameSpace::myData = " << MyNameSpace::myData << endl;

    MyNameSpace::myFunction();

    MyNameSpace::MyClass obj(100);
    obj.display();
}