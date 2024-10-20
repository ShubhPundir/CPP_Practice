#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>
using namespace std;

template<typename T>
class MyClass{
    vector<T> elems;
    public: MyClass() : elems({-1}){
        cout << "Default Ctor";
        showElements();
    }
    MyClass(T b) : elems({b}){
        cout << "Parameterized Ctor";
        showElements();
    }
    MyClass(initializer_list<T> init_list) : elems({init_list}){
        cout << "Initializer List Ctor";
        showElements();
    }
    MyClass(int i, initializer_list<T> init_list) : elems(init_list){
        cout << "Mixed Ctor" << i << showElements();
    }
    void showElements(){
        cout << " { ";
        for(auto it=elems.begin(); it != elems.end(); ++it){
            cout << *it << " ";
        }
        cout << "}" <<endl;
    }
};

int main(){
    MyClass<int> obj1;
    MyClass<int> obj_i(500);
    MyClass<int> obj_d = MyClass<int>(512.15);
    MyClass<int> obj_il{1,2,3,4,5};
    MyClass<int> obj_il2 = {1,2,3,4,5};
}