class C1 {public: void f(){}};
class C2 : public C1 {public: virtual void f() {}};
class C3 : public C2 {public: void g() {}};
class C4 : public C1 {public: virtual void g() {}};