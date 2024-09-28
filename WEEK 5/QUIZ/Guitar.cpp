#include <iostream>
using namespace std;

class Instrument{
    public:
        void play(){
            cout << "Instrument::play()";
        }
        void play(int volume){
            cout << "Instrument::play(int)";
        }
};

class Guitar: public Instrument{
    public:
        void play(){
            cout << "Guitar::play()";
        }
        void play(int volume){
            cout << "Guitar::play(int)";
        }
};

int main(){
    Guitar g;
    g.Instrument::play();
}