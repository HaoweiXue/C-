/*
 * ex9_8.cpp
 *
 *  8. 设计并实现一个电话簿PhoneBook 类。要求如下。
（1）电话簿中每个条目为姓名和电话号码，如“LionelMessi 34-93-4963600”，每个电
话簿对象能够保存的条目数在初始化时指定，如PhoneBook pb(200)，创建一个电话簿pb，
至多保存200 条记录。
（2）支持向电话簿中增加条目、查找和删除指定条目。
（3）支持多种查找方式：指定条目编号、指定姓名、指定号码。
（4）支持利用姓名作为下标查找号码的功能：如，在电话簿pb 中查找Lionel Messi
的电话号码，输入格式为pb[LionelMessi]，输出为34-93-4963600。
（5）支持输入电话簿的功能：从终端或文件逐行输入电话簿条目，直到Ctrl+Z 结束
输入。
（6）支持电话簿的输出功能：将电话簿的内容输出到终端或文件，每行一个条目。
（7）可以添加你认为必要的其他设计。
 */

#include <iostream>
#include <string>
#include <vector>//vector list都可使用 
using namespace std;
//phonebook.h
struct PhoneItem{
	string name;
	string number;
	PhoneItem(const string& nm, const string& num):name(nm),number(num){}
	void list(ostream& os=cout) {os<<name<<"\t"<<number<<"\n";}//注意用法 
};
class PhoneBook{
public:
	PhoneBook(int sz=100);//如果传来参数，则用传来的参数，否则用默认值。 
	void addItem(const string& name, const string& number);
	void delItem(const string& name);
	const string findByName(const string& name);
	const string operator[](const string& name);
	const string findByNumber(const string& number);
	const string findByNo(int no);
	void importFrom(istream& is = cin);//注意用法 
	void exportTo(ostream& os = cout);//注意用法 
	void listAll();
private:
	vector<PhoneItem> items;
	int size;
};

//phonebook.cpp
PhoneBook::PhoneBook(int sz){//成员函数可以初始化，引用，改变数据成员的值。 
	if(sz <= 0)
		size = 100;
	else
		size = sz;
}
void PhoneBook::addItem(const string& name, const string& number)
{
	items.push_back(PhoneItem(name,number));//注意用法 

}
void PhoneBook::delItem(const string& name)
{
	vector<PhoneItem>::iterator it;// 迭代器 注意用法 
	for(it=items.begin(); it!=items.end(); it++){
		if (it->name == name)
			break;
	}
	if(it!=items.end())//找到目标 
		items.erase(it);//注意用法 erase（）； 
}
const string PhoneBook::findByName(const string& name)
{
	vector<PhoneItem>::iterator it;
	for(it=items.begin(); it!=items.end(); it++){
		if (it->name == name)
			break;
	}
	if(it!=items.end())
		return it->number;
	else
		return "";
}
const string PhoneBook::operator[](const string& name)//运算符重载 
{
	return findByName(name);
}
const string PhoneBook::findByNumber(const string& number)
{
	vector<PhoneItem>::iterator it;
	for(it=items.begin(); it!=items.end(); it++){
		if (it->number == number)
			break;
	}
	if(it!=items.end())
		return it->name;
	else
		return "";

}
const string PhoneBook::findByNo(int no)
{

	return (items[no].name+" "+items[no].number);//注意用法 
}
void PhoneBook::importFrom(istream& is)//注意用法 传cin 
{
	string name, number;
	while(is>>name>>number)
		items.push_back(PhoneItem(name,number));//ctrl+z停止 
}
void PhoneBook::exportTo(ostream& os)//注意用法 传cout 
{
	vector<PhoneItem>::iterator it;
	for(it=items.begin(); it!=items.end(); it++){
		it->list(os);
	}
}
void PhoneBook::listAll()
{
	exportTo(cout);//注意用法 成员函数里使用成员函数 ,不需其他修饰 
}
//-----------------------------------
int main()
{
	PhoneBook pb;
	pb.importFrom(cin);//注意用法 
	pb.listAll();
	cout<<pb.findByName("messi")<<endl;
	cout<<pb.findByNo(2)<<endl;
	cout<<pb.findByNumber("12345")<<endl;
	pb.addItem("xavi","8900012");
	pb.listAll();
	pb.delItem("xavi");
	pb.listAll();
}



