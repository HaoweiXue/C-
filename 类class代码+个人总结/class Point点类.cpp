/*
 * 5.��Ʋ�ʵ��һ��ƽ�����Point��Ҫ��
 * ��1����x,y��������ֵ��ʾһ���㣻
 * ��2����ȷ��ʼ��ÿ���㣻Ĭ������ֵΪԭ�㣻
 * ��3������㵽ԭ��ľ��룻
 * ��4�����㵽��һ����ľ��룻
 * ��5����ȡ���x��y����ֵ��//������getter 
 * ��6�����õ��x��y���ꣻ//�޸���setter 
 * ��7���ƶ��㵽��λ�ã�
 * ��д���Գ���
 *
 *
 */
#include <iostream>
#include <cmath>
using namespace std;
//---------------------------------
class Point{
public:
	Point(int px=0, int py=0):x(px),y(py){}

	double distance()const;
	double distance(Point& pt)const;

	int getX()const {return x;}
	int getY()const {return y;}
	void setX(int px){x = px;}
	void setY(int py){y = py;}

	void moveto(const Point& pt);
	void moveto(int px, int py);
private:
	int x = 0;
	int y = 0;
};
double Point::distance()const {
	return sqrt(x*x+y*y);
}
double Point::distance(Point& pt)const{
	int a = pt.x - x;
	int b = pt.y - y;
	return sqrt(a*a + b*b);
}
void Point::moveto(const Point& pt){
	x = pt.x; y = pt.y;
}
void Point::moveto(int px, int py){
	x = px; y = py;
}
//-------------------------------------------
int main()
{
	Point p1(1,3), p2(4,5), p3(2);
	cout<<"p1: "<<p1.getX()<<","<<p1.getY()<<endl;
	cout<<"p1 to origin:"<<p1.distance()<<endl;
	cout<<"p2:"<<p2.getX()<<","<<p2.getY()<<endl;
	cout<<"p1 to p2:"<<p1.distance(p2)<<endl;
	p1.moveto(p3);
	cout<<"p1 moveto p3:"<<p1.getX()<<","<<p1.getY()<<endl;
}

