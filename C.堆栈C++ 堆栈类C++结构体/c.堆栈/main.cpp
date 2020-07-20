#include <iostream>

using namespace std;

const int N=100;
struct CStack
{
    char s[N];
    int tp;
};
void init(CStack*stk)
{
    stk->tp=-1;
}
bool isEmpty(CStack stk)
{
    return (stk.tp==-1);
}
bool isFull(CStack stk)
{
    return (stk.tp==(N-1));
}
void push(CStack*stk,char c)
{
    stk->tp++;
    stk->s[stk->tp]=c;
}
char pop(CStack*stk)
{
    int oldtp=stk->tp;
    stk->tp--;
    return (stk->s[oldtp]);
}
char top (CStack stk)
{
    return (stk.s[stk.tp]);
}
int main()
{
    char str[]={"0123456789"};
    struct CStack s;
    cout<<str<<endl;
    init(&s);
    int i=0;
    while(str[i]&&!isFull(s))
        push(&s,str[i++]);
    while(!isEmpty(s))
        cout<<pop(&s);
    cout<<endl;
    return 0;
}
