/*
 * ex6_8.cpp
 *
 * 8. ��Ʋ�ʵ��һ��Բ����Circle��Ҫ��
 * ��1����Բ�ĺͰ뾶����Բ�Σ�����ʹ�õ�5�ⶨ���Point�ࣩ��
 * ��2���ܹ���������������ܳ�����ȡ�뾶���ƶ������ţ�
 * ��3������ĳ�ʼ����Ĭ��Բ��Ϊԭ�㣬Ĭ�ϰ뾶Ϊ1��
 * ��д���Գ���
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
	static const double PI;//��̬���� 
};
const double Circle::PI = 3.1415926;//��̬�������ⶨ�� 
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

