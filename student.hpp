#pragma once
#include<iostream>
#include<string>
using namespace std;
class student {
public:
	//����
	student* next;
	//����
	student();//�޲ι���
	student(string vname,string num1, string mname,string bf, string num2, string num3, string num4, string num5);
	//��������Ӧ�ò����˰ɣ�ֱ��ȱʡ��
	//����
	void nameset(string n);
	void numberset(string num);
	void majornameset(string n);
	void boolfreshset(string n);
	void mathset(string num);
	void Foreign_languageset(string num);
	void politicsset(string num);
	void majorset(string num);
	//���ʽӿ�
	string getname();
	string getnumber();
	string getmajorname();
	string getboolfresh();
	string getmath();
	string getForeign_language();
	string getpolitics();
	string getmajor();
	//�����ӿ�
	int totalscore();//�ֽܷӿ�
	int mathscore();
	int Foreign_languagescore();
	int politicsscore();
	int majorscore();

	//operator�����,���ֿ��ܻ���ȣ���׼��֤���ǲ�����ȵ�
	bool operator==(const student& stu) { return number == stu.number; }
private://����
	string name;
	string number;
	string majorname;
	string boolfresh;
	string math;
	string Foreign_language;
	string politics;
	string major;
};