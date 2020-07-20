/*
 * ex10_3.cpp
 *
 *  3�����ó�������麯����д��9 ��ϰ���е�Shape ���Ρ�
 *  �ٱ�дһ��totalArea()������������������״�����֮�͡�
 *
 */
#include <iostream>
#include <cmath>
#include <cassert>//���� 
using namespace std;
//-----------------------------------------
class Shape
{
public:
	virtual double area()const = 0;//���д��麯������Ϊ������ 
	virtual double perimeter()const = 0;
	virtual void scale(double factor) = 0;
};
//-----------------------------------------
class Triangle : public Shape//������ 
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
	bool v = validate(x,y,z);//���ó�Ա���� 
	assert(v);//assert()->Ϊtrue�������� ��Ϊfalseֹͣ���С� 
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

bool Triangle::validate(double a, double b, double c)//��֤ 
{
	if((a<=0) || (b<=0) || (c<=0))
		return false;
	if((a+b<=c) || (a+c<=b) || (b+c<=a))
		return false;
	return true;
}
//----------------------------------
class Rectangle:public Shape//���� 
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
class Circle : public Shape//Բ�� 
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





