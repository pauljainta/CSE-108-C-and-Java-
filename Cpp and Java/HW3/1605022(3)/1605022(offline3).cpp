#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

typedef enum {UNDEFINED, POINT2D, POINT3D, CIRCLE, SQUARE, RECTANGLE, SPHERE} STYPE;

class Shape
{
	STYPE type;
public:
	Shape();
	Shape(STYPE type);
	int getType(){return type;}
	virtual void print();
	virtual double area();
	virtual bool contains(Shape *s);
	//Intentionally made non-virtual
	bool operator==(Shape &rhs);
	virtual ~Shape(){}
};

Shape::Shape()
{
	type = UNDEFINED;
}

Shape::Shape(STYPE argtype)
{
	type = argtype;
}

double Shape::area()
{
	cout << "I am a dummy Shape";
	return 0.0;
}

bool Shape::contains(Shape *rhs)
{
	cout << "You see this, because appropriate contains function is undefined";
	return false;
}

void Shape::print()
{
	cout << "Type: " << type;
}

bool Shape::operator==(Shape &rhs)
{
	if(type==rhs.type) return true;
	else return false;
}

class Point2D : public Shape
{
    protected:
	double x,y;
public:
	Point2D();
	Point2D(STYPE argtype, double argx, double argy);
	void print();
	double area();
	bool contains(Shape * rhs);
	bool contains(Point2D * rhs);
	bool operator==(Point2D &rhs);
    void setX(double X){x=X;}
    void setY(double Y){y=Y;}
	double getX() const { return x; }
	double getY() const { return y; }
	~Point2D(){}
};

Point2D::Point2D() //calls Base's default constructor
{
	x = 0.0;
	y = 0.0;
}

Point2D::Point2D(STYPE argtype, double argx, double argy) : Shape(argtype)
{
	x = argx;
	y = argy;
}

void Point2D::print()
{
	Shape::print();
	cout << " (" << x << "," << y << ")";
}

double Point2D::area()
{
	return 0.0;
}

bool Point2D::contains(Shape *rhs)
{
	Point2D * pointType = dynamic_cast<Point2D*>(rhs);
	if(pointType!=NULL)
	{
		//Supported
		return contains(pointType);
	}
	//By default, use base
	return Shape::contains(rhs);
}

bool Point2D::contains(Point2D * rhs)
{
	if(x==rhs->x && y==rhs->y) return true;
	else return false;
}

bool Point2D::operator==(Point2D & rhs)
{
	if( !Shape::operator==(rhs) ) return false;
	if( x==rhs.x && y==rhs.y ) return true;
	else return false;
}
class Rectangle:public Shape
{
	Point2D topRight;
	Point2D bottomLeft;
	Point2D topLeft,bottomRight;
public:

	Rectangle();//implement this
	Rectangle(STYPE type, Point2D tr, Point2D bl);//implement this
	void print(); //implement this
	double area(); //implement this
	bool contains(Shape *rhs);
    bool contains(Point2D *s); //implement this to check containment for point2d only
	bool operator==(Rectangle &rhs);
	Point2D* gettopRight(){return &topRight;}
	Point2D* getbottomLeft(){return &bottomLeft;}
	Point2D* gettopLeft(){return &topLeft;}
	Point2D* getbottomRight(){return &bottomRight;}
	~Rectangle(){}

};

Rectangle::Rectangle()
{
    topRight.setX(0);
    topRight.setY(0);
    bottomLeft.setX(0);
    bottomLeft.setY(0);
}
Rectangle::Rectangle(STYPE type, Point2D tr, Point2D bl):Shape(type)
{
    topRight.setX(tr.getX());
    topRight.setY(tr.getY());
    bottomLeft.setX(bl.getX());
    bottomLeft.setY(bl.getY());
     topLeft.setX(bottomLeft.getX());
	bottomRight.setX(topRight.getX());
	topLeft.setY(topRight.getY());
	bottomRight.setY(bottomLeft.getY());

}
double Rectangle::area()
{
    double length,width;
    length=abs(topRight.getX()-bottomLeft.getX());
    length=abs(topRight.getY()-bottomLeft.getY());
    return width*length;
}
void Rectangle::print()
{
    Shape::print();
}
bool Rectangle::contains(Shape *rhs)
{
   Point2D * pointType = dynamic_cast<Point2D*>(rhs);
	if(pointType!=NULL)
	{
		return contains(pointType);
	}
	return Shape::contains(rhs);
}
bool Rectangle::contains(Point2D *s)
{
    double length,width;
    length=abs(topRight.getX()-bottomLeft.getX());
    length=abs(topRight.getY()-bottomLeft.getY());
        if (s->getX()>=bottomLeft.getX()&& s->getX()<=bottomLeft.getX()+length &&
s->getY()>=bottomLeft.getY()&& s->getY()<=bottomLeft.getY()+width)
		return true;
		return false;
}
bool Rectangle::operator==(Rectangle &rhs)
{
    return (area()==rhs.area());
}


