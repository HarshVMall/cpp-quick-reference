#include <iostream>
using namespace std;

//Implementing factory method design pattern
// First step: Product interface

class Shape {
    public:
    
    virtual void getShape() = 0;
    virtual ~Shape() {
        
    }; //for polymorphism, destroying using base clas implementation
};

//Second step: create products
class Square : public Shape {
    public:
    
    void getShape() override {
        cout << "Square!!" << endl;
    } 
};

class Circle : public Shape {
    public:
    
    void getShape() override {
        cout << "Circle!!" << endl;
    }
};


//Third step: Create Factory interface
class ShapeFactory {
    public:
    
    virtual Shape* createShape() = 0;
    virtual ~ShapeFactory() {
        
    } // for polymorphism
};

//Fourth step: Create Actual Factories
class SquareFactory : public ShapeFactory {
    public:
    
    Shape* createShape() override {
        return(new Square());
    }
};

class CircleFactory : public ShapeFactory {
    public:
    
    Shape* createShape() override {
        return(new Circle());
    }
};


int main() {
    ShapeFactory* circleFactory = new CircleFactory();
    ShapeFactory* squareFactory = new SquareFactory();
    
    Shape* circle = circleFactory->createShape();
    Shape* square = squareFactory->createShape();
    
    circle->getShape();
    square->getShape();
    
    return 0;
}
