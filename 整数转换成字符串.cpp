/*
 * ex5_11.cpp
 *
 *  11. 编写函数，将整数转换成字符串。例如：itoa(-123)，转换结果为："-123"。
 *  函数原型为：string itoa(int);
 *
 */


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
//简单方法： 
string itoa2(int num)//将num int->string 
{
	ostringstream os;
	os<<num;
	return os.str();
}
//复杂方法： 
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
	for(vector<char>::reverse_iterator ri= v.rbegin(); ri!=v.rend();ri++)//反向遍历 
		number += *ri;//注意这里的累加用法。 
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


