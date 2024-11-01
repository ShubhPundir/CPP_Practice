#include <iostream>
#define PI 3.14
using namespace std;

class Circle{
    protected:
        double radius;
    public:
        Circle(double r) : radius(r) {}

        virtual double Area();           //LINE-1

        void Print();            //LINE-2
};
double Circle::Area() { return PI*radius*radius; }
void Circle::Print() { cout << Area() << " "; }

class Cylinder: public Circle{
    double height;
    public:
        Cylinder(double r, double h) : Circle(r), height(h) {}
        double Area() { return 2*PI*radius*radius*height; }
};

int main(){
    double r=7, h=10;
    Circle c1(r);
    Cylinder c2(r,h);
    Circle *c[2] = {&c1, &c2};
    for(int i=0;i<2;i++)
        c[i]->Print();
		
    return 0;
}