#include <iostream>
#include <functional>
using namespace std;

class MyClass{
    typedef std::function<void (float result)> TCallBack;
    void longRunningFunction(TCallBack callback){
        double result = 2.7;
        callback(result);
    }
    void callback(float result){ cout << result; }
    public:
        void longRunningFunctionAsync(){
            auto callback = std::bind(&MyClass::callback, this, std::placeholders::_1);
            longRunningFunction(callback);
        }
};
int main(){
    MyClass().longRunningFunctionAsync();
}