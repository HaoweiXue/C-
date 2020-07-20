/*
 * ex6_9.cpp
 * 9. ��Ʋ�ʵ��һ��������Rectangle��Ҫ��
 * ��1�������ϽǺ����½ǵ������������Σ�����ʹ�õ�5�ⶨ���Point�ࣩ��
 * ��2������������ܳ���
 * ��3���ƶ����Σ�
 * ��4������ĳ�ʼ����Ĭ�Ͽ�͸߶���1��
 * ��д���Գ���
 *
 *
 */
#include <iostream>
#include <cmath>//abs()->�����ֵ 
using namespace std;
//-------------------------------
class Rectangle;//ǰ����������  
class Point{
public:
	Point(int px =0, int py =0):x(px),y(py){}
	friend class Rectangle;//��Ԫ�࣬��ʹ��Point��˽�г�Ա�� 
private:
	int x,y;
};
//-------------------------------
class Rectangle{
public:
	Rectangle(int lux, int luy, int rdx=0, int rdy=0):leftup(lux,luy),rightdown(rdx,rdy){}//left->�� right->�� 
	double area()const{
		int x,y;
		x = leftup.x - rightdown.x;
		y = leftup.y - rightdown.y;
		return abs(x*y);
	}
	double perimeter()const{
		int x,y;
		x = abs(leftup.x - rightdown.x);
		y = abs(leftup.y - rightdown.y);
		return (x+y)*2;
	}
	void move(int x, int y=0){
		leftup.x += x;
		leftup.y += y;
		rightdown.x += x;
		rightdown.y += y;
	}
private:
	Point leftup, rightdown;
};
//-------------------------------
int main()
{
	Rectangle r(1,2,4,5);
	cout<<"area="<<r.area()<<endl;
	cout<<"perimeter="<<r.perimeter()<<endl;
	r.move(10,1);
}





