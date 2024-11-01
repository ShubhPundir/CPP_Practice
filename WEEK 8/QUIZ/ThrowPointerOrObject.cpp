#include <iostream>
using namespace std;

class Printer {};
class Nozzle : public Printer {};
class Cartridge: public Printer {};

void print(int i){
    try{
        i < 0 ? throw Nozzle() : throw new Cartridge();
        // new Cartridge() --> throws a pointer to a cartridge object
        // Nozzle() --> throws the object itself
    }
    catch(Printer){ cout << "PrinterException ";} // catches the Nozzle object
    catch(Nozzle){ cout << "NozzleException ";}
    catch(Cartridge){ cout << "CartridgeException ";}
    // catch(Printer*) { cout << "Gotcha ya cunt ";}
}; // wow somehow this semi-colon does not change shit here!!!

int main(){ // 
    try{
        for(int i=-1; i<2; i++){
            // cout << i <<" is going through now" << endl;
            print(i);
        }
    }
    catch(...){
        cout << "Some other Exception";
    }
    return 0;
}