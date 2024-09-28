// Dynamic cast can only be used on POINTERS and REFERENCES or (void*)
// to ensure, that the result of the type conversion points to a 
// valid complete object of the destination pointer type

// Can be used for UPCASTING, but static_cast is better due to less computation

// only context where it is useful is when we are downcasting (Generalized Class to a Specialized class)
// VALID for polymorphic classes(those with virtual functions) and if-and-only-if the object is a valid complete object of the target type

// if pointed object is NOT a valid complete object of the target type, dynamic_cast returns a null pointer

// if dynamic_cast is used to convert to a reference type and the conversion is not possible,
// an exception of the type --> bad_cast is thrown

// dynamic_cast can also perform the other implicit casts allowed on pointers: casting null pointers
// between pointer types(eveb between unrelated classes), and casting any pointer pf any type to
// a void* pointer

#include <iostream>
using namespace std;

class A{public: virtual ~A() { } };
class B : public A{};
class C{public: virtual ~C() { } };


int main(){
    A a; B b; C c;

    B* pB = &b; A *pA = &a; C *pC = &c;
    cout << "pB = " << pB << " pA = "<< pA << " pC = "<< pC << endl;
    
    pA = dynamic_cast<A*>(pB);
    cout << pB << " casts to " << pA << " : Up-cast: valid" << endl;

    pA = &b; pB = dynamic_cast<B*>(pA) ;
    cout << pA << " casts to " << pB << " : Down-cast: Valid" << endl;

    pA = &a; pB = dynamic_cast<B*>(pA);
    // not valid as a generalized object is attempting to fit in a specialized object4
    // aka target type(B) realizes that whatever it is getting (pA) is a fallacy --> NOT A VALID COMPLETE OBJECT
    cout << pA << " casts to "  << pB << " : Down-cast: Invalid" << endl;
    // null pointer tells that it is not right

    pA = (A*)&c; pC = dynamic_cast<C*>(pA); // unrelated classes --> return null pointer
    cout << pA << " casts to " << pC << " Unrelated-cast Invalid" << endl;

    pA = 0; pC = dynamic_cast<C*>(pA);
    cout << pA << " casts to " << pC << " Unrelated-cast: Valid for null" << endl;
    // ONLY VALID if both source pointer(pA) was null(0) to begin with

    pA = &a; void *pV = dynamic_cast<void*>(pA);
    cout << pA << " casts to " << pV << " Cast-to-void: Valid" << endl;
    // NOTIHNG(left) can be ANYTHING(right)

    // BUT
    // pA = dynamic_cast<A*>(pV); // is INVALID
    // Anything(left) cannot be NOTHING(right)

}