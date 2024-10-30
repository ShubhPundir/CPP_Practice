#include <iostream>
using namespace std;

class MyClass{};

void loseOwnership(){
    MyClass *p = new MyClass; // Create ownership
    cout << p << endl;
    p = 0; // lose ownership
    cout << p <<endl;
}

/*
    The memory pointed to by q (and therefore p as well) is deallocated. 
    p and q are now dangling pointers, 
    meaning they still contain the address of the deallocated memory, 
    but the memory itself is no longer valid.
*/
void doubleDeletion(){
    try{
        MyClass *p = new MyClass; // Create ownership
        MyClass *q = p;
        cout << p << " " << q << endl;
        delete q;
        cout << p << " " << q << endl;
        delete p;
    } catch(const exception& e){
        cerr << "Exception occured: " << e.what() << endl;
    } catch(...){
        cerr << "Unknown Exception occured" << endl;
        throw;
    }
}

void doubleDeletionSolution(){
    MyClass *p = nullptr;
    MyClass *q = nullptr;

    try {
        p = new MyClass; // Create ownership
        q = p;
        cout << p << " " << q << endl;
        
        delete q;
        q = nullptr; // Set to nullptr to avoid double deletion
        cout << p << " " << q << endl;

        // Attempting to delete p now would be safe as we set q to nullptr
        delete p;
        p = nullptr;
    } catch (const exception& e) {
        cerr << "An exception occurred: " << e.what() << endl;
    } catch (...) {
        cerr << "An unknown error occurred." << endl;
    }
}
int main(){
    // loseOwnership();

    // doubleDeletion();

    doubleDeletionSolution();
}