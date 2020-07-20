/*
 * ex6_11.cpp
 * 11. ��Ʋ�ʵ��һ����������Rational��Ҫ��
 * ��1�������������ı�������������
 * ��2���ܹ����мӼ��˳����������㣻
 * ��3���Է�����ʽ�����������
 * ��4���ṩdouble���͵�������������ת����
 * ��5������ĳ�ʼ����ע�����ĸ�ͳ���Ϊ0�Ĵ���Ĭ�Ϸ���Ϊ0����ĸΪ1��
 * ��д���Գ���
 *
 */
//--------------------------
//rational.h
#include <string>
#include <cassert>
#include <sstream>
#include <iostream>
using namespace std;
class Rational{
public:
	//constructor
	Rational(int n=0, int d=1);
	//arithmatic operations
	Rational add(const Rational& r)const;
	Rational sub(const Rational& r)const;
	Rational mul(const Rational& r)const;
	Rational div(const Rational& r)const;
	//conversion
	string toString()const;
	double toDouble()const;

private:
	int nume = 0;  //numerator
	int deno = 1;  //denominator cannot be zero
	//private operation
	static int gcd(int m, int n);
};
//--------------------
//rational.cpp
Rational::Rational(int n, int d)
{//validate
	assert(d!=0);

	if(n == 0){
		nume = 0;
		deno = 1;
		return;
	}

	if(d < 0){
		nume = -1 * n;
		deno = -1 * d;
	}
	else{
		nume = n;
		deno = d;
	}//���������� nume������ 

	int g;
	if(nume > 0)
		g = gcd(nume, deno);
	else
		g = gcd(-nume, deno);

	nume /= g;
	deno /= g;

}
//arithmatic operations
Rational Rational::add(const Rational& r)const// const->���ܸı䵱ǰ�������ݣ�ֻ�ܶ��� 
{
	int d = deno * r.deno;
	int n = deno * r.nume + nume * r.deno;
	return Rational(n, d);
}

Rational Rational::sub(const Rational& r)const
{
	int d = deno * r.deno;
	int n = nume * r.deno - deno * r.nume;
	return Rational(n, d);
}
Rational Rational::mul(const Rational& r)const
{
	return Rational(nume * r.nume, deno * r.deno);
}
Rational Rational::div(const Rational& r)const
{
	return Rational(nume * r.deno, deno * r.nume);
}
//conversion
string Rational::toString()const
{
	ostringstream val;

	if(nume == 0)
		val << 0;
	else if(deno == 1)
		val << nume;
	else
		val << nume << "/" << deno;

	return val.str();
}

double Rational::toDouble()const
{
	return  static_cast<double>(nume)/deno;
}

int Rational::gcd(int m, int n){
	int g = (m < n) ? m : n;
	while(g > 1){
		if(m % g == 0 && n % g == 0)
			break;
		--g;
	}
	return g;
}


//---------------------
int main()
{
	Rational r1; //0
	Rational r2(2);//2/1
	Rational r3(-3,-4); //3/4
	Rational r4(3, -6);

	cout<<"r1: "<<r1.toString()<<endl;
	cout<<"r2: "<<r2.toString()<<endl;
	cout<<"r3: "<<r3.toString()<<endl;
	cout<<"r4: "<<r4.toString()<<endl;

	cout<<"double value of r1: "<<r1.toDouble()<<endl;
	cout<<"double value of r2: "<<r2.toDouble()<<endl;
	cout<<"double value of r3: "<<r3.toDouble()<<endl;
	cout<<"double value of r4: "<<r4.toDouble()<<endl;

	cout<<"r2+r3: "<<r2.add(r3).toString()<<endl;
	cout<<"r2-r3: "<<r2.sub(r3).toString()<<endl;
	cout<<"r2*r3: "<<r2.mul(r3).toString()<<endl;
	cout<<"r2/r3: "<<r2.div(r3).toString()<<endl;


	cout<<"r4+r3: "<<r4.add(r3).toString()<<endl;
	cout<<"r4-r3: "<<r4.sub(r3).toString()<<endl;
	cout<<"r4*r3: "<<r4.mul(r3).toString()<<endl;
	cout<<"r4/r3: "<<r4.div(r3).toString()<<endl;
}




