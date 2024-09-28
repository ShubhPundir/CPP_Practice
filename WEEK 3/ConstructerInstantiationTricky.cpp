#include <iostream>
using namespace std;


class Example{
    int x;
    public:
        Example(int x_=0) : x(x_){
            cout << "Constructor: " << x << " ";

        }
        ~Example() {
            cout << "Destructor: " << x << " "; 
        }
};

Example globalObj(50); // LINE-1

int main(){
    Example *pExample = new Example(20); // LINE-2
    Example localObj1(30); // LINE-3
    
    {

        Example localObj2(40); // LINE-4
        delete pExample; // LINE-5
    } // LINE-6

    return 0;
} // LINE-7