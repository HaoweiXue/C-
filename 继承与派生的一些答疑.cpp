

1. protected有什么用，我实在理不清楚
答：
（1）如果没有继承与派生关系，可认为protected和private访问控制权限一样：
例如：
#include <iostream>

using namespace std;

class CBase
{
private:
    int a;
protected:
    int b;
public:
    CBase(int _a=0, int _b=0):a(_a), b(_b){}
    void Output()
    {
        cout << "Base:" << a << "," << b << endl;
    }
};

int main()
{
    CBase x(3, 4);
    
    x.Output();

    return 0;
}

a和b一个是private，另一个是protected，它们都能在成员函数Output中使用，但通过对象调用x.a或x.b都会出错。

（2）如果存在派生类，区别就出来了：
#include <iostream>

using namespace std;

class CBase
{
private:
    int a;
protected:
    int b;
public:
    CBase(int _a=0, int _b=0):a(_a), b(_b){}
    void Output()
    {
        cout << "Base:" << a << "," << b << endl;
    }
};

class CDerived: public CBase
{
    int c;
public:
    CDerived(int _a=0, int _b=0, int _c=0): CBase(_a, _b), c(_c) {}
    void Output()
    {
        cout << "Derived:" << a << "," << b << "," << c << endl;
    }
};

int main()
{
    CDerived x(3, 4, 5);

    x.Output();

    return 0;
}
这时会编译出错，因为在派生类中访问CBase::a这个CBase类的私有成员，a经过public继承后到了CDerived类变成了“不可访问”，但CBase::b却可以正常使用，因为b是protected类型，经过public继承后到了CDerived类依然是“protected”类型的。

修改后的代码为：
#include <iostream>

using namespace std;

class CBase
{
protected:
    int a;
    int b;
public:
    CBase(int _a=0, int _b=0):a(_a), b(_b){}
    void Output()
    {
        cout << "Base:" << a << "," << b << endl;
    }
};

class CDerived: public CBase
{
    int c;
public:
    CDerived(int _a=0, int _b=0, int _c=0): CBase(_a, _b), c(_c) {}
    void Output()
    {
        cout << "Derived:" << a << "," << b << "," << c << endl;
    }
};

int main()
{
    CDerived x(3, 4, 5);

    x.Output();

    return 0;
}
2. 类继承的时候会继承构造函数吗?

答：在C++98里不可以，但C++11里面可以通过using语句使用基类构造函数；本课程建议大家统一参考C++98标准编程。

例如：
#include <iostream>

using namespace std;

class Base
{
    int a;
public:
    Base(int _a)
    {
        a = _a;
        cout << a << endl;
    }
};

class Derived : public Base
{
    int x;
public:
    using Base::Base;
};

int main()
{
    Derived d(6);
    return 0;
}

参考：https://stackoverflow.com/questions/347358/inheriting-constructors

