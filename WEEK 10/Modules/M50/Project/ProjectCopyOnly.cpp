#include <iostream>
#include <cstring>
using namespace std;
class ResMgr {
    // Resource Management class to track creation and release of resources
    static unsigned int nCreated, nReleased; // Counters for created & released resources
    public:
        ResMgr() { } // Constructor to be called before main
        ~ResMgr() { // Destructor to be called after main
            cout << "Resources Created = " << nCreated << endl;
            cout << "Resources Released = " << nReleased << endl;
        }
    inline static char *Create(const char *s) // Create a resource from s
    {
        return (s) ? ++nCreated, strdup(s) : nullptr;
    } // If s is not null, copy & increment counter
    inline static void Release(char *s) // Release the resource held by s
    {
        (s) ? free(s), ++nReleased : 0;
    } // If s is not null, increment counter & free resource
    inline static void Stat() // Print stats for resources created and released
    {
        cout << " Stat = (" << nCreated << ", " << nReleased << ")nnnn";
    }
};
unsigned int ResMgr::nCreated = 0; // Define and initialize Counters
unsigned int ResMgr::nReleased = 0;

class MyResource {
    // Representative resource class with copy-only support
    char *str = nullptr; // Resource pointer
    public:
    MyResource(const char* s = nullptr) : str(ResMgr::Create(s)) // Param. & Defa. Ctor
    {
        cout << "Ctor[R] ";
    } // Creates resource
    MyResource(const MyResource& s) : str(ResMgr::Create(s.str)) // Copy Ctor
    {
        cout << "C-Ctor[R] ";
    } // Copy-Creates resource
    MyResource& operator=(const MyResource& s) {
        cout << "C=[R] "; // Copy Assignment
        if (this != &s) { 
            ResMgr::Release(str); str = ResMgr::Create(s.str);
        }
        return *this; // Releases and Copy-Creates resource
    }
    ~MyResource() // Destructor
    { cout << "Dtor[R] "; ResMgr::Release(str); } // Releases resource
    friend ostream& operator<<(ostream& os, const MyResource& s) { // Streams resource value
    cout << ((s.str) ? s.str : "null"); return os; // Streams "null" for nullptr (no resource)
    }
};

MyResource f(MyResource s){
    cout << "f[R] "; return s;
}

ResMgr m;
int main(){
    MyResource r1{ "ppd" }; // Ctor[R] r1=ppd Stat = (1, 0)
    cout << "r1=" << r1; ResMgr::Stat(); // r1 constructed with parameter
    MyResource r2 {r1}; // C-Ctor[R] r2=ppd r1=ppd Stat = (2, 0)
    cout << "r2=" << r2 << " r1=" << r1; ResMgr::Stat(); // r2 copy constructed from r1
    MyResource r3 {f(r2) }; // C-Ctor[R] f[R] C-Ctor[R] Dtor[R] r3=ppd r2=ppd Stat = (4, 1)
    cout << "r3=" << r3 << " r2=" << r2; ResMgr::Stat(); // r3 C-Ctor from f(r2): C-Ctor / Dtor for param
    r1 = r2; // C=[R] r1=ppd r2=ppd Stat = (5, 2)
    cout << "r1=" << r1 << " r2=" << r2; ResMgr::Stat(); // r1 copy assigned from r2
    MyResource r4; // Ctor[R] r4=null Stat = (5, 2)
    cout << "r4=" << r4; ResMgr::Stat(); // r4 default constructed
    r4 = f(r3); // C-Ctor[R] f[R] C-Ctor[R] C=[R] Dtor[R] Dtor[R] r4=ppd r3=ppd Stat = (8, 4)
    cout << "r4=" << r4 << " r3=" << r3; ResMgr::Stat(); // r4 C= from f(r3): trace debug to understand
}   // m.~ResMgr is called after the destruction of local automatic objects to print the final statistics
    // Dtor[R] Dtor[R] Dtor[R] Dtor[R]
    // Resources Created = 8 Resources Released = 8 // printed from m.~ResMgr