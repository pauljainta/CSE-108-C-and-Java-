#include<iostream>
using namespace std;


class Point2D
{
	int x,y;
public:
	Point2D(){ x = 0; y = 0; } //default constructor initializes to (0,0)
	Point2D(int x, int y);
	void setX(int x);
	void setY(int y);
	void getX(int x);
	void getY(int y);
	void print();
	~Point2D(){ x = 0; y = 0; } //destructor that sets all values to 0
};

Point2D::Point2D(int argx,int argy)
{
	x = argx;
	y = argy;
}

void Point2D::setX(int argx)
{
	//Complete this function
}

void Point2D::setX(int argy)
{
	y = ary;
}

int Point2D::getX()
{
	return x;
}

int Point2D::getY()
{
	//Complete this function
}

void Point2D::print()
{
	cout << "(" << x << "," << y << ")";
}

class Circle
{
	Point2D center;
	double radius;
public:
	//write a default constructor that initializes all values to 0
	Circle(Point2D c, double r);
	//write getter and setter methods for this class
	double area(); //returns area of the circle
	void print(); //prints the rectangle in the stdout
	int intersect(Circle rhs); //determine if this circle intersects with rhs
	int contains(Circle rhs); //determine if this circle contains circle rhs
	int contains(Point2D p); //determine if this circle contains point p
	double perimeter(); //returns perimeter of the circle
	//write a destructor that sets all values to 0
};

Circle::Circle(Point2D c, double r)
{
	//complete this function
}

double Circle::area()
{
	return 3.1419*radius*radius;
}

int Circle::intersect(Circle rhs)
{
	//complete this function
}

int Circle::contains(Circle rhs)
{
	//complete this function
}

void Circle::print()
{
	cout << "Center: ";
	center.print();
	cout << "Radius: " << radius;
}

class Rectangle
{
	//define two variables that specifies the rectangle in a 2d space
	//the variables should represent: top-right point, bottom-left point
public:
	//write a default constructor that initializes all values to 0
	//write a constructor that accepts values of all member variables and set the members
	//variables accordingly
	//write getter and setter methods for this class
	double area(); //returns area of the rectangle
	int intersect(Rectangle rhs); //determine if this rectangle intersects with rhs
	int contains(Rectangle rhs); //determine if this rectangle contains rhs
	int inside(Circle c); //determine if this rectangle is completely inside the circle c
	double perimeter(); //returns perimeter of the circle
	//write a destructor that sets all values to 0
};

//Practice: Extend your program to include other geometric objects such as square, ellipse, triangle, etc.


int main(void)
{
//Demonstrate your circle class
	//Demonstrate your area funciton showing that it successfully prints area of a circle
	//Demonstrate intersect(Circle) function by creating appropriate circles and showing that they intersect
	//Demonstrate contains(Circle) function by creating appropriate circles and showing that one circle
	//contains another circle
	
//Demonstrate your Rectangle class	
	//Demonstrate your area funciton showing that it successfully prints area of a rectangle
	//Demonstrate intersect(Rectangle) function by creating appropriate circles and showing that 
	//they intersect
	//Demonstrate contains(Rectangle) function by creating appropriate circles and showing that 
	//one rectangle contains another rectangle
	//Demonstrate inside(Circle) function by creating appropriate rectangle and circle and showing that 
	//a rectange is completely inside a circle

	return 0;
}