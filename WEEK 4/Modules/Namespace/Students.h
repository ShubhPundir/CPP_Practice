#include <iostream>
#include <cstring>
using namespace std;

class St{
    public:
        typedef enum GENDER {male=0, female=1};
        St(char *n, GENDER g) : name(strcpy(new char[strlen(n) + 1], n)) , gender(g) { }
        void setRoll(int r) { roll = r;}
        GENDER getGender() { return gender;}
        friend ostream& operator<<(ostream& os, const St& s) {
            cout << ((s.gender == St::male) ? "Male " : "Female ") << s.name << " " << s.roll << endl;
            return os;
        }
    private:
        char *name; GENDER gender; int roll;
};

class StReg{
    St **rec; int nStudents;
    public: StReg(int size) : rec(new St*[size]) , nStudents(0) { }
    void add(St* s) { rec[nStudents] = s; s->setRoll(++nStudents);}
    St *getStudent(int r) {return (r == nStudents + 1) ? 0 : rec[r-1];}
};
