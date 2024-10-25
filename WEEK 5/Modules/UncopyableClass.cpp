#include <iostream>
using namespace std;

class Uncopyable{
    protected:
        Uncopyable() { }
        ~Uncopyable() { }
    private:
        Uncopyable(const Uncopyable&);
        Uncopyable& operator=(const Uncopyable&);
};

class MyClass: private Uncopyable{
};

int main(){
    MyClass test1, test2;
    // MyClass test3(test1); error
    // test2 = test1;//error
}