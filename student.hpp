#pragma once
#include<iostream>
#include<string>
using namespace std;
class student {
public:
	//链表
	student* next;
	//构造
	student();//无参构造
	student(string vname,string num1, string mname,string bf, string num2, string num3, string num4, string num5);
	//拷贝构造应该不用了吧，直接缺省了
	//设置
	void nameset(string n);
	void numberset(string num);
	void majornameset(string n);
	void boolfreshset(string n);
	void mathset(string num);
	void Foreign_languageset(string num);
	void politicsset(string num);
	void majorset(string num);
	//访问接口
	string getname();
	string getnumber();
	string getmajorname();
	string getboolfresh();
	string getmath();
	string getForeign_language();
	string getpolitics();
	string getmajor();
	//分数接口
	int totalscore();//总分接口
	int mathscore();
	int Foreign_languagescore();
	int politicsscore();
	int majorscore();

	//operator运算符,名字可能会相等，但准考证号是不会相等的
	bool operator==(const student& stu) { return number == stu.number; }
private://数据
	string name;
	string number;
	string majorname;
	string boolfresh;
	string math;
	string Foreign_language;
	string politics;
	string major;
};