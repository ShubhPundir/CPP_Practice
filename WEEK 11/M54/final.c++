#include <iostream>
struct B{
    virtual void f() const final; // DO NOT OVERRIDE
    virtual void g();
};

struct D : B{
    void f() const; // ERROR
    void g();
}