class Circle : public Shape
{
	Point2D center;
	double radius;
public:
	Circle();
	Circle(STYPE type, Point2D c, double r); //implement this
	double area(); //implement this
	void print(); //implement this
	bool contains(Shape * s); //implemented partially
	bool contains(Point2D * p); //implement this
	bool contains(Circle * rhs); //implement this
	bool contains(Rectangle * p); //implement this
	bool operator==(Circle &rhs); //implement this
	~Circle(){}
};
Circle::Circle()
{
    center.setX(0.0);
    center.setY(0.0);
}
Circle::Circle(STYPE type,Point2D c,double r):Shape(type)
{
    radius=r;
    center.setX(c.getX());
    center.setY(c.getY());
}
void Circle::print()
{
    Shape::print();
    cout<<"center-"<<"("<<center.getX()<<","<<center.getY()<<")\n";
    cout<<"radius:"<<this->radius<<endl;

}
bool Circle::contains(Point2D *p)
{
    double X,Y;
    X=pow(center.getX()-p->getX(),2);
    Y=pow(center.getY()-p->getY(),2);
    if(X+Y-(radius*radius)<=0) return true;
    return false;
}
bool Circle::contains(Circle *rhs)
{
     double X,Y,R;
    X=pow(center.getX()-rhs->center.getX(),2);
    Y=pow(center.getY()-rhs->center.getY(),2);
    R=radius*rhs->radius;
    if(X+Y<R) return true;
    return false;
}
bool Circle::contains(Rectangle *p)
{
    bool t1,t2,t3,t4;
    t1=contains(p->gettopRight());
    t2=contains(p->getbottomLeft());
    t3=contains(p->gettopLeft());
    t4=contains(p->getbottomRight());
    if(t1&&t2&&t3&&t4) return true;
    return false;
}
bool Circle::operator==(Circle &rhs)
{
    return (radius==rhs.radius);
}
double Circle::area()
{
    return 3.1416*radius*radius;
}
bool Circle::contains(Shape * s)
{
	 Point2D * pointType = dynamic_cast<Point2D*>(s);
	if(pointType!=NULL)
	{
		//Supported
		return contains(pointType);
	}
	 Circle * circleType = dynamic_cast<Circle*>(s);
	if(circleType!=NULL)
	{
		//Supported
		return contains(circleType);
	}
	Rectangle * rectangleType = dynamic_cast<Rectangle*>(s);
	if(rectangleType!=NULL)
	{
		//Supported
		return contains(rectangleType);
	}
	//By default
	return Shape::contains(s);
}




class Point3D : public Point2D
{
    double z;
public:
    Point3D(); //already implemented
    Point3D(STYPE type, double argx, double argy, double argz); //implement this
    void print(); //already implemented
    //double area(); Not needed, base version is sufficient
	bool contains(Shape *rhs); //implement this
	bool contains(Point3D *rhs);
    void setZ(double Z)
    {
        z=Z;
    }
    double getZ(){return z;}
	~Point3D(){}
};
Point3D::Point3D(STYPE type,double argx,double argy,double argz):  Point2D::Point2D(type,argx,argy)
{
    z=argz;
  //  Point2D::Point2D(type,argx,argy);
}

Point3D::Point3D()
{
    z = 0;
}

void Point3D::print()
{
	Shape::print();
    cout << " (" << getX() << "," << getY() << "," << z << ")";
}
bool Point3D::contains(Shape *rhs)
{
    Point3D *PointType=dynamic_cast<Point3D*>(rhs);
    if(PointType!=NULL) return contains(PointType);
    return Shape::contains(rhs);
}
bool Point3D::contains(Point3D *rhs)
{
    if(x==rhs->x&&y==rhs->y&&z==rhs->z) return true;
    return false;
}

class Shape3D : public Shape
{
public:
	Shape3D();
	Shape3D(STYPE type);
	virtual double volume();

	~Shape3D(){}
};

Shape3D::Shape3D()
{

}

Shape3D::Shape3D(STYPE argtype) : Shape(argtype)
{

}

double Shape3D::volume()
{
	cout << "You see this, because appropriate function is missing in the derived class";
	return 0.0;
}



