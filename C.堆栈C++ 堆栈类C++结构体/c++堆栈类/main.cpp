#include <iostream>

using namespace std;
const int N=100;

class CPPStack
{
private:
    char s[N];
    int tp;
public:
    void init();
    bool isEmpty();
    bool isFull();
    void push(char c);
    char pop();
    char top();
};
void CPPStack::init()
{
    tp=-1;
}
bool CPPStack::isEmpty()
{
    return (tp==-1);
}
bool CPPStack::isFull()
{
    return (tp==(N-1));
}
void CPPStack::push(char c)
{
    tp++;
    s[tp]=c;
}
char CPPStack::pop()
{
    int oldtp=tp;
    tp--;
    return s[oldtp];
}
char CPPStack::top()
{
    return s[tp];
}
int main()
{
   char str[]={"0123456789"};
   CPPStack s;
   cout<<str<<endl;
   s.init();
   int i=0;
   while(str[i]&&!s.isFull())
        s.push(str[i++]);
    while(!s.isEmpty())
        cout<<s.pop();
    cout<<endl;

    return 0;
}
