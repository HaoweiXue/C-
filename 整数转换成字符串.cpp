/*
 * ex5_11.cpp
 *
 *  11. ��д������������ת�����ַ��������磺itoa(-123)��ת�����Ϊ��"-123"��
 *  ����ԭ��Ϊ��string itoa(int);
 *
 */


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
//�򵥷����� 
string itoa2(int num)//��num int->string 
{
	ostringstream os;
	os<<num;
	return os.str();
}
//���ӷ����� 
string itoa(int num)
{
	vector<char> v;
	char sign = 0;
	if(num == 0)
		return "0";
	if(num<0)	{
		sign = '-';
		num = -num;
	}
	while(num){
		v.push_back(num%10 + '0');
		num = num/10;
	}
	if(sign)
		v.push_back(sign);
	string number="";
	for(vector<char>::reverse_iterator ri= v.rbegin(); ri!=v.rend();ri++)//������� 
		number += *ri;//ע��������ۼ��÷��� 
	return number;
}

int main()
{
	cout<<"Please input a number:"<<endl;
	int num;
	cin>>num;
	cout<<itoa(num)<<endl;
	cout<<itoa2(num)<<endl;

}


