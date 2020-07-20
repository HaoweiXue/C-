/*1. 老师能讲解一下ostringstream类怎么使用吗?
答：ostringstream一般用来将不同类型的数据转换为字符串，比如说将浮点数3.14转换为字符串“3.14”，就可采用ostringstream。

和 ostringstream类相对的还有istringstream，主要用于从字符串中提取不同类型的数据，比如说将字符串“3.14”转换为浮点数3.14。

例：*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string convertAnytypeToString(string a, int b, double c)
{
    ostringstream oss;
    oss << a << " " << b << " " << c;
    string s = oss.str();
    return s;
}

void convertStringToSpecificTypes(string s, string &a, int &b, double &c)
{
    istringstream is(s);
    is >> a >> b >> c;
}

int main ()
{
    string a;
    int b;
    double c;
    string r;

    cin >> a >> b >> c;

    r = convertAnytypeToString(a, b, c);
    cout << r << endl;

    convertStringToSpecificTypes(r, a, b, c);
    cout << a << " " << b << " " << c << endl;
    return 0;
}

