#pragma once
#include<iostream>
#include<string>
#include"student.hpp"
using namespace std;
class StudentList {
public:
	//构造
	StudentList() :head(NULL),tail(NULL), size(0) {}
	//void remove(student& stu);//依据对象移除
	void remove(student* sp);//重载一个依据地址删除
	void add(student& stu);//添加信息到链表中
	bool xhfind(string xh);
	bool xmfind(string xm,int&count);
	student* xhget(string xh);//依靠学号查找，应该返回地址，而非拷贝来的
	student* xmget(string xm,int order);//依靠姓名查找
	//接口
	student* gethead();//头节点接口
	int getsize();//数据规模接口
	//排序
	void sort();
	//筛选,设计为不破坏原来的链表，不然再操作的话会刷新覆写
	StudentList filter(int totalmin, int mathmin, int flmin, int plmin, int mjmin);
	//展示
	void dataprint(string xm);//把姓名为xm都打出来
	//准考证查重
	bool chachong();
private:
	int size;
	student* head;
	student* tail;
};