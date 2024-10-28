struct B{
    virtual void f();
    virtual void g() const;
    virtual void h(char);
    void k();
};

struct D : B{
    void f() override;
    void g() override; // wrong type
    virtual void h(char);
    void k() override;
};
