#include <iostream>
using namespace std;

class B{
    protected: // does not work wtih private: 
        int data_;
    public:
        B(int d=0) : data_(d) { }
        void Print() {cout << "B Object: " << data_ << endl;}
        friend ostream& operator<<(ostream& os, const B& b){
            os << "B object: " << b.data_ << endl;
            return os;
        }
};

class D : public B{
    int info_;
    public:
        D(int d, int i) : B(d), info_(i) { }
        void Print() { cout << "D Object: " << data_ << ", " << info_ << endl;}
        friend ostream& operator<<(ostream& os, const D& d){
            os << "D object: " << d.data_ << ", " << d.info_ << endl;
            return os;
        }
};

int main(){
    B b(0);
    D d(1,2);

    // b.data_ = 5;

    // b.Print();
    // d.Print();

    cout << b  << d;
}