/*
 * ex8_3.cpp
 * ch8
 * 3�����õ��������Ͳ��ܱ�ʾ���е���������Ϊ���붨��һ����������Rational����ʾ��
 ���������Ա�ʾΪ���������ıȣ���������Ҫ���������ʹ֮�ܹ�����������һ��ʹ�á�ʹ
 ��ʾ�����£�
 */

#include <string>
#include <iostream>
#include <cassert>//assert 
#include <sstream>
using namespace std;
//---------------------------------
const int SCALE = 100000;
class Rational {
public:
	//constructor
	Rational(int n, int d);
	Rational(int n) :
			Rational(n, 1) {//ί�й��캯�� c++11 
	}
	Rational() :
			Rational(0, 1) {//ί�й��캯�� c++11 
	}
	Rational(double val);
	//arithmatic operations��������
	Rational operator-() const;//ע�⣺�˴� constʹ�ú������С����ݳ�Ա��Ϊֻ�����͡����ɸ��ġ� 
	Rational operator+(const Rational& r) const;//&->˫�� 
	Rational operator-(const Rational& r) const;
	Rational operator*(const Rational& r) const;
	Rational operator/(const Rational& r) const;
	//conversionת�� ת�� ����
	string toString() const;//����ע�� 
	operator double() const;
	//overload ���� operator << and >>
	friend istream& operator>>(istream& in, Rational& r);
	friend ostream& operator<<(ostream& out, const Rational& r);
	//relational operations ��ϵ���� 
	friend bool operator==(const Rational& left, const Rational& right);
	friend bool operator!=(const Rational& left, const Rational& right);
	friend bool operator<(const Rational& left, const Rational& right);
	friend bool operator<=(const Rational& left, const Rational& right);
	friend bool operator>(const Rational& left, const Rational& right);
	friend bool operator>=(const Rational& left, const Rational& right);
private:
	int deno = 1;  //denominator����ĸ�� cannot be zero 	[Warning] non-static data member initializers only available with -std=c++11 or -std=gnu++11
	int nume = 0;  //numerator�����ӣ� c++11 
	//private operation��˽�в����� 
	static int gcd(int m, int n);
	static int iabs(int n);
};
//---------------------------

Rational::Rational(int n, int d) {	//validate
	assert(d != 0);//���� 
	if (n == 0) {
		nume = 0;
		deno = 1;
		return;
	}
	int g = gcd(iabs(d), iabs(n));//�����Լ�� 
	if (d > 0) {
		deno = d / g;
		nume = n / g;
	} else if (d < 0) {
		deno = -1 * d / g;
		nume = -1 * n / g;
	} else {
		deno = 1;
		nume = 0;
	}
}
Rational::Rational(double val) :
		Rational(static_cast<int>(val * SCALE), SCALE) {//	[Warning] delegating constructors only available with -std=c++11 or -std=gnu++11 
}

//arithmatic operations �������� 
Rational Rational::operator-() const {
	int d = deno;
	int n = -1 * nume;
	return Rational(n, d);
}

Rational Rational::operator+(const Rational& r) const {
	int d = deno * r.deno;
	int n = deno * r.nume + nume * r.deno;
	return Rational(n, d);
}
Rational Rational::operator-(const Rational& r) const {
	int d = deno * r.deno;
	int n = nume * r.deno - deno * r.nume;
	return Rational(n, d);
}
Rational Rational::operator*(const Rational& r) const {
	int d = deno * r.deno;
	int n = nume * r.nume;
	return Rational(n, d);
}
Rational Rational::operator/(const Rational& r) const {
	int d = deno * r.nume;
	int n = nume * r.deno;
	return Rational(n, d);
}
//conversion ת�� 
string Rational::toString() const {
	ostringstream val;
	val << nume;
	if (deno != 1)
		val << "/" << deno;
	return val.str();
}

Rational::operator double() const {
	return (nume * 1.0) / deno;
}

int Rational::gcd(int m, int n) {
	int g = m < n ? m : n;
	while (g > 1) {
		if (m % g == 0 && n % g == 0)
			break;
		--g;
	}
	return g;
}

int Rational::iabs(int n) {
	if (n < 0)
		return -1 * n;
	else
		return n;
}

//relational operations
bool operator ==(const Rational& left, const Rational& right) {//��Ԫ������������ 
	Rational temp = left - right;//C:\Users\Admin\Desktop\2\main.cpp|13|����:'bool������==(const Shape*�� const Shape*)'������һ�����ö������|�Ĳ��� 
	if(temp.nume == 0)
		return true;
	else
		return false;

}

bool operator !=(const Rational& left, const Rational& right) {
	return !(left == right);
}

bool operator <(const Rational& left, const Rational& right) {
	Rational temp = left - right;
	if(temp.nume < 0)
		return true;
	else
		return false;
}

bool operator <=(const Rational& left, const Rational& right) {
	return (left == right || left < right);
}

bool operator >(const Rational& left, const Rational& right) {
	return (right < left)&&(left != right);
}

bool operator >=(const Rational& left, const Rational& right) {
	return !(left < right);
}
//operator << and >>
istream& operator>>(istream& in, Rational& r) {
	int n, d;
	in >> n >> d;
	r = Rational(n, d);  //create a rational
	return in;
}
ostream& operator<<(ostream& out, const Rational& r) {
	out << r.toString();
	return out;
}

int main() {
	Rational r1; 			//r1=0
	Rational r2(1, 2); 		//r2 = 1/2
	Rational r3(-2, 3); 	//r3 = -2/3
	Rational r4(1.5); 		//double ת��ΪRational
	cout << r1 << endl;
	cout << r2 << endl;
	cout << r3 << endl;
	cout << r4 << endl;

	cout << "please input r1:" << endl;
	cin >> r1; //����
	cout << r2 << endl; 		//�������ʽΪ 1/2
	cout << -r1 << endl; 		//һԪ+,������
	cout << r1 + r3 << endl; 	//��Ԫ�������㣺+,-,*,/
	cout <<(r2<r1) << endl; 	//��ϵ������߼�����
	r4 = r1 / r2; 				//��ֵ����͸��ϸ�ֵ����
	double d;
	d = r4; 					//Rational ת��Ϊdouble
	cout << d << "\t" << r4 << endl;
	return 0;
}
