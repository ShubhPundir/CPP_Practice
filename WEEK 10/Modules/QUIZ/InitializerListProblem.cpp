#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

template<typename T>
class Number{
    public:
        Number() {cout << "1" << " ";}
        Number(int n ) { cout << "2"<<" ";}
        Number(initializer_list<int> elems) {cout<<"3"<<" ";}
        Number(int n, initializer_list<int> elems) { cout <<"4"<< " ";}
};

int main(){
    Number<int> n1(10); // 2
    Number<int> n2({10,20,30}); // 3
    Number<int> n3{10,20,30}; // 3
    Number<int> n4 = {10,20,30}; // 3
    Number<int> n5(10, {10,20,30}); // 4
    
}