#include <iostream>
using namespace std;

// PURE VIRTUAL FUNCTION

class Shape{
    public:
        virtual void draw() = 0;
};
class Circle : public Shape{
    public:
        void draw(){ cout << "Circle::draw" << endl;}
};

int main(){
    Shape *s = new Circle;
    s->draw();
}