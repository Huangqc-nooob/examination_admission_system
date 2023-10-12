#pragma once
#include<iostream>
#include<string>
#include"student.hpp"
using namespace std;
class StudentList {
public:
	//����
	StudentList() :head(NULL),tail(NULL), size(0) {}
	//void remove(student& stu);//���ݶ����Ƴ�
	void remove(student* sp);//����һ�����ݵ�ַɾ��
	void add(student& stu);//�����Ϣ��������
	bool xhfind(string xh);
	bool xmfind(string xm,int&count);
	student* xhget(string xh);//����ѧ�Ų��ң�Ӧ�÷��ص�ַ�����ǿ�������
	student* xmget(string xm,int order);//������������
	//�ӿ�
	student* gethead();//ͷ�ڵ�ӿ�
	int getsize();//���ݹ�ģ�ӿ�
	//����
	void sort();
	//ɸѡ,���Ϊ���ƻ�ԭ����������Ȼ�ٲ����Ļ���ˢ�¸�д
	StudentList filter(int totalmin, int mathmin, int flmin, int plmin, int mjmin);
	//չʾ
	void dataprint(string xm);//������Ϊxm�������
	//׼��֤����
	bool chachong();
private:
	int size;
	student* head;
	student* tail;
};