#include <iostream>

using namespace std;

class A
{
    int x;
public:
    A(int _x=0)
    {
        x = _x;
        cout << "Cons " << x << endl;
    }
    A(const A &aCopy)
    {
        x = aCopy.x;
        x++;
        cout << "Copy "<< x << endl;
    }
    ~A()
    {
        cout << "De " << x << endl;
    }
};

A fun(A a)
{
    A objA3(a);
    return objA3;
}

int main()
{
    A objA0(1);
    A objA1(objA0);
    A objA2 = fun(objA1);

    return 0;
}
