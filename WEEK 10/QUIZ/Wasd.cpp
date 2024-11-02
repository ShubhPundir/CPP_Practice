#include <iostream>
using namespace std;

void show(char* str) {
    // yaba bu baba ooo
    // yaba bi babu boo
    
    // some code
    // lmao
    cout << "function show is very much showing" << endl;
}

template<typename FUNC, typename PARA>
void function(FUNC f, PARA p){
    f(p);
}

int main(){
    char s[15] = "Modern C++"; 
    function(show, s);
    // function(show, 0); // error 
    // function(show, s[4]); // error as it is a char not a char*
    function(show, nullptr);
    return 0;
}