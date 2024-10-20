#include <initializer_list>
#include <iostream>
#include <vector>
using namespace std;

class Widget{
    public:
        Widget(initializer_list<int> init_list){
            cout << "Initializer List" << endl;
        }
        Widget(int a, int b, int c){
            cout << "Arguments passed" << endl;
        }
};

int main(){
    Widget w1(1,2.0,3.0);
    // Widget w2{1,2.0,3}; // error
    Widget w3{1,2,3};
    Widget w4({4,5,6});
}