#include <iostream>

using namespace std;

int main()
{
    int **mat;
    int m,n;
    mat=new int*[m];
    for(int i=0;i<m;i++)
    {
        mat[i]=new int[n];
    }
    for(int i=0;i<m;i++)
    {
        delete []mat[i];
    }
    delete[]mat;
    return 0;
}
