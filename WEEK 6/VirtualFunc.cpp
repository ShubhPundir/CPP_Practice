using namespace std;
class B { public:
    void n () {}
    virtual void f ( ) { }
};
class D : public B { public:
    void n () {}
    virtual void f ( ) { }
};
int main() {
    B d;
    D d;

    B *p;
    p = &b; p->f(); // B::f();
            p->n(); // B::f();


    // UPCASTING
    p = &d; p->f(); // D::f();
            p->n(); // B::f();

}