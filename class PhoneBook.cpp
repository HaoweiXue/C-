/*
 * ex9_8.cpp
 *
 *  8. ��Ʋ�ʵ��һ���绰��PhoneBook �ࡣҪ�����¡�
��1���绰����ÿ����ĿΪ�����͵绰���룬�硰LionelMessi 34-93-4963600����ÿ����
���������ܹ��������Ŀ���ڳ�ʼ��ʱָ������PhoneBook pb(200)������һ���绰��pb��
���ౣ��200 ����¼��
��2��֧����绰����������Ŀ�����Һ�ɾ��ָ����Ŀ��
��3��֧�ֶ��ֲ��ҷ�ʽ��ָ����Ŀ��š�ָ��������ָ�����롣
��4��֧������������Ϊ�±���Һ���Ĺ��ܣ��磬�ڵ绰��pb �в���Lionel Messi
�ĵ绰���룬�����ʽΪpb[LionelMessi]�����Ϊ34-93-4963600��
��5��֧������绰���Ĺ��ܣ����ն˻��ļ���������绰����Ŀ��ֱ��Ctrl+Z ����
���롣
��6��֧�ֵ绰����������ܣ����绰��������������ն˻��ļ���ÿ��һ����Ŀ��
��7�������������Ϊ��Ҫ��������ơ�
 */

#include <iostream>
#include <string>
#include <vector>//vector list����ʹ�� 
using namespace std;
//phonebook.h
struct PhoneItem{
	string name;
	string number;
	PhoneItem(const string& nm, const string& num):name(nm),number(num){}
	void list(ostream& os=cout) {os<<name<<"\t"<<number<<"\n";}//ע���÷� 
};
class PhoneBook{
public:
	PhoneBook(int sz=100);//����������������ô����Ĳ�����������Ĭ��ֵ�� 
	void addItem(const string& name, const string& number);
	void delItem(const string& name);
	const string findByName(const string& name);
	const string operator[](const string& name);
	const string findByNumber(const string& number);
	const string findByNo(int no);
	void importFrom(istream& is = cin);//ע���÷� 
	void exportTo(ostream& os = cout);//ע���÷� 
	void listAll();
private:
	vector<PhoneItem> items;
	int size;
};

//phonebook.cpp
PhoneBook::PhoneBook(int sz){//��Ա�������Գ�ʼ�������ã��ı����ݳ�Ա��ֵ�� 
	if(sz <= 0)
		size = 100;
	else
		size = sz;
}
void PhoneBook::addItem(const string& name, const string& number)
{
	items.push_back(PhoneItem(name,number));//ע���÷� 

}
void PhoneBook::delItem(const string& name)
{
	vector<PhoneItem>::iterator it;// ������ ע���÷� 
	for(it=items.begin(); it!=items.end(); it++){
		if (it->name == name)
			break;
	}
	if(it!=items.end())//�ҵ�Ŀ�� 
		items.erase(it);//ע���÷� erase������ 
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
const string PhoneBook::operator[](const string& name)//��������� 
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

	return (items[no].name+" "+items[no].number);//ע���÷� 
}
void PhoneBook::importFrom(istream& is)//ע���÷� ��cin 
{
	string name, number;
	while(is>>name>>number)
		items.push_back(PhoneItem(name,number));//ctrl+zֹͣ 
}
void PhoneBook::exportTo(ostream& os)//ע���÷� ��cout 
{
	vector<PhoneItem>::iterator it;
	for(it=items.begin(); it!=items.end(); it++){
		it->list(os);
	}
}
void PhoneBook::listAll()
{
	exportTo(cout);//ע���÷� ��Ա������ʹ�ó�Ա���� ,������������ 
}
//-----------------------------------
int main()
{
	PhoneBook pb;
	pb.importFrom(cin);//ע���÷� 
	pb.listAll();
	cout<<pb.findByName("messi")<<endl;
	cout<<pb.findByNo(2)<<endl;
	cout<<pb.findByNumber("12345")<<endl;
	pb.addItem("xavi","8900012");
	pb.listAll();
	pb.delItem("xavi");
	pb.listAll();
}



