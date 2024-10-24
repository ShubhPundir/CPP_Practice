#include <iostream>
using namespace std;

class MyClass{
    int data;
    public:
        MyClass(int i) : data(i) {}
        friend void display(const MyClass&);
};

void display(const MyClass& a){
    cout << "data " << a.data <<endl;
}
int main(){
    MyClass obj(10);
    display(obj);
}