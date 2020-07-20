#include <iostream>
#include <string>
using namespace std;

class base
{
    string mark;
public:
    base()
    {
        mark = "null";
        cout << "Constructor " << mark << endl;
    }
    base(string str)
    {
        mark = str;
        cout << "Constructor " << mark << endl;
    }
    ~base()
    {
        cout << "Destructor " << mark << endl;
    }
};

base g1("g1");
base g2("g2");
int main()
{
    base l1("l1");
    base l2("l2");
    base *d1, *d2;
    d1 = new base("d1");
    d2 = new base ("d2");
    delete d1;
    delete d2;
    return 0;
}

