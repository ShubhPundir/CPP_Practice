#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int main()
{
    char str[12] = "ABCDEFGHIJK";

    // cout << strlen(str); // OOF this is 11, despite the char array allocation of 12, STRLEN focuses on the contents over the initialzed storage 
    stack<char> stack1, stack2;
    int i;

    for(i=0; i< strlen(str)/2; i++)
    {
        stack1.push(str[i]);
    }

    for(i=i-1; i< strlen(str); i++)
    {
        stack2.push(str[i]);
    }

    // cout << stack2.size();

    while(!stack1.empty())
    {
        stack2.push(stack1.top());
        stack1.pop();
    }

    while(!stack2.empty())
    {
        cout << stack2.top();
        stack2.pop();
    }
    return 0;
}
