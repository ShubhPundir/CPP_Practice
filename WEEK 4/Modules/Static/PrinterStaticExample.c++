#include <iostream>
using namespace std;

class PrintJobs{
    int nPages;
    static int nTrayPages;
    static int nJobs;
    PrintJobs(int nP) : Npages(nP) {
        ++nJobs;
        cout << "Printing : " << nP << " pages" << endl; 
        nTrayPages -= nP;
    }
    ~PrintJobs() {--nJobs;}
};

int PrintJobs::nTrayPages = 500;
int PrintJobs::nJobs = 0;

int main(){
    cout << "Jobs = " << PrintJobs::nJobs << endl;
    cout << "Pages = " << PrintJobs::nTrayPages << endl;
    PrintJobs job1(10);

    cout << "Jobs = " << PrintJobs::nJobs_ << endl;
    cout << "Pages= " << PrintJobs::nTrayPages_ << endl;
    {
        PrintJobs job1(30), job2(20); // Different job1 in block scope
        cout << "Jobs = " << PrintJobs::nJobs_ << endl;
        cout << "Pages= " << PrintJobs::nTrayPages_ << endl;
        PrintJobs::nTrayPages_ += 100; // Load 100 more pages
    }
    cout << "Jobs = " << PrintJobs::nJobs_ << endl;
    cout << "Pages= " << PrintJobs::nTrayPages_ << endl;

}