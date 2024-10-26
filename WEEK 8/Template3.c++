#include <iostream>
#include <cstring>
using namespace std;

template <class T>
class Stack{
    T data[100];
    int top;
    public: 
        Stack() : top(-1) {}
        ~Stack() {}
        void push(const T& item) {data[++top] = item;}
        void pop() { --top;}
        const T& peek() const {return data[top];}
        bool empty() const {return top==-1;}
};

int main(){
    char str[10] = "ABCDE";
    Stack<char> s;

    for(int i = 0; i < strlen(str); i++){
        s.push(str[i]);
    }
    cout << "Reversed String: ";

    while (!s.empty())
    {
        cout << s.peek();
        s.pop();
    }
    
}