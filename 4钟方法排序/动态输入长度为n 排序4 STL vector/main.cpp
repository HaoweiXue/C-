#include <iostream>
#include <cstdlib>//rand()º¯Êý
#include <vector>//vector
#include <algorithm>//sort()
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector <int>a(n);
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%100;
    }
    cout<<endl;
    sort(a.begin(),a.end());
    for(size_t i=0;i<a.size();i++)
    {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
    return 0;
}
