#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
class Point2D
{
    int vuj,koti;
    public:
    void setX(int x)
    {
        vuj=x;
    }
    void setY(int y)
    {
       koti=y;
    }
    int getX()
    {
       return vuj;
    }
    int getY()
    {
        return koti;
    }
    ~Point2D()
    {
     vuj=0;
     koti=0;
    }
};
class Circle
{
      int centerX,centerY;
public:
    double radius;
    Circle();
    Circle(Point2D c,double r);
    ~Circle();
    void setValues(int x1,int y1,double r1)
    {
        centerX=x1;
        centerY=y1;
        radius=r1;
    }
    int getCenterX()
    {
        return centerX;
    }
     int getCenterY()
    {
        return centerY;
    }
    int getRadius()
    {
        return radius;
    }
    void intersect(Circle rhs)
    {
        int distance1,distance2;
        distance1=(radius+rhs.radius)*(radius+rhs.radius);
        distance2=pow(centerX-rhs.centerX,2)+pow(centerX-rhs.centerY,2);
        if(distance1>distance2||distance1==distance2)
        {
            cout<<"The two circles intersect"<<endl;
        }
        else cout<<"The two circles dont intersect"<<endl;
    }
    void contains(Circle rhs)
    {
        float d,d1;
        d=pow(rhs.centerX-centerX,2)+pow(rhs.centerY-centerY,2);
        d1=sqrt(d)+rhs.radius;
        if(radius>=d1) cout<<"The rhs circle contains in the first one"<<endl;
        else cout<<"The rhs circle does not contain in the second one"<<endl;

    }
    int contains(Point2D p)
    {

        float d;
        d=pow(p.getX()-centerX,2)+pow(p.getY()-centerY,2);
        if(d<radius*radius||d==radius*radius) return 1;
               // cout<<"The circle contains the point"<<endl;
            else return 0; //cout<<"The circle does not contain the point"<<endl;


    }
    double perimeter()
    {
        return 2*3.1416*radius;

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
    int Area;
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
       Area=0;
    }
    Rectangle(Point2D P1,Point2D P2)
    {
        TopRight.setX(P1.getX());
        TopRight.setY(P1.getY());
        BottomLeft.setX(P2.getX());
        BottomLeft.setY(P2.getY());
    }
    void setValues(int x1,int y1,int x2,int y2)
    {
       int  TopLeftX,TopLeftY,BottomRightX,BottomRightY;
       TopRight.setX(x1);
       TopRight.setY(y1);
       BottomLeft.setX(x2);
       BottomLeft.setY(y2);
        TopLeftX=TopRight.getX()-(abs(TopRight.getX())-abs(BottomLeft.getX()));
       TopLeftY=TopRight.getY()-(abs(TopRight.getY())-abs(BottomLeft.getY()));
       BottomRightX=BottomLeft.getX()+(abs(TopRight.getX())-abs(BottomLeft.getX()));
        BottomRightY=BottomLeft.getY()+(abs(TopRight.getY())-abs(BottomLeft.getY()));
       TopLeft.setX(TopLeftX);
       TopLeft.setY(TopLeftY);
       BottomRight.setX(BottomRightX);
       BottomRight.setY(BottomRightY);
    }
    int getTopRightX()
    {
        return TopRight.getX();
    }
    int getTopRightY()
      {
          return TopRight.getY();
      }
      int getBottomLeftX()
      {
          return BottomLeft.getX();
      }
        int getBottomLeftY()
      {
          return BottomLeft.getY();
      }
      int getTopLeftX()
      {
          return TopLeft.getX();
      }
      int getTopLeftY()
      {
          return TopLeft.getY();
      }
      int getBottomRightX()
      {
          return BottomRight.getX();
      }
      int getBottomRightY()
      {
          return BottomRight.getY();
      }
       int area()
      {
          int width,length;
          width=abs(TopRight.getX())-abs(BottomLeft.getX());
          length=abs(TopRight.getY())-abs(BottomLeft.getY());

           return width*length;//The rectangle is assumed to be in parallel axis
      }
      int perimeter()
      {
          int width,length;
          width=abs(TopRight.getX())-abs(BottomLeft.getX());
          length=abs(TopRight.getY())-abs(BottomLeft.getY());

           return 2*(width+length);

      }
      void intersect(Rectangle rhs)
      {
          if(getTopLeftX()>=rhs.getBottomRightX()||getBottomRightX()<=rhs.getTopLeftX()||getTopLeftY()<=rhs.getBottomRightY()||getBottomRightY()>=rhs.getTopLeftY())
             cout<<"The two rectangle intersect with each other"<<endl;
          else cout<<"They donot intersect"<<endl;

      }
      void contains(Rectangle rhs)
      {
          if(getBottomLeftX()<rhs.getBottomLeftX()&&getBottomLeftY()<rhs.getBottomLeftY()&&getTopRightY()>rhs.getTopRightY()&&getTopRightX()>rhs.getTopRightX())
             cout<<"The rectangle contains rhs rectangle"<<endl;
             else cout<<"The rectangle does not contain rhs rectangle"<<endl;
      }
      void inside(Circle C)
      {
          int t1,t2,t3,t4;
          t1=C.contains(TopLeft);
          t2=C.contains(TopRight);
          t3=C.contains(BottomLeft);
          t4=C.contains(BottomRight);
          if(t1==1&&t2==1&&t3==1&&t4==1) cout<<"The rectangle is fully inside the circle"<<endl;
          else cout<<"The rectangle is not inside the circle"<<endl;


      }
      ~Rectangle()
      {
          TopRight.setX(0);
       TopRight.setY(0);
       BottomLeft.setX(0);
       BottomLeft.setY(0);
       Area=0;
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
     Circle c2;
     c2.setValues(11,12,10.1);
     c1.setValues(0,0,4);
     c1.intersect(c2);
     c1.contains(c2);
    if(c1.contains(point2)) cout<<"The circle contains the point"<<endl;
    else cout<<"The circle does not contain the point"<<endl;
     cout<<"The perimeter of the circle is "<<c1.perimeter()<<" unit"<<endl;
     R1.setValues(4,4,2,2);
     R2.setValues(3,3,1,1);
     cout<<"The area of R1 is "<<R1.area()<<" square unit"<<endl;
    cout<<"The perimeter of R1 is "<<R1.perimeter()<<" unit"<<endl;
    R1.intersect(R2);
    R1.contains(R2);
    R1.inside(c1);


}
