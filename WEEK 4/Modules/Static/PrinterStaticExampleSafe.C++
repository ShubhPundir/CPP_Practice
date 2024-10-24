#include <iostream>
using namespace std;


class PrintJobs{
    int nPages;
    static int nTrayPages;
    static int nJobs;
    public:
    PrintJobs(int nP) : nPages(nP) {
        ++nJobs;
        cout << "Printing : " << nP << " pages" << endl; 
        nTrayPages -= nP;
    }
    ~PrintJobs() {--nJobs;}
    static int getJobs() {return nJobs; }
    static int checkPages() {return nTrayPages; }
    static void loadPages(int nP) {nTrayPages += nP; }
};

int PrintJobs::nTrayPages = 500;
int PrintJobs::nJobs = 0;

int main(){
    cout << "Jobs = " << PrintJobs::getJobs() << endl;
    cout << "Pages = " << PrintJobs::checkPages() << endl;
    PrintJobs job1(10);

    cout << "Jobs = " << PrintJobs::getJobs() << endl;
    cout << "Pages= " << PrintJobs::checkPages() << endl;
    {
        PrintJobs job1(30), job2(20); // Different job1 in block scope
        cout << "Jobs = " << PrintJobs::getJobs() << endl;
        cout << "Pages= " << PrintJobs::checkPages() << endl;
        PrintJobs::loadPages(100); // Load 100 more pages
    }
    cout << "Jobs = " << PrintJobs::getJobs() << endl;
    cout << "Pages= " << PrintJobs::checkPages() << endl;

}