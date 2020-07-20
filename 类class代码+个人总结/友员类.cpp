/*
 * ex6_9.cpp
 * 9. 设计并实现一个矩形类Rectangle，要求：
 * （1）用左上角和右下角的坐标描述矩形（可以使用第5题定义的Point类）；
 * （2）计算面积、周长；
 * （3）移动矩形；
 * （4）合理的初始化；默认宽和高都是1；
 * 编写测试程序。
 *
 *
 */
#include <iostream>
#include <cmath>//abs()->求绝对值 
using namespace std;
//-------------------------------
class Rectangle;//前向引用声明  
class Point{
public:
	Point(int px =0, int py =0):x(px),y(py){}
	friend class Rectangle;//友元类，可使用Point中私有成员。 
private:
	int x,y;
};
//-------------------------------
class Rectangle{
public:
	Rectangle(int lux, int luy, int rdx=0, int rdy=0):leftup(lux,luy),rightdown(rdx,rdy){}//left->左 right->右 
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





