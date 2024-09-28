#include <iostream>
using namespace std;

int gloablVar = 5;

class MyClass{
    int memberVar;
    public: 
        MyClass(int memberVar_ = 0 ) : memberVar(++memberVar_){
            ++gloablVar; // LINE-1
        }
        ~MyClass(){
            memberVar = 0;
            gloablVar = 0;
        }
        void display(){
            cout << "MemberVar: " << memberVar << " "<< "Global Var: " << gloablVar;
        }
};

void function(){
    MyClass obj;
    obj.display();
    cout << endl;
}
int main()
{
    MyClass obj;
    function();
    obj.display();
    return 0;
}