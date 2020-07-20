#include <iostream>
#include <string>
using namespace std;
struct StuNode
{
    int ID;
    string name;
    string gender;
    int age;
    void Set(int id,const string &sn,const string &sg,int a)
    {
        ID=id;
        name=sn;
        gender=sg;
        age=a;
    }
    void Output()
    {
        cout<<ID<<","<<name<<","<<gender<<","<<age<<endl;
    }
};
int main()
{
   StuNode myNode;
   myNode.Set(101,"Tom","male",35);
   myNode.Output();
    return 0;
}
