#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
class Point2D
{
    double vuj,koti;
    public:
    void setX(double x)
    {
        vuj=x;
    }
    void setY(double y)
    {
       koti=y;
    }
    double getX()
    {
       return vuj;
    }
    double getY()
    {
        return koti;
    }
    ~Point2D()
    {
     vuj=0;
     koti=0;
    }
Point2D operator+(Point2D p)
{
    Point2D p1;
    p1.setX(vuj+p.vuj);
    p1.setY(koti+p.koti);
    return p1;
}
Point2D operator*(int n)
{
    Point2D p;
    p.setX(vuj*n);
    p.setY(koti*n);
    return p;
}
bool operator==(Point2D P)
{
    return ((getX()==P.getX())&&(getY()==P.getY()));
}
bool operator!=(Point2D P)
{
        return (!((getX()==P.getX())&&(getY()==P.getY())));
}
};
class Circle
{
      double centerX,centerY;
public:
    double radius;
    Circle();
    Circle(Point2D c,double r);
    ~Circle();
    Circle(double r)
    {
        radius=r;
    }
    void setCenter(double x1,double y1)
    {
        centerX=x1;
        centerY=y1;
    }
    void setRadius(double r)
    {
        radius=r;
    }
    double getCenterX()
    {
        return centerX;
    }
     double getCenterY()
    {
        return centerY;
    }
     double getRadius()
    {
        return radius;
    }
    Circle operator+(Point2D P)
    {
        Circle C;
        C.setCenter(getCenterX()+P.getX(),getCenterY()+P.getY());
        return C;
    }
     Circle operator*(int n)
     {
         Circle C;
         C.setCenter(getCenterX()*n,getCenterY()*n);
         C.setRadius(getRadius()*n);
         return C;
     }
     Circle operator+(Circle C2)
     {
         Circle C1;
         double alpha,alphaX,alphaY;
         alpha=getRadius()/(getRadius()+C2.getRadius());
         alphaX=(getCenterX()*alpha)+(C2.getCenterX()*(1-alpha));
         alphaY=(getCenterY()*alpha)+(C2.getCenterY()*(1-alpha));
         C1.setCenter(alphaX,alphaY);
         C1.setRadius(getRadius()+C2.getRadius());
         return C1;
     }
     Circle operator-(Circle C2)
     {
         Circle C1;
         double alpha,alphaX,alphaY;
         alpha=getRadius()/(getRadius()+C2.getRadius());
         alphaX=(getCenterX()*alpha)+(C2.getCenterX()*(1-alpha));
         alphaY=(getCenterY()*alpha)+(C2.getCenterY()*(1-alpha));
         C1.setCenter(alphaX,alphaY);
         C1.setRadius(getRadius()-C2.getRadius());
         return C1;
     }
     bool operator==(Circle C2)
     {
         return (C2.getRadius()==getRadius());
     }
     bool operator>(Circle C2)
     {
         return ((3.1416*getRadius()*getRadius())>(3.1416*C2.getRadius()*C2.getRadius()));
     }
     bool operator>=(Circle C2)
     {
         return ((3.1416*getRadius()*getRadius())>=(3.1416*C2.getRadius()*C2.getRadius()));
     }
      bool operator<(Circle C2)
     {
         return ((3.1416*getRadius()*getRadius())<(3.1416*C2.getRadius()*C2.getRadius()));
     }
        bool operator<=(Circle C2)
     {
         return ((3.1416*getRadius()*getRadius())<=(3.1416*C2.getRadius()*C2.getRadius()));
     }
     Circle operator++()
     {
         ++radius;
         return Circle(radius);
     }
     Circle operator++(int v)
     {
         Circle temp(*this);
         ++radius;
         return temp;
     }
};
Circle::Circle()
{
    centerX=0;
    centerY=0;
    radius=0;
}
Circle::Circle(Point2D c,double r)
{
    centerX=c.getX();
    centerY=c.getY();

   if(r>0||r==0) radius=r;
}
Circle::~Circle()
{
    radius=0;
}
class Rectangle
{
    Point2D TopRight,BottomLeft,TopLeft,BottomRight;
    public:
    Rectangle()
    {
       TopRight.setX(0);
       TopRight.setY(0);
       BottomLeft.setX(0);
       BottomLeft.setY(0);
       TopLeft.setX(0);
       BottomRight.setX(0);
       TopLeft.setY(0);
       BottomRight.setY(0);
    }
    Rectangle(Point2D P1,Point2D P2)
    {
        TopRight.setX(P1.getX());
        TopRight.setY(P1.getY());
        BottomLeft.setX(P2.getX());
        BottomLeft.setY(P2.getY());
    }
    void setValues(double x1,double y1,double x2,double y2)
    {
       TopRight.setX(x1);
       TopRight.setY(y1);
       BottomLeft.setX(x2);
       BottomLeft.setY(y2);
    }
     getTopRightX()
    {
        return TopRight.getX();
    }
    double getTopRightY()
      {
          return TopRight.getY();
      }
      double getBottomLeftX()
      {
          return BottomLeft.getX();
      }
        double getBottomLeftY()
      {
          return BottomLeft.getY();
      }

