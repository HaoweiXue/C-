/*
 * ex8_1.cpp
 *
 * 1．为第6 章习题中定义的Date 类、Employee 类和Student 类提供I/O 流输出操作符。
 */

#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Date{
	int year = 1970;
	int month = 1;
	int day = 1;
public:
	//constructor
	Date(int y, int m, int d){
		if (y > 0)
			year = y;
		else
			year = 1970;

		if(m >= 1 && m <= 12)
			month = m;
		else
			month = 1;

		if(leapYear() && month == 2){
			if(d >= 1 && d <= 29)
				day = d;
			else
				day = 1;
		}
		else{
			if(d >= 1 && d <= days[month])
				day = d;
			else
				day = 1;
		}
	}
	//default constructor
	Date() : Date(1970, 1, 1){}

	friend ostream& operator<<(ostream& os, const Date& d);

private:
	int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	bool leapYear() const{
		return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
	}

};
ostream& operator<<(ostream& os, const Date& d){
	os << d.year << "/" << d.month << "/" << d.day;
	return os;
}
//----------------------------------------------------------

class Employee{
	string name;
	unsigned int id;
	string department;
	string title;
	double salary = 0;
	string address;
	vector<string> phone;
public:
	Employee(string ename, unsigned eid) : name(ename), id(eid){}
	Employee(string ename, unsigned eid, string dept, string ttl)
	: name(ename), id(eid), department(dept), title(ttl)	{}

	friend ostream& operator<<(ostream& os, const Employee& e);
};

ostream& operator<<(ostream& os, const Employee& e){
	os <<"Name: " << e.name << "\n"
		<<"ID: " << e.id << "\n"
		<<"Department: " << e.department <<"\n"
		<<"Title: "<< e.title << "\n";
	cout << "Tel: ";
	for(auto p : e.phone)
		os << p << "\t";
	return os;
}
//----------------------------------------------------------
class Student{
	string name;
	unsigned int id;
	string department;
public:
	Student(string sname, unsigned sid) : name(sname), id(sid){}
	Student(string sname, unsigned sid, string dept) : name(sname), id(sid), department(dept){}

	friend ostream& operator<<(ostream& os, const Student& s);
};

ostream& operator<<(ostream& os, const Student& s){
	os << s.id <<"\t" << s.name  <<"\t" << s.department;
	return os;
}
//----------------------------------------------------------
int main()
{

	Date d(2017, 2, 12);
	cout << "Date\n" << d << endl;
	Employee e("Lily", 123, "Sales", "Manager");
	cout << "Employee\n" << e << endl;
	Student s("LinDong", 118109, "Computer Science");
	cout << "Student\n" << s << endl;

	return 0;
}








