#include <iostream>

using namespace std;

class Complex
{
    float real,imag;
public:
    Complex(float r=0,float i=0):real(r),imag(i){};
    Complex operator+(Complex other)
    {
        Complex r;
        r.real=real+other.real;
        r.imag=imag+other.imag;
        return r;
    }
    void Output()
    {
        if(imag>0)
            cout<<real<<"+"<<imag<<"i"<<endl;
        else
            cout<<real<<imag<<"i"<<endl;
    }
};
int main()
{
   Complex a(2,3),b(3,4),c;
   c=a+b;
   c.Output();
    return 0;
}

