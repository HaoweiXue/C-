/*
 * ex6_7.cpp
 *
 * 7. 实现复数类ComplexNumber
 * 复数加、减、乘、除的公式如下：
 (a+bi) + (c+di) = (a+c) + (b+d)i
 (a+bi) - (c+di) = (a-c) + (b-d)i
 (a+bi) * (c+di) = (ac-bd) + (bc + ad)i
 (a+bi) / (c+di) = (ac+bd)/(c2+d2) + (bc-ad)i/(c2+d2)
 *
 */

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class ComplexNumber{
public:
	ComplexNumber(double r = 0, double i = 0): real(r), imag(i){}

	double getImaginary() const;
	double getReal() const;

	string toString()const;//常用 

	ComplexNumber add(const ComplexNumber& c)const;
	ComplexNumber sub(const ComplexNumber& c)const;
	ComplexNumber mul(const ComplexNumber& c)const;
	ComplexNumber div(const ComplexNumber& c)const;

private:
	double real = 0;//0
	double imag = 0;

};

double ComplexNumber::getImaginary() const {
	return imag;
}

double ComplexNumber::getReal() const {
	return real;
}

string ComplexNumber::toString() const {//常用 
	ostringstream os;
	if(real == 0){
		if(imag == 0)
			os << 0;
		else
			os << imag << "i";
	}
	else{
		if(imag == 0)
			os << real;
		else if(imag  > 0)
			os << real << "+" << imag << "i";
		else
			os << real << imag << "i";
	}

	return os.str();//注意 
}

ComplexNumber ComplexNumber::add(const ComplexNumber& c) const {
	return ComplexNumber(real + c.real, imag + c.imag);
}

ComplexNumber ComplexNumber::sub(const ComplexNumber& c) const {
	return ComplexNumber(real - c.real, imag - c.imag);
}
//(a+bi) * (c+di) = (ac-bd) + (bc + ad)i
//(a+bi) / (c+di) = (ac+bd)/(c2+d2) + (bc-ad)i/(c2+d2)
ComplexNumber ComplexNumber::mul(const ComplexNumber& c) const {
	ComplexNumber cn;
	cn.real = real * c.real - imag * c.imag;
	cn.imag = imag * c.real + real * c.imag;
	return cn;
}

ComplexNumber ComplexNumber::div(const ComplexNumber& c) const {
	ComplexNumber cn;

	double cds = c.real * c.real + c.imag * c.imag;

	cn.real = (real * c.real + imag * c.imag) / cds;
	cn.imag = (imag * c.real - real * c.imag) / cds;

	return cn;
}

//------------------------------

int main()
{
	ComplexNumber c1(1, 2), c2(3, 4), c3(-3, 2), c4(2, -4), c5(-1, -2), c6;

	cout <<"c1: " << c1.toString() << endl;
	cout <<"c2: " << c2.toString() << endl;
	cout <<"c3: " << c3.toString() << endl;
	cout <<"c4: " << c4.toString() << endl;
	cout <<"c5: " << c5.toString() << endl;
	cout <<"c6: " << c6.toString() << endl;

	cout <<"c1 + c2 = " << c1.add(c2).toString() << endl;
	cout <<"c3 + c2 = " << c3.add(c2).toString() << endl;
	cout <<"c4 + c2 = " << c4.add(c2).toString() << endl;

	cout <<"c1 - c2 = " << c1.sub(c2).toString() << endl;
	cout <<"c1 * c2 = " << c1.mul(c2).toString() << endl;
	cout <<"c1 / c2 = " << c1.div(c2).toString() << endl;
	return 0;
}

