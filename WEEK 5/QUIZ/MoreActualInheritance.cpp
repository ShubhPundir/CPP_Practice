#include <iostream>
using namespace std;

class X{
    public:
        int x;
};

class Y : protected X{
    public:
        int y;
};

class Z : public Y{
    public:
        int z;
    
        Z(int x_,int y_, int z_){
            x = x_; // LINE-1 --> ERROR
            y = y_;
            z = z_;
        }
};

int main(){
    // Z zObj(10,20,30);
    // cout << zObj.x << " "; // LINE-2
    // cout << zObj.y << " ";
    // cout << zObj.z << " ";

    Y yObj(10,20);
    cout << yObj.x << " "; // LINE-2
    cout << yObj.y << " ";


}