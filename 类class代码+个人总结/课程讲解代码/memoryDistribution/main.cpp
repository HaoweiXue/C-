#include <iostream>
#include <cstdio>
using namespace std;

class CPoint2D
{
    int x, y;
    static int num;
public:
    CPoint2D()
    {
        x = y = 0;
        num++;
    }
    CPoint2D(int x, int y)
    {
        this->x = x;
        this->y = y;
        num++;
    }
    ~CPoint2D()
    {
        num--;
    }
    static int GetCounter()
    {
        return num;
    }
    float GetX()
    {
        return x;
    }
    void Output()
    {
        cout << "静态变量地址:" << &num << endl;
        cout << "静态函数地址:" << (void *)&GetCounter << endl;
    }
};

int CPoint2D::num = 0;
CPoint2D g_v(1,1);

int main()
{
    CPoint2D v;
    CPoint2D *p;

    p = new CPoint2D;
    p->GetCounter();

    cout << "全局对象地址:" << &g_v << endl;
    cout << "局部对象地址:" << &v << endl;
    cout << "动态对象地址:" << p << endl;
    p->Output();
    cout << "局部对象函数地址:" << (void *)&(v.GetX) << endl;
    cout << "全局对象函数地址:" << (void *)&(g_v.GetX) << endl;
    cout << "动态对象函数地址:" << (void *)&(p->GetX) << endl;
    cout << "main函数地址:" << (void *)&main << endl;

    delete p;
}
