#include <iostream>

using namespace std;
class CPPStackExt
{
private:
    char*s;
    int tp;
    int size;
public:
    CPPStackExt(int initSize=5);//constructor 
    CPPStackExt(const CPPStackExt &scopy);//constructor 
    ~CPPStackExt();//destructor
    bool isEmpty();
    bool isFull();
    void push(char c);
    char pop();
    char top();

};
bool CPPStackExt::isEmpty()
{
    return (tp==-1);//判断 
}
bool CPPStackExt::isFull()
{
    return (tp==(size-1));
}
void CPPStackExt::push(char c)
{
    if(isFull())
    {
        char*p=new char[2*size];
        for(int i=0;i<size;i++)
            p[i]=s[i];
        delete []s;
        s=p;
        size=2*size;
    }
    tp++;
    s[tp]=c;
}
char CPPStackExt::pop()
{
   int oldtp=tp;
   tp--;
   return s[oldtp];
}
char CPPStackExt::top()
{
    return s[tp];
}
CPPStackExt::CPPStackExt(int initSize)
{
    tp=-1;
    size=initSize;
    s=new char [size];
}
CPPStackExt::CPPStackExt(const CPPStackExt&scopy)
{
    tp=scopy.tp;
    size=scopy.size;
    s=new char [size];
    for(int i=0;i<=tp;i++)
        s[i]=scopy.s[i];

}
CPPStackExt::~CPPStackExt()
{
    if(s!=NULL)
    {
        delete []s;
        s=NULL;
    }
}
int main()
{
    CPPStackExt s;

    for(int i=0;i<7;i++)
        s.push('a'+i);
     CPPStackExt sCopy(s);// 
    while(!s.isEmpty()) s.pop();//while循环 s.出栈 
    for(int i=0;i<7;i++)
    {
        s.push('1'+i);//s.入栈。 
    }
    while(!sCopy.isEmpty())
        cout<<sCopy.pop();//输出。 
    cout<<endl;
    while(!s.isEmpty())
        cout<<s.pop();
    cout<<endl;
    return 0;
}

