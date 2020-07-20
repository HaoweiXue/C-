#include <iostream>
#include <cstring>
using namespace std;

struct StuNode
{
    int ID;
    char name[32];
    char gender[8];
    int age;
};
void Set(struct StuNode*s,int id,const char*sn,const char*sg,int a)
{
    s->ID=id;
    strcpy(s->name,sn);
    strcpy(s->gender,sg);
    s->age=a;
}
void Output(struct StuNode s)
{
    cout<<s.ID<<","<<s.name<<","<<s.gender<<","<<s.age<<endl;
}
int main()
{
    struct StuNode myNode;
    Set(&myNode,101,"Tom","male",35);
    Output(myNode);
    return 0;
}
