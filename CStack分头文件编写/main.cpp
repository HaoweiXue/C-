#include <iostream>
#include "CStack.h"
using namespace std;

int main()
{
    CPPStackExt s;

    for(int i=0;i<7;i++)
        s.push('a'+i);

    CPPStackExt sCopy(s);

    while(!s.isEmpty()) s.pop();

    for(int i=0;i<7;i++)
        s.push('1'+i);

    while(!sCopy.isEmpty()){
        cout<<sCopy.pop();

    }
    cout<<endl;



    return 0;
}
