#include <iostream>

class MyResource{
    char *str = nullptr;
    public:
        // Move: Constructs by moving resource from rvalue reference source (rr)
        MyResource(MyResource&& rr) noexcept : str(rr.str) {
            rr.str = nullptr;
        }
        
        // Move: Assigns by moving resource from rvalue reference source (rr)
        MyResource& operator=(MyResource&& rr) noexcept {
            delete [] str; // Release the current value
            str = rr.str; // Take the value of source rr
            rr.str = nullptr; // Changed but Valid state set for the source
            return *this; // Return the assigned object
        }
};

int main(){

    MyResource r; 
    r = std::move(r);
    return 0;
}