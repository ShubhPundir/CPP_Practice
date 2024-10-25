#include <iostream> // Abstract Base Class shown in red
using namespace std; // Concrete Class shown in green

class Shapes {
    public: // Abstract Base Class
    virtual void draw() = 0; // Pure Virtual Function
};
void Shapes::draw(){ cout << "Shapes: Init Brush ";}
class Polygon: public Shapes { public: void draw() { cout<< "Polygon: Draw by Triangulation" <<endl; } };
class ClosedConics: public Shapes { public: // Abstract Base Class
// draw() inherited - Pure Virtual
};
class Triangle: public Polygon { public: void draw() { cout << "Triangle: Draw by Lines" << endl; } };
class Quadrilateral: public Polygon {
    public: void draw() { cout << "Quadrilateral: Draw by Lines" << endl; }
};
class Circle: public ClosedConics {
    public: void draw() { cout << "Circle: Draw by Breshenham Algorithm" << endl; }
};
class Ellipse: public ClosedConics {
    public: void draw() { cout << "Ellipse: Draw by ..." << endl; }
};
int main() {
    Shapes *arr[] = { new Triangle, new Quadrilateral, new Circle, new Ellipse };
    for(int i = 0; i < sizeof(arr) / sizeof(Shapes *); ++i)
        arr[i]->draw();
    // ...
}