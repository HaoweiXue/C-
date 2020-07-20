/*1. ��ʦ�ܽ���һ��ostringstream����ôʹ����?
��ostringstreamһ����������ͬ���͵�����ת��Ϊ�ַ���������˵��������3.14ת��Ϊ�ַ�����3.14�����Ϳɲ���ostringstream��

�� ostringstream����ԵĻ���istringstream����Ҫ���ڴ��ַ�������ȡ��ͬ���͵����ݣ�����˵���ַ�����3.14��ת��Ϊ������3.14��

����*/
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

