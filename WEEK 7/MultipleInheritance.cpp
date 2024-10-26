#include <iostream>
using namespace std;

class Base1{
    protected: int i; double data;
    public: Base1(){ cout << "Base1 Ctor " << endl;}
    ~Base1(){cout << "Base1 Dtor"<< endl;}
};

class Base2{
    protected: int j; double data2;
    public: Base2(){ cout << "Base2 Ctor " << endl;}
    ~Base2(){cout << "Base2 Dtor"<< endl;}
};

class Derived: public Base1, public Base2{
    int k;
    using Base1::data;
    public: Derived(){cout << "Derived Ctor" << endl;}
    ~Derived() {cout << "Derived Dtor" << endl;}
    void setData(double data){
        this->data = data;
        cout << "Data set to " << this->data << endl;
    }
};

int main(){
    Derived d;
    // d.data = 3;
    d.setData(3);
}