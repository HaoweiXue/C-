//2. ʹ�õ�������д���򣬴ӱ�׼�����豸��������string���󣬲������Ǵ洢��һ��vector �����У�Ȼ���������vector �����е�Ԫ�ء�
//��ʾ��ʹ�����������ʵ�֡�

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

   auto rit=vs.rbegin();//auto  ���������
   while(rit!=vs.rend())
   {
       cout<<*rit<<endl;
       ++rit;
   }
    return 0;
}

