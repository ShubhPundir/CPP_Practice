#include <iostream>
using namespace std;

class myClass{
    int priMem_;
    public: int pubMem_;
    myClass(int pri,int pub) : priMem_(pri), pubMem_(pub){}

    int getMember() const {return priMem_;}
    void setMember(int i) {
        priMem_ = i;
        cout << "Setting nothing fucka" <<endl;
    }
    void print() const{cout << priMem_ << " "<< pubMem_ <<endl;}
};
int main()
{
    myClass a(1,2);
    cout << a.getMember() <<endl;
    a.setMember(4);
    a.print();

    const myClass b(11,21);

    cout << b.getMember() <<endl;
    // b.setMember(4);
    b.print();
    return 0;
}