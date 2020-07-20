//答疑，下列代码中的for (auto &e: v)是什么意思:
 
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

/*for (auto &e: v) 是C++11后增加的新语法“基于范围的循环“，

for (const auto &e: arr) cout << e << " ";
等价于
for (auto __begin=arr.begin(), __end=arr.end(); __begin!=__end; ++__begin) 
{ 
     const auto &e=*__begin; 
     cout << e << " ";
}
具体解释参考：
https://en.cppreference.com/w/cpp/language/range-for*/

