/*
 * 5.设计并实现一个平面点类Point，要求：
 * （1）用x,y两个坐标值表示一个点；
 * （2）正确初始化每个点；默认坐标值为原点；
 * （3）计算点到原点的距离；
 * （4）计算到另一个点的距离；
 * （5）获取点的x、y坐标值；//访问器getter 
 * （6）设置点的x、y坐标；//修改器setter 
 * （7）移动点到新位置；
 * 编写测试程序。
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

