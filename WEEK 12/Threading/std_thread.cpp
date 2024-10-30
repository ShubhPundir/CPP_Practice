#include <iostream>
#include <thread>
#include <utility>
#include <chrono>
using namespace std;

void f1(int n){
    for(int i=0; i<5; i++){
        cout << "Thread 1 executing\n";
        ++n;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
void f2(int& n){
    for(int i=0; i<5; i++){
        cout << "Thread 2 executing\n";
        ++n;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

class foo{
    public: int n = 0;
    void bar(){
        for(int i=0; i<5; i++){
            cout << "Thread 3 excecuting\n";
            ++n;
            std::this_thread::sleep_for(chrono::milliseconds(10));
        }
    }
};
class baz{
    public: int n = 0;
    void operator()(){
        for(int i=0; i<5; i++){
            cout << "Thread 4 executing\n";
            ++n;
            std::this_thread::sleep_for(chrono::milliseconds(10));
        }
    }
};

int main(){
    int n = 0; foo f; baz b;
    
    // t1 is non-executing thread
    thread t1; cout << "t1 = " << t1.get_id() << endl;
    
    // pass by value
    thread t2(f1, n+1); cout << "t2 = " << t2.get_id() << endl;
    
    // pass by reference
    thread t3(f2, ref(n)); cout << "t3 = " << t3.get_id() << endl;
    
    // t4 is now running f2(). t3 is no longer a thread
    thread t4(move(t3)); cout << "t4 = " << t4.get_id() << endl;
    
    // t5 runs foo::bar() on object f
    thread t5(&foo::bar, &f); cout << "t5 = " << t5.get_id() << endl;
    // &foo::bar --> pointer to a member function bar of foo
    // &f --> address of object f passed as reference
    
    // t6 runs baz::operator() on a copy of object b
    thread t6(b); cout << "t6 = " << t6.get_id() << endl;

    t2.join(); t4.join(); t5.join(); t6.join();

    cout << "Final n: " << n << endl; // 5
    cout << "Final f.n: " << f.n << endl; // 5
    cout << "Final b.n: " << b.n << endl; // 0
    // can reflect 5 if thread t6(ref(b));
    // OR
    // thread t6([&b](){b();});

    // CAN'T OASS thread t6(&b)
    /*
        Using &b Directly: You can't pass &b directly because it 
        refers to a member function pointer, 
        and the thread constructor needs a callable type.
    */

}