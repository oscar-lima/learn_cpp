#include <iostream>
#include <vector>

using namespace std;

class Shapes
{
    public:

    Shapes()
    {
        cout << "parent class constructor" << endl;
    }

    virtual double calculate_area()
    {
        return 0;
    }

    private:

};

class Rectangle : public Shapes
{
    public:

    Rectangle()
    {
        cout << "child class constructor" << endl;
        lenght_ = 1.0;
        width_ = 2.0;
    }

    Rectangle(double lenght, double width)
    {
        cout << "child class constructor" << endl;
        lenght_ = lenght;
        width_ = width;
    }

    double calculate_area()
    {
        return width_*lenght_;
    }

    private:

    double lenght_, width_;
};

class Circle : public Shapes
{
    public:

    Circle()
    {
        radius_ = 5.0;
    }

    Circle(double radius)
    {
        radius_ = radius;
    }

    double calculate_area()
    {
        return 3.1416*radius_*radius_;
    }

    private:

    double radius_;
};

int main()
{
    Rectangle a(2.0, 4.0);
    Circle b(3.0);

    cout << "Calculating rectangle area : " << a.calculate_area() << "\n";
    cout << "Calculating circle area : " << b.calculate_area() << "\n";

    std::vector<Rectangle> many_rectangles;

    many_rectangles.push_back(Rectangle(2.5, 3.0));
    many_rectangles.push_back(Rectangle(5.0, 6.0));

    cout << "Area of rectangles [0] : " << many_rectangles[0].calculate_area() << "\n";
    cout << "Area of rectangles [1] : " << many_rectangles[1].calculate_area() << "\n";

    std::vector<Shapes*> many_shapes;

    many_shapes.push_back(&a);
    many_shapes.push_back(&b);

    cout << "\nLooping over std shapes vector\n";


    for(std::vector<Shapes*>::iterator it = many_shapes.begin(); it != many_shapes.end(); ++it)
    {
        cout << "Calculating shapes [" << *it << "] : " << (*it)->calculate_area() << "\n";
    }

    // the same but with for loop
    for (int i =  0; i < many_shapes.size() ; i++)
    {
        many_shapes.at(i)->calculate_area();
    }

    return 0;
}