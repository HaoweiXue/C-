/*
 * ex9_4.cpp
 *
 * 4. ��֪����������Ĳ����������£�
 class slist {
 public:
 slist����;
 ~slist����;
 void insert_front(int x); //�ڱ�ͷ����Ԫ��x
 void insert_back(int x); //�ڱ�β����Ԫ��x
 int del_front(); //ɾ�������ص�һ��Ԫ��
 int del_back(); //ɾ�����������һ��Ԫ��
 int front(); //���ص�һ��Ԫ��
 int back(); //�������һ��Ԫ��
 bool empty(); //�ж������Ƿ�Ϊ��
 ��
 };
 ��slist ��Ļ����ϣ���Ʋ�ʵ��һ�����Ͷ�ջ��intStack��
 */

#include <list>
#include <iostream>
using namespace std;

//the slist class
class slist {
public:
	slist() = default;
	~slist() = default;
	void insert_front(int x); //�ڱ�ͷ����Ԫ��x
	void insert_back(int x); //�ڱ�β����Ԫ��x
	int del_front(); //ɾ�������ص�һ��Ԫ��
	int del_back(); //ɾ�����������һ��Ԫ��
	int front(); //���ص�һ��Ԫ��
	int back(); //�������һ��Ԫ��
	bool empty(); //�ж������Ƿ�Ϊ��
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
	intStack() = default;//�Զ�ת����Ĭ��ֵ)
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
