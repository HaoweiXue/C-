/*
 * ex6_10.cpp
 *
 * 10. 设计并实现一个三角形类Triangle，要求：
 * （1）用三条边描述三角形；
 * （2）计算面积、周长；
 * （3）合理的初始化，注意检验三条边长度的合法性；默认三边长都为1；
 * 编写测试程序。
 *
 *
 */
#include<cassert>//判断 
#include<cmath>
#include <iostream>
using namespace std;
//-----------------------------------
class Triangle
{
public:
	Triangle(double a=1, double b=1, double c=1);
	~Triangle();
	double area()const;
	double perimeter()const;
	double getA()const;
	double getB()const;
	double getC()const;
	void setA(double a);
	void setB(double b);
	void setC(double c);
private:
	double a, b, c;
};
//----------------------------------
//global function
bool validate(double a, double b, double c)//验证 
{
	if((a<=0) || (b<=0) || (c<=0))
		return false;
	if((a+b<=c) || (a+c<=b) || (b+c<=a))
		return false;
	return true;
}
//--------------------------------

Triangle::Triangle(double x, double y, double z)
{
	bool v = validate(x,y,z);
	assert(v);//v为false退出 
	a=x; b=y; c=z;
}
Triangle::~Triangle()
{}
//virtual functions
double Triangle::area()const
{
	double p = (a+b+c)/2;
	double s = p*(p-a)*(p-b)*(p-c);
	return sqrt(s);//妙 
}
double Triangle::perimeter()const
{
	return a+b+c;
}
//others......
double Triangle::getA()const//访问器 
{ return a; }
double Triangle::getB()const
{ return b; }
double Triangle::getC()const
{ return c; }
void Triangle::setA(double d)//修改器 
{
	bool v = validate(d, b,c);
	assert(v);//v为false退出 
	a = d;
}
void Triangle::setB(double d)
{
	bool v = validate(a, d,c);
	assert(v);
	b = d;
}
void Triangle::setC(double d)
{
	bool v = validate(a, b,d);
	assert(v);
	c = d;
}


//--------------------------
int main(int argc, char *argv[])
{

	Triangle t(5,3,4);

	cout<<"Triangle t:\t"<<"a: "<<t.getA()
	<<"  b: "<<t.getB()<<" c: "<<t.getC()<<endl;
	cout<<"area="<<t.area()<<"\tperimeter="<<t.perimeter()<<endl;
}

