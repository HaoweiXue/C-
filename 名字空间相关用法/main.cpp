#include <iostream>

using namespace std;

namespace Xilin
{
    int year=2020;
    char name[]="Xilin";
    void ShowName()
    {
        cout<<name<<"\t"<<year<<endl;
    }
}
namespace Xinong
{
    int year=2020;
    char name[]="Xinong";
    void ShowName()
    {
        cout<<name<<"\t"<<year<<endl;
    }
}
using namespace Xinong;
using namespace Xilin;

int main()
{
   Xilin::ShowName();
    return 0;
}
