#include <iostream>
using namespace std;

class Example{
    static int count;
    public:
        void increment(){
            count += 5;
            show();
        }
        static void show(){
            cout << count << " ";
        }
};

int Example::count = 0;

int main(){
    Example e;
    e.increment();
}