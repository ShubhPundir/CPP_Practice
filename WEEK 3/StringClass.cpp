#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class String{
    char *str; size_t len;
    public: 
        String(char *s) : str(strdup(s)) , len(strlen(str)){
            cout << "Ctor ";
            print();
        }
        ~String(){
            cout << "Dtor ";
            print();
        }
        void print(){
            cout << "(" << str << ": " << len << ")" << endl;
        }
};

int main(){
    String s = "Shubh";
    s.print();
}