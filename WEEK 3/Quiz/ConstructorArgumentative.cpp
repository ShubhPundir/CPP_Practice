#include <iostream>
using namespace std;

class Sample{
    int x,y,z;
    public:
        Sample(int val=0) : z(++val), y(val++), x(++val) {}
        // here the memberFunctions get initialized the order they were created
        // x = ++5 = 6
        // y = 6++ = 6
        // z = ++ 7 = 8
    void display(){
        cout << "x "<< x <<  " y " << y << " z "<< z;
    }
};

int main()
{
    Sample obj(5);
    obj.display();
    return 0;
}