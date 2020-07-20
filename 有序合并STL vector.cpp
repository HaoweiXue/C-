/*
 * ex5_7.cpp
 *
 *  7. ��д����������������vector�ϲ���һ���µ�����vector������ԭ��Ϊ��
 *  vector<int> merge(vector<int> list1, vector<int> list2);
 *
 */


#include<vector>
#include<iostream>
using namespace std;

vector<int> merge(vector<int> list1, vector<int> list2){//ע�ⷵ��vector<int> 
	vector<int> vm;//��˵������Ĭ�Ϻܶ�� 

	auto it1 = list1.begin(), it2 = list2.begin();

	while(it1 != list1.end() && it2 != list2.end()){
		if(*it1 < *it2)
			vm.push_back(*it1++);
		else
			vm.push_back(*it2++);
	}

	while(it1 != list1.end())
		vm.push_back(*it1++);

	while(it2 != list2.end())
		vm.push_back(*it2++);

	return vm;
}

int main()
{
	vector<int> v1 = {2, 3, 4, 6};
	vector<int> v2 = {1, 3, 5, 7, 9, 13};
	vector<int> v3 = merge(v1, v2);

	cout << "\nv1: ";
	for(auto e : v1) cout << e << " ";//�������v1 

	cout << "\nv2: ";
	for(auto e : v2) cout << e << " ";

	cout << "\nmerge(v1, v2): ";
	for(auto e : v3) cout << e << " ";


	return 0;
}

