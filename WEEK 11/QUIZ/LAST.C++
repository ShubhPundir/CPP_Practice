#include <iostream>
#include <string>
using namespace std;

class intClass{
    private: bool d1; string d2;
    public:
        intClass(bool data) : d1(data) {}
        intClass(string data) : d2(data) {}
        
        explicit operator bool const(){
            if(d2 == "")
                return d1 == false ? 0 : 1;
            else
                return d2 == "true" ? 1 : d2 == "false" ? 0 : -1;
        }
};

int main(){
    string v = "false";
    intClass i1(true);
    intClass i2(v);

    cout << i1 << endl; // LINE-1 ERROR
    cout << bool(i2) << endl; // LINE-2
    cout << static_cast<bool>(i1) << endl; // LINE-3
    cout << (bool)i2 << endl; // LINE-4
}