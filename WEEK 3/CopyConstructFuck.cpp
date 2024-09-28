#include <iostream>
using namespace std;

class Rectangle{
    int width, height;
    public:
        Rectangle(int width_=0, int height_=0) : width(width_), height(height_) {
            cout << "ctor ";
        } // LINE-1

    Rectangle(Rectangle &r) : width(r.width), height(r.height){
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
    cout << "R1 done ";
    Rectangle r2 = r1;
    cout << "R2 done ";
    Rectangle *rPtr;
    cout << "rPtr done ";
    Rectangle r3;
    r3 = r2;
    cout << "R3 done ";
    return 0;
}