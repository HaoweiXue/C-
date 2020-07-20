#include <iostream>
#include <cstdlib>
using namespace std;

class Complex
{
    float real;
    float imag;
public:
    Complex(float r=0,float i=0)
    {
        real = r;
        imag = i;
    }
    const Complex operator+(const Complex &other)
    {
        Complex r;
        r.real = real + other.real;
        r.imag = imag + other.imag;
        return r;
    }
    const Complex operator+(float x)
    {
        Complex r;
        r.real = real+x;
        r.imag = imag;
        return r;
    }
    friend const Complex operator+(float x, const Complex &c)
    {
        Complex r;
        r.real = x+c.real;
        r.imag = c.imag;
        return r;
    }
    friend const Complex operator*(const Complex &c1, const Complex &c2)
    {
        Complex r;
        r.real = c1.real*c2.real-c1.imag*c2.imag;
        r.imag = c1.real*c2.imag+c1.imag*c2.real;
        return r;
    }
    const Complex operator=(const Complex &c2)
    {
        real = c2.real;
        imag = c2.imag;
        return *this;
    }
    const Complex &operator++()//前缀++ 
    {
        ++real;
        ++imag;
        return *this;
    }
    const Complex operator++(int x)//后缀++ 
    {
        Complex r = *this;
        real++;
        imag++;
        return r;
    }
    float &operator[](int i)//重要 
    {
        if (i==0) return real;
        else if(i==1) return imag;
        else
        {
            cout << "Out of boundary" << endl;
            exit(1);
        }
    }
    Complex &operator()(float r, float i)
    {
        real = r;
        imag = i;
        return *this;
    }
    friend istream &operator>>(istream &in, Complex &c)
    {
        in >> c.real >> c.imag;
        return in;
    }
    friend ostream &operator<<(ostream &out, const Complex &c)
    {
        if(c.imag>0)
            out << c.real << "+" << c.imag << "i" << endl;
        else
            out << c.real << c.imag << "i" << endl;
        return out;
    }
};

int main()
{
    Complex c;

    cin >> c;

    Complex d = c;

    d(7, 8);

    d = c+d;

    c++;
    ++d;

    cout << c ;
    cout << d ;


    return 0;
}
