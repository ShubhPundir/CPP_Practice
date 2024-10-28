#include <iostream>
#include <functional>
using namespace std;

int half(int x) { return x/2;}
struct third_t { double operator()(int x) { return x/3.0;}};
struct MyValue { int value; int fifth(){return value/5;}};

int main(){
    std::function<int(int)> fn1 = half;
    std::function<int(int)> fn2 = &half;
    std::function<double(int)> fn3 = third_t();
    std::function<int(int)> fn4 = [](int x){return x/4;};
    std::function<int(int)> fn5 = std::negate<int>();

    cout << "fn1(60) : " << fn1(60) << endl;
    cout << "fn2(60) : " << fn2(60) << endl;
    cout << "fn3(60) : " << fn3(86) << endl;
    cout << "fn4(60) : " << fn4(60) << endl;
    cout << "fn5(60) : " << fn5(60) << endl;

    std::function<int(MyValue&)> value_DM = &MyValue::value; // pointer to a data member
    std::function<int(MyValue&)> fifth_MF = &MyValue::fifth; // pointer to a member function

    MyValue sixty{60};
    cout << "value(sixty) : " << value_DM(sixty) << endl;
    cout << "fifth(sixty) : " << fifth_MF(sixty) << endl;
}