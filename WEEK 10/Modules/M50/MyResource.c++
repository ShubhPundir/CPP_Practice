#include <iostream>
#include <cstring>
using namespace std;

class MyResource{
    char *str = nullptr;
    public:
        MyResource() : str(nullptr) { } // default ctor

        MyResource(const char* s) : str(strcpy(new char[strlen(s) + 1], s)) {} 

        // Move: Constructs by moving resource from rvalue reference source (rr)
        MyResource(MyResource&& rr) noexcept : str(rr.str) {
            rr.str = nullptr;
        }
        
        // Move: Assigns by moving resource from rvalue reference source (rr)
        MyResource& operator=(MyResource&& rr) noexcept {
            if(this != &rr){
                delete [] str; // Release the current value
                str = rr.str; // Take the value of source rr
                rr.str = nullptr; // Changed but Valid state set for the source
            }
            return *this; // Return the assigned object
        }

        friend ostream& operator<<(ostream& os, const MyResource& r){
            os << r.str;
            return os;
        }
};

int main(){

    MyResource r1("Shubh"); MyResource r2("Pundir");
    cout << r1 << " " << r2<< endl; 
    
    r1 = std::move(r2);

    cout << r1 << " " << r2; 
    return 0;
}