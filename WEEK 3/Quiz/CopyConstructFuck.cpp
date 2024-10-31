#include <iostream>
using namespace std;

class Rectangle{
    int width, height;
    public:
        Rectangle(int width_=0, int height_=0) : width(width_), height(height_) {
            cout << "ctor ";
        } // LINE-1

        Rectangle(Rectangle& r) : width(r.width), height(r.height){
            cout << "c-ctor ";
        } // LINE-2

        Rectangle& operator=(Rectangle r) {
            width = r.width;
            height = r.height;
            cout << "c-assign ";
            return *this;
        } // LINE-3
};

int main()
{
    Rectangle r1(30,40);
    cout << "R1-done " << endl;
    Rectangle r2 = r1;
    cout << "R2-done " << endl;
    Rectangle *rPtr; // no constructor called as it is just a pointer and no object has been created
    cout << "rPtr-done " << endl;
    Rectangle r3; // ctor
    cout << "Hello1 ";
    r3 = r2; // c-tor c-assign

    /*Here, r3 is being assigned the values of r2.
    First, the copy constructor is called to make a copy of r2,
    which outputs c-ctor.
    Then, the copy assignment operator (LINE-3) is called to assign the copied object to r3,
    which outputs c-assign.*/
    cout << "Hello2 ";
    cout << "R3-done " << endl;
    return 0;
    /*
        ctor R1-done 
        c-ctor R2-done 
        rPtr-done 
        ctor Hello1 c-ctor c-assign Hello2 R3-done 
    */
}