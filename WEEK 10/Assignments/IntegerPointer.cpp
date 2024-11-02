#include <iostream>
#include <vector>
using namespace std;

class Integer { 
    public:
        Integer(){ cout << "Ctor ";}
        Integer(int i) : ip_(new int(i)) { cout << "Param-Ctor ";} 
        Integer(const Integer& n): ip_(new int(*(n.ip_) * 5)){ cout << "C-Ctor ";}    // LINE-1: copy constructor 
        Integer& operator=(const Integer& n) {      // LINE-2: copy assignment 
            cout << "Assign-Ctor ";
            if (this != &n) { 
                delete ip_;  
                ip_ = new int(*(n.ip_) * 10); 
            } 
            return *this;
        }
        ~Integer() { delete ip_; } 
        Integer(Integer&& n): ip_(n.ip_) {
            cout << "Mtor ";
            n.ip_ = nullptr;
        }  // LINE-3: move constructor 
        Integer& operator=(Integer&& d) {        // LINE-4: move assignment 
            cout << "M-Assigntor ";
            if (this != &d) { 
                ip_ = d.ip_; 
                d.ip_ = nullptr; 
            }
            return *this;
        }
        void show(){
            if(ip_ == nullptr)
                std::cout << "moved : ";
            else
                std::cout << *ip_ << " : ";
        }
        private:
            int* ip_ {nullptr};
};

int main(){
    int a = 2;
    // std::cin >> a;
    Integer n1(a); // Param-Ctor
    cout << endl; 
    Integer n2 = n1; // C-Ctor
    cout << endl;
    Integer n3; // Ctor
    cout << endl;
    n3 = n1; // Assign-Ctor
    // n1.show();
    // n2.show();
    // n3.show();
    cout << endl;
    
    Integer n4 = std::move(n1); // Mtor
    Integer n5; // Ctor
    n5 = std::move(n1); // here only null value is moved// M-Assigntor
    // n1.show();
    // n4.show();
    // n5.show();
    return 0;
}