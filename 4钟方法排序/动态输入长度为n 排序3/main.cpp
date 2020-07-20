#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>//sort(数组首地址，数组末地址):将数组元素从小到大排序;
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        a.push_back(rand()%100);
    }
    for(size_t i=0;i<a.size();i++)//a.size()-->size_t 
    {
        cout<<a[i]<<"\t";
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
