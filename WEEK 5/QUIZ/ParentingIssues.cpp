#include <iostream>
using namespace std;

int value = 5;

class Parent{
    protected:
        int value;
    public:
        Parent() : value(15) {}
        ~Parent() {}
};

class Child : public Parent{
    protected:
        int value;
    public:
        Child() : value(25) {}
        ~Child() {}

        void display()
        {
            // cout << value << " " << Parent::value << " " << ::value;
            // cout << this->value << " " << Parent::value << " " << ::value;
            // above works

            cout << Child::value << " " << Parent::value << " " << ::value;
        }
};

int main()
{
    Child c;
    c.display();
    return 0;

}