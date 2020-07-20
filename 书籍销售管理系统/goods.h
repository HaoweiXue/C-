/*
 * goods.h
 *
 */
// ifndef ���δ���� ͷ�����е�#ifndef������һ���ܹؼ��Ķ�����������������C�ļ���������C�ļ���include��ͬһ��ͷ�ļ���������ʱ��������C�ļ�Ҫһͬ�����һ���������ļ��������������ˣ�������������ͻ�� 

//���ǰ�ͷ�ļ������ݶ�����#ifndef��#endif�аɡ��������ͷ�ļ��᲻�ᱻ����ļ����ã��㶼Ҫ���������һ���ʽ�������ģ� 
//#ifndef <��ʶ> 
//#define <��ʶ> 




//...... 
//...... 



//#endif 



//<��ʶ>����������˵���������������ģ���ÿ��ͷ�ļ����������ʶ����Ӧ����Ψһ�ġ���ʶ����������һ����ͷ�ļ���ȫ��д��ǰ����»��ߣ������ļ����еġ�.��Ҳ����»��ߣ��磺stdio.h 


//#ifndef _STDIO_H_ 
//#define _STDIO_H_ 


//...... 



//#endif 
#ifndef GOODS_H_
#define GOODS_H_
#include <string>
#include <sstream>
using namespace std;
class Goods{
public:
	Goods(string t, double pr):title(t),price(pr){}//��Щ����Ĺ�ͬ���� title��price 
	virtual ~Goods(){}
	virtual double getPrice() {return price;}//�ṩ�ӿ� 
	virtual string getTitle() {return title;}//�ṩ�ӿ� 
	virtual string getDetails()=0;//�ṩ�ӿ� 
private:
	string title;
	double price;
};
//---------------------
class Book : public Goods{
public:
	Book(string t, double pr):Goods(t,pr){//�����Ѷ��壬��ʹ���乹�캯�� 
		author ="Unknown";
		press = "Unknown";//������ 
		ISBN = "Unknown";//���ʱ�׼ͼ���� 
	}
	~Book(){}
	void setDetails(string au, string pr, string isbn){
		author = au;
		press = pr;
		ISBN = isbn;
	}
	string getDetails(){
		ostringstream os;//ע���÷� 
		os<<"Title:"<<getTitle()<<"\t";
		os<<"Author:"<<author<<"\t";
		os<<"Press:"<<press<<"\t";
		os<<"ISBN:"<<ISBN<<"\t";
		os<<"Price:"<<getPrice()<<"\n";
		return os.str();
	}
private:
	string author;
	string press;
	string ISBN;
};
class Magazine : public Goods{
public:
	Magazine(string t, double pr):Goods(t,pr){
		issue = "Unknown";
		issNo = "Unknown";
		period = "Unknown";
	}
	~Magazine(){}
	void setDetails(string isn, string p,string is){
		issue = is;
		issNo = isn;
		period = p;
	}
	string getDetails(){
		ostringstream os;
		os<<"Title:"<<getTitle()<<"\t";
		os<<"IssueNo."<<issNo<<"\t";
		os<<"Period:"<<period<<"\t";
		os<<"Issue:"<<issue<<"\t";
		os<<"Price:"<<getPrice()<<"\n";
		return os.str();
	}
private:
	string issue;//�ں� 
	string issNo;//���п��� 
	string period;//��������
};
class MusicCD : public Goods{
public:
	MusicCD(string t, double p):Goods(t,p){
		player = "Unknown";
		style = "Unknown";
		tracks = 0;
		lasttime = 0;
	}
	~MusicCD(){}
	void setDetails(string p, string st,int tr, int t){
		player = p;
		style = st;
		tracks = tr;
		lasttime = t;
	}
	string getDetails(){
		ostringstream os;
		os<<"Title:"<<getTitle()<<"\t";
		os<<"Player:"<<player<<"\t";
		os<<"Style:"<<style<<"\t";
		os<<"Tracks:"<<tracks<<"\t";
		os<<"LastTime:"<<lasttime<<"minitues.\t";
		os<<"Price:"<<getPrice()<<"\n";
		return os.str();
	}
private:
	string player;
	string style;
	int tracks;
	int lasttime;
};
class Video : public Goods{
public:
	Video(string t, double p):Goods(t,p){
		description = "Unknown";
		lasttime = 0;
	}
	~Video(){}
	void setDetails(int t, string des){
		description = des;
		lasttime = t;
	}
	string getDetails(){
		ostringstream os;
		os<<"Title:"<<getTitle()<<"\t";
		os<<"Description:"<<description<<"\t";
		os<<"LastTime:"<<lasttime<<"minitues.\t";
		os<<"Price:"<<getPrice()<<"\n";
		return os.str();
	}
private:
	string description;//˵���� 
	int lasttime;
};
#endif /* GOODS_H_ */
