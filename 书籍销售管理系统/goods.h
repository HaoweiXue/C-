/*
 * goods.h
 *
 */
// ifndef 如果未定义 头件的中的#ifndef，这是一个很关键的东西。比如你有两个C文件，这两个C文件都include了同一个头文件。而编译时，这两个C文件要一同编译成一个可运行文件，于是问题来了，大量的声明冲突。 

//还是把头文件的内容都放在#ifndef和#endif中吧。不管你的头文件会不会被多个文件引用，你都要加上这个。一般格式是这样的： 
//#ifndef <标识> 
//#define <标识> 




//...... 
//...... 



//#endif 



//<标识>在理论上来说可以是自由命名的，但每个头文件的这个“标识”都应该是唯一的。标识的命名规则一般是头文件名全大写，前后加下划线，并把文件名中的“.”也变成下划线，如：stdio.h 


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
	Goods(string t, double pr):title(t),price(pr){}//这些货物的共同点是 title与price 
	virtual ~Goods(){}
	virtual double getPrice() {return price;}//提供接口 
	virtual string getTitle() {return title;}//提供接口 
	virtual string getDetails()=0;//提供接口 
private:
	string title;
	double price;
};
//---------------------
class Book : public Goods{
public:
	Book(string t, double pr):Goods(t,pr){//基类已定义，可使用其构造函数 
		author ="Unknown";
		press = "Unknown";//出版社 
		ISBN = "Unknown";//国际标准图书编号 
	}
	~Book(){}
	void setDetails(string au, string pr, string isbn){
		author = au;
		press = pr;
		ISBN = isbn;
	}
	string getDetails(){
		ostringstream os;//注意用法 
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
	string issue;//期号 
	string issNo;//发行刊号 
	string period;//发行周期
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
	string description;//说明书 
	int lasttime;
};
#endif /* GOODS_H_ */
