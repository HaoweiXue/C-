//2. 使用迭代器编写程序，从标准输入设备读入若干string对象，并将它们存储在一个vector 容器中，然后逆序输出vector 中所有的元素。
//提示：使用逆向迭代器实现。

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

int main()
{
   string line;
   vector<string> vs;
   cout<<"Enter 10 strings: "<<endl;
   for(int i=0;i<10;i++)
   {
       getline(cin,line);//getline(cin,***)
       vs.push_back(line);//push_back(***)
   }

   auto rit=vs.rbegin();//auto  逆向迭代器
   while(rit!=vs.rend())
   {
       cout<<*rit<<endl;
       ++rit;
   }
    return 0;
}

