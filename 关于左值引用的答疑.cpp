关于左值引用的答疑

问：重载加减乘除运算符来对类运算时，重载运算符函数的返回类型是类的引用为什么对结果有很大影响啊？

答：返回为某数据类型的引用是C++的新特征，类似于C语言的返回指针操作。
例：
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

等价于：
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

类似于：
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
