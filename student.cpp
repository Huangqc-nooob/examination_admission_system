#pragma once
#include "student.hpp"
using namespace std;
student::student() {//�޲ι���
	name = "NULL";
	number = "NULL";
	majorname = "NULL";
	boolfresh = "NULL";
	math = "NULL";
	Foreign_language = "NULL";
	politics = "NULL";
	major = "NULL";
}

student::student(string vname, string num1, string mname, string bf, string num2, string num3, string num4, string num5) {
	//������׼��֤�ţ�רҵ�����Ƿ�Ӧ��������ѧ�ɼ�������ɼ������γɼ���רҵ�ɼ�
	//name
	name = vname;
	majorname = mname;
	//other
	boolfresh = bf;
	number = num1;
	math = num2;
	Foreign_language = num3;
	politics = num4;
	major = num5;
}
void student::nameset(string n) {
	name = n;
}
void student::numberset(string num) {
	number = num;
}
void student::majornameset(string n)
{
	majorname = n;
}
void student::boolfreshset(string n)
{
	boolfresh = n;
}
void student::mathset(string num) {
	math = num;
}
void student::Foreign_languageset(string num) {
	Foreign_language = num;
}
void student::politicsset(string num) {
	politics = num;
}
void student::majorset(string num) {
	major = num;
}
//�ӿ�
string student::getname() {
	return name;
}
string student::getnumber() {
	return number;
}
string student::getmajorname() {
	return majorname;
}
string student::getboolfresh() {
	return boolfresh;
}
string student::getmath() {
	return math;
}
string student::getForeign_language() {
	return Foreign_language;
}
string student::getpolitics() {
	return politics;
}
string student::getmajor() {
	return major;
}
int student::totalscore() {
	int sum = 0;
	sum += atoi(math.c_str());
	sum += atoi(Foreign_language.c_str());
	sum += atoi(politics.c_str());
	sum += atoi(major.c_str());
	return sum;
}
int student::mathscore() {
	return atoi(math.c_str());
}
int student::Foreign_languagescore() {
	return atoi(Foreign_language.c_str());
}
int student::politicsscore() {
	return atoi(politics.c_str());
}
int student::majorscore() {
	return atoi(major.c_str());
}