/*
 * ex6_8.cpp
 *
 * 8. 设计并实现一个圆形类Circle，要求：
 * （1）由圆心和半径描述圆形（可以使用第5题定义的Point类）；
 * （2）能够计算面积、计算周长、获取半径、移动和缩放；
 * （3）合理的初始化；默认圆心为原点，默认半径为1；
 * 编写测试程序。
 *
 */
#include <iostream>
using namespace std;
//--------------------------------
class Circle{
public:
	Circle(double r, int px=0, int py=0);
	double area()const;
	double perimeter()const;
	double getRadius()const{return radius;}
	void moveto(int px, int py){ x = px; y = py; }
	void scale(double fac){ radius *= fac; }
private:
	double radius;
	int x,y;
	static const double PI;//静态数据 
};
const double Circle::PI = 3.1415926;//静态数据类外定义 
Circle::Circle(double r, int px, int py){
	radius =r;
	x = px;
	y = py;
}
double Circle::area()const{
	return PI*radius*radius;
}
double Circle::perimeter()const{
	return PI*radius*2;
}

//--------------------------------
int main()
{
	Circle c1(2.5);
	cout<<"c1: radius="<<c1.getRadius()<<endl;
	cout<<"area="<<c1.area()<<endl;
	cout<<"perimeter="<<c1.perimeter()<<endl;
	c1.scale(2);
	cout<<"c1: radius="<<c1.getRadius()<<endl;
	cout<<"area="<<c1.area()<<endl;
	cout<<"perimeter="<<c1.perimeter()<<endl;
}

