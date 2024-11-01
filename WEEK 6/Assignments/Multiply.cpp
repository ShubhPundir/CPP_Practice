#include <iostream>
using namespace std;

class myClass1{
    int data1;
    public:
        myClass1(int d) : data1(d) {}
        virtual void print();                     //LINE-1
        friend void Mul(myClass1&, myClass1&);    //LINE-2
};

class myClass2 : public myClass1{
    int data2;
    public:
        myClass2(int d1, int d2) : myClass1(d1), data2(d2) {}
        void print(){
            myClass1::print();                    //LINE-3
            cout << data2 << " ";
        }
};
void myClass1::print(){ cout << data1 << " "; }

void Mul(myClass1 &m1, myClass1 &m2){
    m1.data1 = m1.data1 * m2.data1;
}

int main(){
    int m = 12, n = 3;
    // cin >> m >> n;
    myClass1 *t1 = new myClass2(m,n);
    myClass1 *t2 = new myClass1(m);
    Mul(*t1, *t2);
    t1->print();
    return 0;
}