������ֵ���õĴ���

�ʣ����ؼӼ��˳����������������ʱ����������������ķ����������������Ϊʲô�Խ���кܴ�Ӱ�찡��

�𣺷���Ϊĳ�������͵�������C++����������������C���Եķ���ָ�������
����
#include <iostream>
using namespace std;

int g_a = 3;

int &func()
{
    g_a++;
    return g_a;
}

int main()
{
    func() = 10;
    cout << g_a << endl;
    return 0;
}

�ȼ��ڣ�
#include <iostream>
using namespace std;

int g_a = 3;

int &func()
{
    g_a++;
    return g_a;
}

int main()
{
    int &r = func();

    r = 10;

    cout << g_a << endl;

    return 0;
}

�����ڣ�
#include <iostream>
using namespace std;

int g_a = 3;

int *func()
{
    g_a++;
    return &g_a;
}

int main()
{
    *func() = 10;
    cout << g_a << endl;
    return 0;
}
