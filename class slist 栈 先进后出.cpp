#include <iostream>
#include <list>
using namespace std;
class slist{
public:
    slist()=default;
    ~slist()=default;
    void insert_front(int x);
    void insert_back(int x);
    int del_front();
    int del_back();
    int front();
    int back();
    bool empty();
private:
    list<int>lst;

};

void slist::insert_front(int x){
    lst.push_front(x);
}
void slist::insert_back(int x){
    lst.push_back(x);
}
int slist::del_front(){
    if(lst.empty())
        return 0;
    int ele=lst.front();
    lst.pop_front();
    return ele;
}
int slist::del_back(){
    if(lst.empty())
        return 0;
    int ele=lst.back();
    lst.pop_back();
    return ele;
}
int slist::front(){
return lst.front();
}
int slist::back(){
    return lst.back();
}
bool slist::empty(){
    return lst.empty();
}
class intStack{//前面定义了slist类，这就可以用slist类定义对象。 
public:
    intStack()=default;
    ~intStack()=default;
    void push(int x){
    	stack.insert_front(x);
    }
    int pop(){
        return stack.del_front();
    }
    int top(){
    return stack.front();
    }
    int empty(){
        return stack.empty();
    }
private:
    slist stack;//class slist定义的对象 注意用法 
};
int main()
{
    intStack st;
    for(int i=0;i<10;i++)
        st.push(i);
    while(!st.empty())
        cout<<st.pop()<<"\t";

    return 0;
}
