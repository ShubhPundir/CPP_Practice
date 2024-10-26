#include <iostream>
#include <cstring>
#include <string>
using namespace std;

template<class T1=int, class T2=string> // version 1
class Student{
    T1 roll; T2 name;
    public: Student(T1 r, T2 n): roll(r), name(n) { }
    void Print() const {cout << "Version 1 : (" << name << ", "<< roll << ")\n";}
};

template<class T1> // version 2
class Student<T1, char*>{
    T1 roll; char* name;
    public: Student(T1 r, char* n): roll(r), name(strcpy(new char[strlen(n) + 1], n)) { }
    void Print() const {cout << "Version 2 : (" << name << ", "<< roll << ")\n";}
};

int main(){
    Student<int,string> s1 (1, "Ram"); s1.Print(); // v1 (int, string)
    Student<int>        s2 (2, "Shampa"); s2.Print(); // v1 (int, string)
    Student<>           s3 (3, "Gagan"); s3.Print(); // v1 (int, string)
    Student<string>     s4 ("4", "Ram"); s4.Print(); // v1 (string, string)
    Student<int,char*>  s5 (5, "Ram"); s5.Print(); // v2 (int, char*)

}