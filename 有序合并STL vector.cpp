/*
 * ex5_7.cpp
 *
 *  7. 编写函数，将两个有序vector合并成一个新的有序vector，函数原型为：
 *  vector<int> merge(vector<int> list1, vector<int> list2);
 *
 */


#include<vector>
#include<iostream>
using namespace std;

vector<int> merge(vector<int> list1, vector<int> list2){//注意返回vector<int> 
	vector<int> vm;//不说明数量默认很多个 

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
	for(auto e : v1) cout << e << " ";//遍历输出v1 

	cout << "\nv2: ";
	for(auto e : v2) cout << e << " ";

	cout << "\nmerge(v1, v2): ";
	for(auto e : v3) cout << e << " ";


	return 0;
}

