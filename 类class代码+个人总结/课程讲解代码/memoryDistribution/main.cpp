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
        cout << "��̬������ַ:" << &num << endl;
        cout << "��̬������ַ:" << (void *)&GetCounter << endl;
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

    cout << "ȫ�ֶ����ַ:" << &g_v << endl;
    cout << "�ֲ������ַ:" << &v << endl;
    cout << "��̬�����ַ:" << p << endl;
    p->Output();
    cout << "�ֲ���������ַ:" << (void *)&(v.GetX) << endl;
    cout << "ȫ�ֶ�������ַ:" << (void *)&(g_v.GetX) << endl;
    cout << "��̬��������ַ:" << (void *)&(p->GetX) << endl;
    cout << "main������ַ:" << (void *)&main << endl;

    delete p;
}
