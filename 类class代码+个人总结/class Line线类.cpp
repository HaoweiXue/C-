/*
 * ex9_5.cpp
 *
 *      5. 已知平面点Point 类的声明如下：
 *      在Point 的基础上，设计并实现一个线段类Line。
 *      要求支持线段的平移、伸缩、计算长度等操作。
 */
#include <iostream>
#include <cmath>
using namespace std;

class Point {
public:
	Point(int x=0, int y=0):px(x),py(y){}
	~Point(){}
	int getX()const{return px;}
	int getY()const{return py; }
	void setX(int x) {px = x;}
	void setY(int y) {py = y; }
	void moveto(int x, int y){setX(x); setY(y);}
	double distance(const Point& pt){
		int dx, dy;
		dx = pt.px - px;
		dy = pt.py - py;
		return sqrt(dx*dx+dy*dy);
	}

private:
	int px,py;
};
class Line{
public:
	Line(int x1, int y1, int x2=0, int y2=0):p1(x1,y1),p2(x2,y2){}
	Line(const Point& pt1, const Point& pt2):p1(pt1),p2(pt2){}
	void moveX(int dis){
		p1.setX(p1.getX() + dis);
		p2.setX(p2.getX() + dis);
	}
	void moveY(int dis){
		p1.setY(p1.getY() + dis);
		p2.setY(p2.getY() + dis);
	}
	double length(){return p1.distance(p2);}
private:
	Point p1,p2;
};

int main()
{
	Point p1(1,2),p2(3,4);
	Line line1(3,4),line2(p1,p2);
	cout<<"line1:"<<line1.length()<<endl;
	cout<<"line2:"<<line2.length()<<endl;
}






