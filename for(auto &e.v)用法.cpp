//���ɣ����д����е�for (auto &e: v)��ʲô��˼:
 
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int main()
{
    int n = 10;
    vector <int> v(n);
    for (auto &e: v) e = rand()%100;
    for (const auto &e: v) cout << e << " ";
    cout << endl;
    return 0;
}

/*for (auto &e: v) ��C++11�����ӵ����﷨�����ڷ�Χ��ѭ������

for (const auto &e: arr) cout << e << " ";
�ȼ���
for (auto __begin=arr.begin(), __end=arr.end(); __begin!=__end; ++__begin) 
{ 
     const auto &e=*__begin; 
     cout << e << " ";
}
������Ͳο���
https://en.cppreference.com/w/cpp/language/range-for*/

