#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    string line,studID,studName;
    map<string,string>m;
    while(getline(cin,line))
    {
        if(line=="exit") break;
        istringstream is(line);
        is>>studID>>studName;
        m.insert({studID,studName});
    }
    string key;
    cin>>key;
    auto p=m.find(key);
    if(p!=m.end())
        cout<<p->second<<endl;
    else
        cout<<"Not in the list."<<endl;
//    string line,studID,studName;
//    vector<string>vID,vName;
//    while(getline(cin,line))
//    {
//        if(line=="exit") break;
//        istringstream is(line);
//        is>>studID>>studName;
//        vID.push_back(studID);
//        vName.push_back(studName);
//    }
//
//    string key;
//    cin>>key;
//    auto p=find(vID.begin(),vID.end(),key);
//    if(p!=vID.end())
//        cout<<vName[p-vID.begin()] <<endl;
//    else
//        cout<<"Not in the list."<<endl;
    return 0;
}
