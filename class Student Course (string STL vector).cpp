/*
 * ex9_7.cpp
 *
 *  7. 学生选修课程这一事实可以用学生类和课程类之间的关联关系来建模。设计并实现
这两个类以及它们的关联关系。要求如下。
（1）学生的属性有姓名和学号。
（2）课程的属性有课程名、编号和学分。
（3）课程能知道选修了该课程的所有学生。
（4）学生知道自己选修了哪些课程。
编写测试程序，模拟学生选课的操作，选课完成后，打印某门课程的学生名单，对某位学生，统计选修课程的总学分数。
*
 */

#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
//-------------------------------------------------
class Course;//提前申明 
//Student class declaration
class Student{
	string name;
	unsigned id;
	vector<Course*> cs;//对象指针 
public:
	Student(string nm, unsigned sid): name(nm), id(sid){}
	Student(const Student& s) = delete;//delete 
	Student& operator=(const Student& s) = delete;
	~Student() = default;
	unsigned getId() const {return id;}
	const string& getName() const {return name;}

	void takeCourse(Course* c);
	void quitCourse(Course* c);
	string getCourses()const;
	int getTotalCredits()const;


};
//-------------------------------------------------
//Course class declaration
class Course{
	string name;
	unsigned id;
	int credit;
	vector<Student*> stu;
public:
	Course(string nm, unsigned cid, int crdt) : name(nm), id(cid), credit(crdt){}
	Course(const Course& s) = delete;
	Course& operator=(const Course& s) = delete;
	~Course() = default;

	int getCredit() const {	return credit;	}
	unsigned getId() const {return id;	}
	const string& getName() const {	return name;}

	string getStudents()const;
	void take(Student* s);
	void quit(Student* s);
};

//-------------------------------------------------
//Course class implementation
string Course::getStudents() const {
	string stuList = "";
	for(auto it = stu.begin(); it != stu.end(); ++it){//it为指针 
		stuList += (*it) -> getName();//注意用法  string+= 
		stuList += " ";
	}
	return stuList;
}
void Course::take(Student* s){
	auto it = find(stu.begin(), stu.end(), s);//注意用法 find（）在一个范围内找对象。 
	if(it != stu.end())
		return;
	stu.push_back(s);
}
void Course::quit(Student* s){
	auto it = find(stu.begin(),stu.end(), s);
	if(it != stu.end())
		stu.erase(it);

}
//-------------------------------------------------
//Student class implementation
void Student::takeCourse(Course* c){
	auto it = find(cs.begin(), cs.end(), c);

	if(it != cs.end())
		return;

	cs.push_back(c);
	c->take(this);//明白每个类的成员函数的作用就行，高内聚，低耦合。 
}

void Student::quitCourse(Course* c){
	auto it = find(cs.begin(), cs.end(), c);

	if(it != cs.end()){
		cs.erase(it);
		c->quit(this);
	}
}

int Student::getTotalCredits()const{
	int credits = 0;
	for(auto it = cs.begin(); it != cs.end(); ++it)
		credits += (*it) -> getCredit();

	return credits;
}
string Student::getCourses() const {
	string courseList = "";
	for(auto it = cs.begin(); it != cs.end(); ++it){
		courseList += (*it) -> getName();
				courseList += " ";
	}
	return courseList;
}
//-------------------------------------------------

//-------------------------------------------------
int main(){
	Course c1("Java", 101, 3);
	Course c2("C++", 201, 3);
	Course c3("Data Structure", 102, 4);
	Course c4("OS", 302, 3);
	Course c5("Software Engineering", 301, 4);

	Student s1("Lilin", 118001);
	Student s2("LiuNa", 119003);
	Student s3("ZhaoMei", 118011);
	Student s4("ZhangWei", 119006);
	Student s5("SunYang", 118015);
	Student s6("MengHui", 118023);

	s1.takeCourse(&c1);
	s1.takeCourse(&c3);
	s2.takeCourse(&c4);
	s2.takeCourse(&c5);

	s3.takeCourse(&c1);
	s3.takeCourse(&c2);
	s3.takeCourse(&c3);
	s3.takeCourse(&c4);
	s3.takeCourse(&c5);

cout<<"S1:";
cout << s1.getName() << "\t" << s1.getCourses() << endl;
cout << s1.getTotalCredits()<<endl;

cout<<"S3:";
cout << s3.getName() << "\t" << s3.getCourses() << endl;
cout << s3.getTotalCredits()<<endl;

cout<<"Course 1: ";
cout << c1.getName() << endl;
cout<<c1.getStudents()<<endl;

cout<<"Course 2: ";
cout << c2.getName() << endl;
cout<<c2.getStudents()<<endl;

cout<<"Course 3: ";
cout << c3.getName() << endl;
cout<<c3.getStudents()<<endl;

cout<<"Course 4: ";
cout << c4.getName() << endl;
cout<<c4.getStudents()<<endl;

cout<<"Course 5: ";
cout << c5.getName() << endl;
cout<<c5.getStudents()<<endl;

s3.quitCourse(&c1);
cout<<"S3:";
cout << s3.getCourses() << endl;
cout << s3.getTotalCredits()<<endl;
cout<<"Course 101: ";
cout<<c1.getStudents()<<endl;

	return 0;
}

