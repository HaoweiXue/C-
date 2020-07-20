#include <iostream>
#include <cstdlib>
using namespace std;

int compare(const void*a,const void*b)
{
    return (*(int*)a-*(int*)b);
}
int main()
{
  int n;
  int *a=NULL;
  cin>>n;
  a=(int*)malloc(sizeof(int)*n);//malloc-->free 
  for(int i=0;i<n;i++) a[i]=rand()%100;
  for(int i=0;i<n;i++)
  {
    cout<<a[i]<<"\t";
    cout<<endl;
  }
  qsort(a,n,sizeof(int),compare);

  for(int i=0;i<n;i++)
  {
      cout<<a[i]<<"\t";
      cout<<endl;
  }
  free(a);
    return 0;
}
