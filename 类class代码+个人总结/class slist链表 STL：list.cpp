/*
 * ex9_4.cpp
 *
 * 4. 已知整型链表类的部分声明如下：
 class slist {
 public:
 slist（）;
 ~slist（）;
 void insert_front(int x); //在表头插入元素x
 void insert_back(int x); //在表尾插入元素x
 int del_front(); //删除并返回第一个元素
 int del_back(); //删除并返回最后一个元素
 int front(); //返回第一个元素
 int back(); //返回最后一个元素
 bool empty(); //判断链表是否为空
 …
 };
 在slist 类的基础上，设计并实现一个整型堆栈类intStack。
 */

#include <list>
#include <iostream>
using namespace std;

//the slist class
class slist {
public:
	slist() = default;
	~slist() = default;
	void insert_front(int x); //在表头插入元素x
	void insert_back(int x); //在表尾插入元素x
	int del_front(); //删除并返回第一个元素
	int del_back(); //删除并返回最后一个元素
	int front(); //返回第一个元素
	int back(); //返回最后一个元素
	bool empty(); //判断链表是否为空
private:
	list<int> lst;
};

void slist::insert_front(int x) {
	lst.push_front(x);
}

void slist::insert_back(int x) {
	lst.push_back(x);
}

int slist::del_front() {
	if(lst.empty())
		return 0;
	int ele = lst.front();
	lst.pop_front();
	return ele;
}

int slist::del_back() {
	if(lst.empty())
		return 0;
	int ele = lst.back();
	lst.pop_back();
	return ele;
}

int slist::front() {
	return lst.front();
}

int slist::back() {
	return lst.back();
}

bool slist::empty() {
	return lst.empty();
}

class intStack{
public:
	intStack() = default;//自动转到（默认值)
	~intStack() = default;
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
	slist stack;
};

int main(){
	intStack st;
	for(int i = 0; i < 10; ++i)
		st.push(i);

	while(!st.empty())
		cout << st.pop() << "\t";

	return 0;
}
