/*
 * ex10_3.cpp
 *
 *  3．利用抽象类和虚函数改写第9 章习题中的Shape 类层次。
 *  再编写一个totalArea()函数计算任意两个形状的面积之和。
 *
 */
#include <iostream>
#include <cmath>
#include <cassert>//断言 
using namespace std;
//-----------------------------------------
class Shape
{
public:
	virtual double area()const = 0;//含有纯虚函数的类为抽象类 
	virtual double perimeter()const = 0;
	virtual void scale(double factor) = 0;
};
//-----------------------------------------
class Triangle : public Shape//三角形 
{
public:
	Triangle(double a=1, double b=1, double c=1);
	double area()const;
	double perimeter()const;
	void scale(double factor);
	double getA(){return a;}
	double getB(){return b;}
	double getC(){return c;}
	//others......
private:
	double a, b, c;
	static bool validate(double a, double b, double c);
};
Triangle::Triangle(double x, double y, double z)
{
	bool v = validate(x,y,z);//调用成员函数 
	assert(v);//assert()->为true继续进行 ，为false停止进行。 
	a=x; b=y; c=z;
}

double Triangle::area()const
{
	double p = (a+b+c)/2;
	double s = p*(p-a)*(p-b)*(p-c);
	return sqrt(s);
}
double Triangle::perimeter()const
{
	return a+b+c;
}
//others......
void Triangle::scale(double factor){
	assert(factor>0);
	a *= factor;
	b *= factor;
	c *= factor;
}

bool Triangle::validate(double a, double b, double c)//验证 
{
	if((a<=0) || (b<=0) || (c<=0))
		return false;
	if((a+b<=c) || (a+c<=b) || (b+c<=a))
		return false;
	return true;
}
//----------------------------------
class Rectangle:public Shape//矩形 
{
public:
	Rectangle(double w=1.0,double h=1.0);
	double area()const;
	double perimeter()const;
	void scale(double f);
	double width(){return _width;}
	double height(){return _height;}
private:
	double _height;
	double _width;
};
Rectangle::Rectangle(double w,double h)
{ assert(w>0);
assert(h>0);
_width = w;
_height = h;
}
double Rectangle::area()const
{
	return _height*_width;
}
double Rectangle::perimeter()const
{
	return 2*(_height+_width);
}
void Rectangle::scale(double f)
{
	assert(f > 0);
	_height *= f;
	_width *= f;
}
//------------------------------
class Circle : public Shape//圆形 
{
public:
	Circle(double r = 1.0);
	double area()const;
	double perimeter()const;
	void scale(double factor);
	double getRadius(){return radius;}
private:
	double radius;
};
const double pi=3.1415926;
Circle::Circle(double r)
{
	assert(r>0);
	radius = r;
}
double Circle::area()const
{
	return pi*radius*radius;
}
double Circle::perimeter()const
{
	return pi*radius*2;
}
void Circle::scale(double f)
{
	assert(f>0);
	radius *= f;
}
//------------------------------------
double totalArea(Shape& s1, Shape& s2)
{
	return s1.area()+s2.area();
}
//-------------------------
int main()
{
	Rectangle r(5,3);
	cout<<"Rectangle r:\t"<<"width: "<<r.width()
	<<"\theight:"<<r.height()<<endl;
	cout<<"area="<<r.area()<<"\tperimeter="<<r.perimeter()<<endl;
	Circle c(4);
	cout<<"Circle c:\t"<<"radius: "<<c.getRadius()<<endl;
	cout<<"area="<<c.area()<<"\tperimeter="<<c.perimeter()<<endl;
	Triangle t(5,3,4);
	cout<<"Triangle t:\t"<<"a: "<<t.getA()
	<<"  b: "<<t.getB()<<" c: "<<t.getC()<<endl;
	cout<<"area="<<t.area()<<"\tperimeter="<<t.perimeter()<<endl;

	cout<<"totalArea(r,c)="<<totalArea(r,c)<<endl;
	cout<<"totalArea(r,t)="<<totalArea(r,t)<<endl;
	cout<<"totalArea(t,c)="<<totalArea(t,c)<<endl;
}





