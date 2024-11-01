#include <iostream>
using namespace std;

template<typename T>
class SPtr{
    private: T* ptr;
    public:
        explicit SPtr(T* ptr_=nullptr) { 
            cout << "SPtr::ctor(), ";
            ptr = ptr_;
       }
       ~SPtr() { delete ptr;}
       T& operator*(){
            cout << "SPtr::operator*(), ";
            return *ptr;
       }
       T* operator->(){
            cout << "SPtr::operator->(), ";
            return ptr;
       }
};

class Test{
    public:
        Test() {cout << "Test::ctor(), ";}
        void fun() {cout << "Test::fun(), ";}
};

int main(){
    SPtr<Test> sp(new Test());
    (*sp).fun();
}