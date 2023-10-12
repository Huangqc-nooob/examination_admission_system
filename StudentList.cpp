#pragma once
#include<iostream>
#include<string>
#include"student.hpp"
#include"StudentList.hpp"
using namespace std;

void StudentList::add(student& stu) {//添加信息到链表中,尾部添加
	if (head == NULL) {//空表，head=NULL跟tail=NULL应该是一样的
		student* ptr = new student(stu);//用student类来新建节点
		ptr->next = head;
		head = ptr;
		tail = ptr;
	}
	else {
		student* ptr = new student(stu);
		tail->next = ptr;
		tail = ptr;
	}
	size += 1;
}
//void StudentList::remove(student& stu) {//删除指定对象
//	if (head->getnumber() == stu.getnumber()) {//删除头节点
//		student* p = head;
//		head = head->next;
//		delete p;
//		size -= 1;
//	}
//	else if (tail->getnumber() == stu.getnumber()) {//删除尾节点，动tail
//		student* pre = head;
//		while (pre->next != tail) pre = pre->next;//遍历找到pre
//		delete tail;
//		tail = pre;
//		tail->next = NULL;
//	}
//	else {
//		student* p = head;//p查找stu的位置
//		while (p && p->getnumber() != stu.getnumber()) p = p->next;
//		if (p == NULL) cout << "no information could be deleted" << endl;//这句感觉没必要
//		else {
//			student* pre = head;
//			while (pre->next != p) pre = pre->next;//找到p的前位pre
//			pre->next = p->next;
//			delete p;
//			size -= 1;
//		}
//	}
//}
void StudentList::remove(student* sp) {
	if (head->getnumber() == (*sp).getnumber()) {//删除头节点
		student* p = head;
		head = head->next;
		delete p;
		size -= 1;
	}
	else if (tail->getnumber() == (*sp).getnumber()) {//删除尾节点，动tail
		student* pre = head;
		while (pre->next != tail) pre = pre->next;//遍历找到pre
		delete tail;
		tail = pre;
		tail->next = NULL;
	}
	else {
		student* p = head;//p查找stu的位置
		while (p && p->getnumber() != (*sp).getnumber()) p = p->next;
		if (p == NULL) cout << "no information could be deleted" << endl;//这句感觉没必要，毕竟前提是有才来删
		else {
			student* pre = head;
			while (pre->next != p) pre = pre->next;//找到p的前位pre
			pre->next = p->next;
			delete p;
			size -= 1;
		}
	}
}
bool StudentList::xhfind(string xh) {
	student* p = head;
	while (p&&p->getnumber()!=xh) {
		p = p->next;
	}
	if (p == NULL) return false;
	else return true;
}
bool StudentList::xmfind(string xm,int&count) {
	student* p = head;
	count = 0;
	bool flag = false;
	while (p) {//检验是否存在
		if (p->getname() == xm) {
			flag = true;
			break;
		}
		p = p->next;
	}
	//再遍历一次取重复次数
	p = head;
	while (p) {
		if (p->getname() == xm) {
			count += 1;
		}
		p = p->next;
	}
	return flag;
}
student* StudentList::xhget(string xh) {//依靠学号查找
	student* p = head;
	while (p && p->getnumber() != xh) {
		p = p->next;
	}
	//直接找到p
	return p;
}
student* StudentList::xmget(string xm,int order) {//依靠姓名查找
	int order0 = 1;
	student* p = head;
	while (p && (p->getname() != xm || order0!=order)) {
		if (p->getname() == xm) order0 += 1;
		p = p->next;

	}
	return p;
}
student* StudentList::gethead() {
	return head;
}
int StudentList::getsize() {
	return size;
}
StudentList StudentList::filter(int totalmin, int mathmin, int flmin, int plmin, int mjmin) {
	//符合要求的学生加入新链表
	StudentList rList;
	//int count = 0;//add中已经有size的操作了
	student* p = head;
	while (p) {//遍历原链表，找出复合要求的
		if ((*p).totalscore() >= totalmin && (*p).mathscore() >= mathmin && (*p).Foreign_languagescore() >= flmin && (*p).politicsscore() >= plmin && (*p).majorscore() >= mjmin) {
			rList.add((*p));//符合要求就添加进去
		}
		p = p->next;
	}
	return rList;
}

void StudentList::sort() {//降序
	//寻找较大值，然后交换值，节点就不换了
	//遍历找最大值
	student* p = head;
	while (p) {
		student* max = p;//找最大
		student* ptr = p->next;
		while (ptr) {//ptr遍历
			if (ptr->totalscore() > max->totalscore()) max = ptr;
			ptr = ptr->next;
		}
		if (max != p) {//整个交换,这个交换够暴力的
			//name
			string tmp = p->getname();
			(*p).nameset(max->getname());
			(*max).nameset(tmp);
			//number
			tmp = p->getnumber();
			(*p).numberset(max->getnumber());
			(*max).numberset(tmp);
			//boolfresh
			tmp = p->getboolfresh();
			(*p).boolfreshset(max->getboolfresh());
			(*max).boolfreshset(tmp);
			//majorname
			tmp = p->getmajorname();
			(*p).majornameset(max->getmajorname());
			(*max).majornameset(tmp);
			//math
			tmp = p->getmath();
			(*p).mathset(max->getmath());
			(*max).mathset(tmp);
			//Foreign language
			tmp = p->getForeign_language();
			(*p).Foreign_languageset(max->getForeign_language());
			(*max).Foreign_languageset(tmp);
			//politics
			tmp = p->getpolitics();
			(*p).politicsset(max->getpolitics());
			(*max).politicsset(tmp);
			//major
			tmp = p->getmajor();
			(*p).majorset(max->getmajor());
			(*max).majorset(tmp);
		}
		p = p->next;
	}
}

void StudentList::dataprint(string xm) {
	student* p = head;
	int count = 1;
	while (p) {
		if ((*p).getname() == xm) {
			cout << count << '.';
			cout << (*p).getname() << ' ' << (*p).getnumber() << ' ' << (*p).getmajorname() << ' ';
			cout << (*p).getboolfresh() << ' ' << (*p).getmath() << ' ' << (*p).getForeign_language() << ' ';
			cout << (*p).getpolitics() << ' ' << (*p).getmajor() << endl;
			count += 1;
		}
		
		p = p->next;
	}
}
bool StudentList::chachong() {//准考证查重！
	bool flag = false;
	student* p = head;
	while (p) {
		student* q = p->next;
		while (q) {
			if (p->getnumber() == q->getnumber()) return true;
			q = q->next;
		}
		p = p->next;
	}
}