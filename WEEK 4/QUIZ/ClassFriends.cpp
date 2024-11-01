#include <iostream>
using namespace std;

class Beta;

class Alpha{
    int x = 15;
    friend class Beta;
    // class friend Beta;
};

class Beta{
    public:
        int increase(Alpha& a){
            return (a.x + 5);
        }
};

int main(){
    Alpha a1;
    Beta b1;
    int x = b1.increase(a1);
    cout << x;
}