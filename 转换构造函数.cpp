//2. 老师，有一个关于类的类型转换的问题？
class A {
private:
	int a;
public:
	A(int g) {
		a = g;
	}
};

int main() {
	A t = 1;
        t = 3;
}

////t是一个对象，1、3是一个基本数据类型的数怎么可以赋值操作？

//答：这里涉及到一个新的知识点：“转换构造函数”，转换构造函数可将基本数据类型的数赋给对象，例如：

#include <iostream>
using namespace std;

class A {
private:
	int a;
	int b;
public:
	A(int a1) //类型转换构造函数
	{
		a = a1;
		b = 0;
        cout << "cons 1: " <<  a << "," << b << endl;
	}
	A(int a1, int b1) //一般构造函数
	{
		a = a1;
		b = b1;
        cout << "cons 2: " <<  a << "," << b << endl;
	}
};

int main()
{
	A t = 1;
        t = 2;
	return 0;
}


/*会发现类型转换构造函数被调用了两次，第一次是 A t=1调用了，第二次是将2转换为一个临时对象A tmp = 2调用了，最后执行了t = tmp。

既然整数可以赋给类类型对象（如：A t = 1），字符串可不可以？
如： A t = "abc"。
答：不建议这样操作，如果非要这样做，再写一个构造函数：
	A(const char str[]) //类型转换构造函数
	{
	    if (str[0]!='\0')
            a = str[0] - 'a';
        else
            a = 0;
		b = 0;
        cout << "cons 2: " <<  a << "," << b << endl;
	}*/


//最后，类型转换要避免使用，会影响代码安全性和可读性。

