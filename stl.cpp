/*************************************************************************
	> File Name: stl.cpp
	> Author: LoveZJT
	> Mail: 151220055@smail.nju.edu.cn
	> Created Time: 2017年05月19日 星期五 21时11分52秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>
#include<numeric>
#include<locale>
using namespace std;

static const char *ZH_CN_LOCALE_STRING="zh_CN.utf8";
static const locale zh_CN_locale = locale(ZH_CN_LOCALE_STRING);
static const collate<char>& zh_CN_collate = use_facet<collate<char> >(zh_CN_locale);

enum Sex{M,F};

class Student
{
public:
	int stuid;
	string stuname;
	Sex stusex;
	string stumajor;
	int stuage;
	void display()
	{
		cout<<stuid<<" "<<stuname<<" ";
		if(stusex==F)
			cout<<"female ";
		else if(stusex==M)
			cout<<"male ";
		cout<<stumajor<<" "<<stuage<<endl;
	}
};

class MatchMajor
{
public:
	string stumajor;
	MatchMajor(string major)
	{
		stumajor=major;
	}
	bool operator ()(Student &stu)
	{
		return stumajor==stu.stumajor;
	}
};

void display(Student &stu);
double compute_age(vector<Student> v);
int add_age(int sum,Student stu);
int countmajor(vector<Student> v,string major);
void save(vector<Student> v);
void save_computer(Student &stu);
void sort_by_id(vector<Student> v);
bool compare_id(Student &stu1,Student &stu2);
void sort_by_name(vector<Student> v);
bool compare_name(Student &stu1,Student &stu2);
bool zh_CN_less_than(const string &s1, const string &s2);
bool compare_major(Student &stu1,Student &stu2);
void sort_by_major(vector<Student> v);

int main()
{
	vector<Student> v;
	ifstream fin("student.txt");
	if(!fin)
	{
		cout<<"can't open the student.txt"<<endl;
		return -1;
	}
	Student stu;
	char ch;
	fin>>stu.stuid>>stu.stuname;
	fin>>ch;
	if(ch=='F')
		stu.stusex=F;
	else
		stu.stusex=M;
	fin>>stu.stumajor>>stu.stuage;
	while(fin)
	{
		v.push_back(stu);
		fin>>stu.stuid>>stu.stuname;
		fin>>ch;
		if(ch=='F')
			stu.stusex=F;
		else
			stu.stusex=M;
		fin>>stu.stumajor>>stu.stuage;
		//fin>>stu.stuid>>stu.stuname>>stu.stusex>>stu.stumajor>>stu.stuage;
	}
	fin.close();
	for_each(v.begin(),v.end(),display);
	//cout<<v.size();
	cout<<compute_age(v)<<endl;
	cout<<countmajor(v,"计算机")<<endl;
	save(v);
	sort_by_id(v);
	sort_by_name(v);
	sort_by_major(v);
	return 0;
}

void display(Student &stu)
{
	stu.display();
}

double compute_age(vector<Student> v)
{
	int sum=accumulate(v.begin(),v.end(),0,add_age);
	//cout<<sum/v.size()<<endl;
	return sum/v.size();
}

int add_age(int sum,Student stu)
{
	return sum+stu.stuage;
}

int countmajor(vector<Student> v,string major)
{
	return count_if(v.begin(),v.end(),MatchMajor(major));
}

void save(vector<Student> v)
{
	ofstream fout("students_computer.txt");
	if(!fout)
		fout.close();
	for_each(v.begin(),v.end(),save_computer);
}

void save_computer(Student &stu)
{
	ofstream fout("students_computer.txt",ios::app);
	if(!fout)
	{
		cout<<"can't open the students_computer.txt"<<endl;
	}
	if(stu.stumajor=="计算机")
	{
		fout<<stu.stuid<<" "<<stu.stuname;
		if(stu.stusex=='F')
			fout<<" F ";
		else
			fout<<" M ";
		fout<<stu.stumajor<<" "<<stu.stuage<<endl;
	}
	fout.close();
}

void sort_by_id(vector<Student> v)
{
	sort(v.begin(),v.end(),compare_id);
	for_each(v.begin(),v.end(),display);
}

bool compare_id(Student &stu1,Student &stu2)
{
	return stu1.stuid<stu2.stuid;
}

void sort_by_name(vector<Student> v)
{
	sort(v.begin(),v.end(),compare_name);
	for_each(v.begin(),v.end(),display);
}

bool compare_name(Student &stu1,Student &stu2)
{
	//return stu1.stuname<stu2.stuname;
	return zh_CN_less_than(stu1.stuname,stu2.stuname);
}

bool zh_CN_less_than(const string &s1, const string &s2)
{
	 const char *pb1 = s1.data();
	 const char *pb2 = s2.data();
	 return (zh_CN_collate.compare(pb1, pb1+s1.size(), pb2, pb2+s2.size()) < 0);
}

void sort_by_major(vector<Student> v)
{
	sort(v.begin(),v.end(),compare_major);
	for_each(v.begin(),v.end(),display);
}

bool compare_major(Student &stu1,Student &stu2)
{
	return zh_CN_less_than(stu1.stumajor,stu2.stumajor);
}
