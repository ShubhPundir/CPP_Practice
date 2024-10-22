#include <iostream>
using namespace std;

class Widget {
public:
    // Default constructor
    Widget() : pData(new int(0)) { 
        cout << "Default Ctor" << endl; 
    }

    // Constructor with an integer parameter
    Widget(int i_) : pData(new int(i_)) { 
        cout << "Ctor" << endl; 
    }

    // Move constructor
    Widget(Widget&& rhs) noexcept : pData(rhs.pData) {
        rhs.pData = nullptr;  // Transfer ownership, leave rhs in a valid state
        cout << "Move Ctor" << endl;
    }

    // Move assignment operator
    Widget& operator=(Widget&& rhs) noexcept {
        if (this != &rhs) {
            delete pData;  // Free existing resource
            pData = rhs.pData;  // Transfer ownership
            rhs.pData = nullptr;  // Leave rhs in a valid state
            cout << "Move Assignment" << endl;
        }
        else{
            cout << "Self Move Assignment" << endl;
        }
        return *this;
    }

    // Destructor
    ~Widget() {
        delete pData;  // Clean up the dynamically allocated memory
        cout << "Dtor" << endl;
    }

    // Function to display the value
    void show() const {
        if (pData)
            cout << "Value: " << *pData << endl;
        else
            cout << "No data --> " << endl;
    }

private:
    int* pData;  // Pointer to dynamically allocated int
};

int main() {
    Widget w1;
    w1.show();  // Should show the default value of 0

    Widget w2(10);
    w2.show();  // Should show the value 10

    Widget w3 = std::move(w2);  // Use move constructor
    w3.show();  // Should show the value 10
    w2.show();  // Should show "No data" (w2 was moved from)

    w1 = std::move(w3);  // Use move assignment operator
    w1.show();  // Should show the value 10
    w3.show();  // Should show "No data" (w3 was moved from)
    
    w3 = std::move(w3);
    return 0;
}
