#include <iostream>
using namespace std;

struct trace{
    int i;
    trace() : i(0) {cout << "construct"<<endl;}
    trace(trace const& c) : i(c.i) {cout << "copy construct"<<endl;}
    ~trace()  {cout << "destroy"<<endl;}
    trace& operator=(trace& t) {
        cout << "assign"<<endl;
        if(this != &t)
            i = t.i;
        return*this;
    }
};

int main(){
    int i = 2;
    {
        trace t;
        int i = 8;
        auto m1 = [=](){return i/2;};
    }
    {
        trace t;
        auto m1 = [=](){int i = t.i;};
        cout << "---make copy---" << endl;
        auto m2 = m1;
    }
    {
        trace t;
        auto m1 =[&](){i = t.i;};
        cout <<"---make copy---" << endl;
        auto m2 = m1;
    }
}