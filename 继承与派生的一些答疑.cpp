

1. protected��ʲô�ã���ʵ�������
��
��1�����û�м̳���������ϵ������Ϊprotected��private���ʿ���Ȩ��һ����
���磺
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

a��bһ����private����һ����protected�����Ƕ����ڳ�Ա����Output��ʹ�ã���ͨ���������x.a��x.b�������

��2��������������࣬����ͳ����ˣ�
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
��ʱ����������Ϊ���������з���CBase::a���CBase���˽�г�Ա��a����public�̳к���CDerived�����ˡ����ɷ��ʡ�����CBase::bȴ��������ʹ�ã���Ϊb��protected���ͣ�����public�̳к���CDerived����Ȼ�ǡ�protected�����͵ġ�

�޸ĺ�Ĵ���Ϊ��
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
2. ��̳е�ʱ���̳й��캯����?

����C++98�ﲻ���ԣ���C++11�������ͨ��using���ʹ�û��๹�캯�������γ̽�����ͳһ�ο�C++98��׼��̡�

���磺
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

�ο���https://stackoverflow.com/questions/347358/inheriting-constructors

