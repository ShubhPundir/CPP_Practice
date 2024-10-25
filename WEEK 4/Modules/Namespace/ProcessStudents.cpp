#include <iostream>
using namespace std;
#include "Students.h"

extern StReg *reg;

namespace App1{
    void ProcSt(){
        cout << "Male Students: " << endl;
        int r = 1;
        St *s;

        while(s = reg->getStudent(r++)){
            if(s->getGender()==St::male)
                cout << *s;
        }
        cout << endl << endl;
        return;
    }
}

namespace App2{
    void ProcSt(){
        cout << "Female Students: " << endl;
        int r = 1;
        St *s;

        while(s = reg->getStudent(r++)){
            if(s->getGender()==St::female)
                cout << *s;
        }
        cout << endl << endl;
        return;
    }
}

StReg *reg = new StReg(1000);

int main(){
    St s1("Ravi", St::male); reg->add(&s1);
    St s2("Rhea", St::female); reg->add(&s2);
    St s3("Ram", St::male); reg->add(&s3);
    St s4("Raashi", St::female); reg->add(&s4);

    App1::ProcSt();
    App2::ProcSt();
}