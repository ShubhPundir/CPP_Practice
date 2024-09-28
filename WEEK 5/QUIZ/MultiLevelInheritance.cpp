#include <iostream>
using namespace std;

class Alpha{
    public: 
    // int static counter;
    Alpha(){
        cout << "A ";
        // counter++;
    }
    ~Alpha(){
        cout << "-A ";
    }
};

class Beta : public Alpha{
    public: Beta(){
        cout << "B ";
    }
    ~Beta(){
        cout << "-B ";
    }
};

class Gamma:public Alpha{
    // first of all Alpha constructor is called
    Beta b;
    public: Gamma(){
        cout << "C ";
    }
    ~Gamma(){
        cout << "-C ";
    }
};

// int Alpha::counter = 0;
int main()
{
    Gamma g1;
    // A B A C -C -A -B -A

    // A A B C -C -B -A -A
    return 0; 
}