class Sphere : public Shape3D
{
	Point3D center;
	double radius;
public:
	Sphere();//implement this
	Sphere(STYPE type, Point3D c, double r);//implement this
	void print(); //implement this
	double area(); //implement this
	double volume(); //implement this
	bool contains(Shape * rhs); //implement this for checking containgment of Point3D, Sphere inside sphere
	bool contains(Point3D * p); //implement this
	bool contains(Sphere * s); //implement this
	~Sphere(){}
};
Sphere::Sphere()
{
    center.setX(0.0);
    center.setY(0.0);
    center.setZ(0.0);
}
Sphere::Sphere(STYPE type, Point3D c, double r):Shape3D(type)
{
    radius=r;
    center.setX(c.getX());
    center.setY(c.getY());
    center.setZ(c.getZ());
}
void Sphere::print()
{
    cout<<"center-("<<center.getX()<<","<<center.getY()<<","<<center.getZ()<<")"<<endl;
    cout<<"radius-\n"<<radius;
}
double Sphere::area()
{
    return 4.0*3.1416*pow(radius,2);
}
double Sphere::volume()
{
   return (4.0/3)*3.1416*pow(radius,3);
}
bool Sphere::contains(Shape *rhs)
{
	Point3D *pointType = dynamic_cast<Point3D*>(rhs);
	if(pointType!=NULL)
	{
		return contains(pointType);
	}
	Sphere *SphereType = dynamic_cast<Sphere*>(rhs);
	if(SphereType!=NULL)
	{
		return contains(SphereType);
	}
	return Shape::contains(rhs);
}
bool Sphere::contains(Point3D *p)
{
    double X,Y,Z;
    X=pow(center.getX()-p->getX(),2);
    Y=pow(center.getY()-p->getY(),2);
    Z=pow(center.getZ()-p->getZ(),2);
    if(X+Y+Z-(radius*radius)<=0) return true;
    return false;
}
bool Sphere::contains(Sphere *s)
{
    return (radius==s->radius);
}



int main(void)
{

	while(1)
	{
		int choice = 10;
		Shape * shape;
		Shape * p= new Point2D(POINT2D, 6.0,11.0);
		Shape * p1= new Point2D(POINT2D, 10.0,15.0);
		Point2D p3(POINT2D,10.0,10.0);
        Point2D p4(POINT2D,25.0,25.0);

		Shape3D * shape3D;
		Shape *r = new Rectangle(RECTANGLE,p3,p4);
		Rectangle r2 (RECTANGLE,p3,p4);
        Circle c2(CIRCLE,p3,10.0);
		Shape *c = new Circle(CIRCLE,p3,10.0);
		cout << "1. Point2D 2. Rectangle 3. Circle\n";
        cout << "4. Point3D 5. Sphere. 0. Exit\n";
        cout << "Your choice:";
        cin >> choice;

		switch(choice)
		{

			case 1:{
				shape = new Point2D(POINT2D, 5.0,10.0);

				cout<<"Point 1:";
                shape->print();

				cout << "\nArea: " << shape->area()<<endl;
				cout<<"Point 2:";
                p->print();
				if(shape->contains(shape)==true) cout<<"Contains"<<endl;
				else cout<<"Doesn't contain"<<endl;
				if(shape==p) cout<<"Equal"<<endl;
				else cout<<"Not equal"<<endl;
				break;
			}
			case 2:{
				Point2D p1(POINT2D,5.0,5.0);
				Point2D p2(POINT2D,20.0,20.0);
				shape = new Rectangle(RECTANGLE, p1, p2);
				shape->print();
				cout << "\nArea: " << shape->area()<<endl;
				if(shape->contains(&p2)==true) cout<<"contains"<<endl;
				else cout<<"Doesn't contain"<<endl;

				if(shape==r) cout<<"It is equal"<<endl;
				else cout<<"Not equal"<<endl<<endl;
				break;
			}
			case 3:{
				Point2D p5(POINT2D,0.0,0.0);
				shape = new Circle(CIRCLE,p5,10.0);
				Shape * p6= new Point2D(POINT2D, 3.0,4.0);

				shape->print();
				cout << "\nArea: " << shape->area()<<endl;
				if(shape->contains(p6)==true) cout<<"Contains"<<endl;
				else cout<<"Doesn't contain"<<endl;
				if(shape->contains(c)==true) cout<<"Contains"<<endl;
				else cout<<"Doesn't contain"<<endl;
				if(shape->contains(r)==true) cout<<"Contains"<<endl;
				else cout<<"Doesn't contain"<<endl;

				if(shape==shape) cout<<"Equal"<<endl;
				else cout<<"Not equal"<<endl;
				break;
			}
			case 4:{
				Point3D p1(POINT3D,0.0,0.0,0.0);
				shape3D = new Sphere(SPHERE,p1,10.0);
				Point3D *p3D = new Point3D(POINT3D,0.0,0.0,0.0);
				shape3D->print();
				cout << "\nArea: " << shape3D->area()<<endl;
				cout << "\nVolume: " << shape3D->volume()<<endl;
				if (shape3D->contains(p3D)==true) cout<<"Contains"<<endl;
				else cout<<"Doesn't contain"<<endl;
				if (shape3D->contains(shape3D)==true) cout<<"Contains"<<endl;
				else cout<<"Doesn't contain"<<endl;
				break;
		}
            default: cout<<"Choose correctly"<<endl;

	}
	if(choice==0) break;
	}
	return 0;
}


