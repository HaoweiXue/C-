#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int*a=NULL;
    cin>>n;
    a=new int[n];//new -->delete 
    for(int i=0;i<n;i++) a[i]=rand()%100;
    for(int i=0;i<n;i++) cout<<a[i]<<"\t";
    cout<<endl;

    sort(a,a+n);

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";

    }
    cout<<endl;
    delete []a;
    return 0;
}
