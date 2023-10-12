#pragma once
#include<iostream>
#include<string>
#include"student.hpp"
#include"StudentList.hpp"
using namespace std;

void StudentList::add(student& stu) {//�����Ϣ��������,β�����
	if (head == NULL) {//�ձ�head=NULL��tail=NULLӦ����һ����
		student* ptr = new student(stu);//��student�����½��ڵ�
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
//void StudentList::remove(student& stu) {//ɾ��ָ������
//	if (head->getnumber() == stu.getnumber()) {//ɾ��ͷ�ڵ�
//		student* p = head;
//		head = head->next;
//		delete p;
//		size -= 1;
//	}
//	else if (tail->getnumber() == stu.getnumber()) {//ɾ��β�ڵ㣬��tail
//		student* pre = head;
//		while (pre->next != tail) pre = pre->next;//�����ҵ�pre
//		delete tail;
//		tail = pre;
//		tail->next = NULL;
//	}
//	else {
//		student* p = head;//p����stu��λ��
//		while (p && p->getnumber() != stu.getnumber()) p = p->next;
//		if (p == NULL) cout << "no information could be deleted" << endl;//���о�û��Ҫ
//		else {
//			student* pre = head;
//			while (pre->next != p) pre = pre->next;//�ҵ�p��ǰλpre
//			pre->next = p->next;
//			delete p;
//			size -= 1;
//		}
//	}
//}
void StudentList::remove(student* sp) {
	if (head->getnumber() == (*sp).getnumber()) {//ɾ��ͷ�ڵ�
		student* p = head;
		head = head->next;
		delete p;
		size -= 1;
	}
	else if (tail->getnumber() == (*sp).getnumber()) {//ɾ��β�ڵ㣬��tail
		student* pre = head;
		while (pre->next != tail) pre = pre->next;//�����ҵ�pre
		delete tail;
		tail = pre;
		tail->next = NULL;
	}
	else {
		student* p = head;//p����stu��λ��
		while (p && p->getnumber() != (*sp).getnumber()) p = p->next;
		if (p == NULL) cout << "no information could be deleted" << endl;//���о�û��Ҫ���Ͼ�ǰ�����в���ɾ
		else {
			student* pre = head;
			while (pre->next != p) pre = pre->next;//�ҵ�p��ǰλpre
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
	while (p) {//�����Ƿ����
		if (p->getname() == xm) {
			flag = true;
			break;
		}
		p = p->next;
	}
	//�ٱ���һ��ȡ�ظ�����
	p = head;
	while (p) {
		if (p->getname() == xm) {
			count += 1;
		}
		p = p->next;
	}
	return flag;
}
student* StudentList::xhget(string xh) {//����ѧ�Ų���
	student* p = head;
	while (p && p->getnumber() != xh) {
		p = p->next;
	}
	//ֱ���ҵ�p
	return p;
}
student* StudentList::xmget(string xm,int order) {//������������
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
	//����Ҫ���ѧ������������
	StudentList rList;
	//int count = 0;//add���Ѿ���size�Ĳ�����
	student* p = head;
	while (p) {//����ԭ�����ҳ�����Ҫ���
		if ((*p).totalscore() >= totalmin && (*p).mathscore() >= mathmin && (*p).Foreign_languagescore() >= flmin && (*p).politicsscore() >= plmin && (*p).majorscore() >= mjmin) {
			rList.add((*p));//����Ҫ�����ӽ�ȥ
		}
		p = p->next;
	}
	return rList;
}

void StudentList::sort() {//����
	//Ѱ�ҽϴ�ֵ��Ȼ�󽻻�ֵ���ڵ�Ͳ�����
	//���������ֵ
	student* p = head;
	while (p) {
		student* max = p;//�����
		student* ptr = p->next;
		while (ptr) {//ptr����
			if (ptr->totalscore() > max->totalscore()) max = ptr;
			ptr = ptr->next;
		}
		if (max != p) {//��������,���������������
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
bool StudentList::chachong() {//׼��֤���أ�
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