      ~Rectangle()
      {
          TopRight.setX(0);
       TopRight.setY(0);
       BottomLeft.setX(0);
       BottomLeft.setY(0);
      }
Rectangle operator+(Point2D P)
{
    Rectangle R;
    double x1,y1,x2,y2;
    x1=TopRight.getX()+P.getX();
    x2=BottomLeft.getX()+P.getX();
    y1=TopRight.getY()+P.getY();
    y2=BottomLeft.getY()+P.getY();
    R.setValues(x1,y1,x2,y2);
    return R;
}
Rectangle operator*(int n)
{
    Rectangle R;
    double x1,y1,x2,y2;
    x1=TopRight.getX()*n;
    x2=BottomLeft.getX()*n;
    y1=TopRight.getY()*n;
    y2=BottomLeft.getY()*n;
    R.setValues(x1,y1,x2,y2);
    return R;
}

};
int main()
{
     Point2D point1,point2;
     Rectangle R1(point1,point2),R2;
     point1.setX(2);
     point1.setY(3);
     point2.setX(1);
     point2.setY(3);
     Circle c1(point1,4.5);
     Circle c2(point2,12.0);
     R1.setValues(4,4,2,2);
     cout<<"Center of the circle c1 is "<<"("<<c1.getCenterX()<<","<<c1.getCenterY()<<")"<<"and radius is "<<c1.getRadius()<<endl;
      cout<<"Center of the circle c2 is "<<"("<<c1.getCenterX()<<","<<c2.getCenterY()<<")"<<"and radius is "<<c2.getRadius()<<endl;
     cout<<"After translating about point(1,3) the new center is ";
     Circle C3=c1+point2;
     cout<<"("<<C3.getCenterX()<<","<<C3.getCenterY()<<")"<<endl;
     C3=c1*3;
     cout<<"After multiplying with n=3,the center is("<<C3.getCenterX()<<","<<C3.getCenterY()<<")"<<"and radius is \n"<<C3.getRadius();
     C3=c1+c2;
     cout<<"After operating '+' with a circle having center(1,3) and radius 12,"<<endl<<endl<<"we get the new center is("<<C3.getCenterX()<<","<<C3.getCenterY()<<")";
     cout<<" and radius is "<<C3.getRadius()<<endl;
     C3=c1-c2;
     cout<<endl<<"After operating '-' with a circle having center(1,3) and radius 12,"<<endl<<endl<<"we get the new center is("<<C3.getCenterX()<<","<<C3.getCenterY()<<")";
     cout<<" and radius is "<<C3.getRadius()<<endl;
     if(c1==c2) cout<<"The two circles have the same area"<<endl<<endl;
     else cout<<"The two circles c1 and c2 don't have the same area"<<endl<<endl;
     if((c1>(c2))) cout<<"C1 is larger than C2"<<endl<<endl;
     else cout<<"C1 is not larger than C2"<<endl<<endl;
     if((c1.operator>=(c2))) cout<<"C1 is larger than or equals to C2"<<endl<<endl;
     else cout<<"C1 is not larger or equals to than C2"<<endl<<endl;
     if((c1.operator<(c2))) cout<<"C1 is smaller than C2"<<endl<<endl;
     ++c1;
     cout<<"After increment, the radius of C1 is "<<c1.getRadius()<<"\n\n";
     c1++;
     cout<<"After increment, the radius of C1 is "<<c1.getRadius()<<"\n\n";
    Rectangle R3=R1+point1;
    cout<<"R1-> TopRight(4,4),BottomLeft(2,2)\n";
    cout<<"\nAfter translating the reactangle R1 about the point(2,3),"<<endl;
    cout<<"\nR1->  TopRight("<<R3.getTopRightX()<<","<<R3.getTopRightY()<<")";
    cout<<"  BottomLeft("<<R3.getBottomLeftX()<<","<<R3.getBottomLeftY()<<")\n\n";
    cout<<"After multiplying with n=3,\n\n";
    R3=R1*3;
    cout<<"\nR1->  TopRight("<<R3.getTopRightX()<<","<<R3.getTopRightY()<<")";
    cout<<"  BottomLeft("<<R3.getBottomLeftX()<<","<<R3.getBottomLeftY()<<")\n\n";
    cout<<"P1(2,3),P2(1,3)\n\n";
    Point2D P3=point1+point2;
    cout<<"P1+P2->("<<P3.getX()<<","<<P3.getY()<<")"<<endl<<endl;
    P3=point1*2;
     cout<<"P1*2->("<<P3.getX()<<","<<P3.getY()<<")"<<endl<<endl;
     return 0;






}
