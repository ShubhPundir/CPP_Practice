#include <iostream>
using namespace std;

class myClass{
    int priMem_;
    mutable int mPriMem_= -4; 
    public: int pubMem_;
    myClass(int pri,int pub) : priMem_(pri), pubMem_(pub){}

    int getMember() const {return priMem_;}
    void setMember(int i) {
        priMem_ = i; // not possible even if setMember() is declared with const 
        // as data members of a constant object cannot be changed
        cout << "Setting nothing fucka" <<endl;
    }
    
    void setMemberMutable(int i) const {
        mPriMem_ = i; // not possible even if setMember() is declared with const 
        // as data members of a constant object cannot be changed
        cout << "Setting nothing fucka" <<endl;
    }
    void print() const{cout << priMem_ << " "<< pubMem_ << " "<< mPriMem_ << endl;}
};
int main()
{
    myClass a(1,2);
    cout << a.getMember() <<endl;
    a.setMember(4);
    a.setMemberMutable(4);
    a.print();
    cout << "-------------------------------------------" << endl;

    const myClass b(11,21);

    cout << b.getMember() <<endl;
    // b.setMember(4);
    b.setMemberMutable(4);
    b.print();
    return 0;
}