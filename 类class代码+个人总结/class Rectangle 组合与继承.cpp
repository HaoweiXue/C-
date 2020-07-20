/*
 * ex9_3.cpp
 *
  *      3. ��֪������Rectangle �Ķ������£�
 *      ��Rectangle ��Ļ����ϣ���Ʋ�ʵ��һ����������Square��
 */

#include <iostream>
using namespace std;
class Rectangle{
public:
	Rectangle(int wid=1, int hei=1):width(wid),height(hei){}
	int getWidth(){return width;}
	void setWidth(int newWid){width = newWid;}
	int getHeight(){return height;}
	void setHeight(int newHei){height = newHei;}
	int area(){return width*height;}//���
	int perimeter(){return (width+height)*2;}//�ܳ�
	void scale(double fw, double fh) {width*=fw; height*=fh;}//����
protected:
	double width, height;
};
//---------------------------
class Square : public Rectangle{
public:
	Square(int edge):Rectangle(edge,edge){}
	void scale(double fe){setWidth(getWidth()*fe); setHeight(getWidth());}
};
//-----------------------------
int main()
{
	Rectangle r(2,3);
	cout<<"Rectangle:"<<r.getHeight()<<","<<r.getWidth()<<endl;
	cout<<"area="<<r.area()<< "\tperimeter= "<<r.perimeter()<<endl;
	r.scale(1.5,2);
	cout<<"Rectangle:"<<r.getHeight()<<","<<r.getWidth()<<endl;
	cout<<"area="<<r.area()<< "\tperimeter= "<<r.perimeter()<<endl;
	Square s(3);
	cout<<"Square:"<<s.getHeight()<<","<<s.getWidth()<<endl;
	cout<<"area="<<s.area()<< "\tperimeter= "<<s.perimeter()<<endl;
	s.scale(2.5);
	cout<<"Square:"<<s.getHeight()<<","<<s.getWidth()<<endl;
	cout<<"area="<<s.area()<< "\tperimeter= "<<s.perimeter()<<endl;
}




