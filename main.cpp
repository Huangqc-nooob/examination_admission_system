#include<iostream>
#include<fstream>
#include<string>
#include"student.hpp"
#include"StudentList.hpp"
using namespace std;
void function_panel_display();
void select_panel_display();
void change_panel_display();
void rewrite(StudentList rList);
void resultout(StudentList rList);
int main() {
	int i11 = 0;//�����ù�����
	int i1 = 0;//һ��ѡ��
	int i2 = 0;//����ѡ��
	int i3 = 0;//����ѡ��
	int i4 = 0;//�ļ�ѡ��
	int qd = 0;//ȷ����
	string tmp;//��������ʱ�洢
	StudentList stuList;//����ѧ������
	StudentList AdmitList;//¼ȡ����
	int totalmin, mathmin,flmin, plmin, mjmin;//��¼��ͷ���
	ifstream infile("D:/stuinformation.txt", ios::in);//��ȡ��Ϣ
	if (!infile)//���ļ��ļ��
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	string vname, num1, mname, bf, num2, num3, num4, num5;
	while (infile >> vname >> num1 >> mname >> bf >> num2 >> num3 >> num4 >> num5) {
		student stu(vname, num1, mname, bf, num2, num3, num4, num5);
		//�������
		stuList.add(stu);
	}
	infile.close();//�ر�����
	if (stuList.chachong() == true) {
		cerr << "׼��֤���ظ����ļ�����" << endl;
		exit(1);
	}
	while (i1 != -1) {//������
		i2 = 0;//ˢ��һ��
		i3 = 0;
		function_panel_display();//����������ʾ
		cin >> i1;
		system("cls");
		if (i1 == 1) {//������Ϣ����������������ܵ�ʱ���ٿ��ɣ�����һ��while������
			cout << "������Ϣ" << endl;
			cout << "������������׼��֤�ţ�רҵ�����Ƿ�Ӧ��������ѧ�ɼ�������ɼ������γɼ���רҵ�ɼ�" << endl;
			cin >> vname >> num1 >> mname >> bf >> num2 >> num3 >> num4 >> num5;
			student stu(vname, num1, mname, bf, num2, num3, num4, num5);
			if (stuList.xhfind(num1) == true) {
				cout << "���������������ظ�,���ʧ�ܣ��������������ַ���" << endl;
				cin >> i11;
				system("cls");
			}
			else {
				stuList.add(stu);//�������
				rewrite(stuList);//��д
				cout << "��Ӳ���д���,�����������ַ���" << endl;
				cin >> i11;
				system("cls");
			}
		}
		else if (i1 == 2) {//�޸���Ϣ
			bool flag;
			cout << "�޸���Ϣ" << endl;
			select_panel_display();
			while (i2 != -1) {//i2������-1��һֱ���޸���Ϣ
				//cout << "����i2" << endl;
				flag = false;
				cin >> i2;
				system("cls");
				if (i2 == 1) {//������ѯ
					cout << "�������ѯ��������" << endl;
					string fname;
					cin >> fname;
					system("cls");
					int xmcount = 0;//���ݳ��ִ���
					if (stuList.xmfind(fname,xmcount) == true) {
						//���ҳɹ�
						flag = true;
						if (xmcount == 1) {
							cout << "��ѯ�ɹ���" << endl;
							i4 = 1;
						}
						else {
							//cout << xmcount << endl;//������
							stuList.dataprint(fname);//չʾ�ظ�����
							cout << "���ظ�����������������ѡ��Ҫ�޸ĵĶ���" << endl;
							cin >> i4;
							if (i4 > xmcount) {
								i3 = -1;
								i2 = -1;
								flag = false;
								cout << "ѡ�����" << endl;
							}
							else {
								cout << "ѡ��ɹ�" << endl;
							}
						}
						
						while (i3 != -1) {
							change_panel_display();//�޸�ѡ�����
							cin >> i3;
							//system("cls");
							if (i3 == 1) {//�޸�����
								cout << "������������" << endl;
								cin >> tmp;
								student* changep = stuList.xmget(fname,i4);
								(*changep).nameset(tmp);
							}
							else if (i3 == 2) {
								cout << "��������׼��֤��" << endl;
								cin >> tmp;
								if (stuList.xhfind(tmp) == true) {//��׼��֤�ż��
									cout << "���������������ظ�,���ʧ�ܣ��������������ַ���" << endl;
									cin >> i11;
									i2 = -1;
									system("cls");
								}
								else {
									student* changep = stuList.xmget(fname,i4);
									(*changep).numberset(tmp);
								}
							}
							else if (i3 == 3) {
								cout << "��������רҵ��" << endl;
								cin >> tmp;
								student* changep = stuList.xmget(fname,i4);
								(*changep).majornameset(tmp);
							}
							else if (i3 == 4) {
								cout << "���޸��Ƿ�ΪӦ����" << endl;
								cin >> tmp;
								student* changep = stuList.xmget(fname,i4);
								(*changep).boolfreshset(tmp);
							}
							else if (i3 == 5) {
								cout << "����������ѧ�ɼ�" << endl;
								cin >> tmp;
								student* changep = stuList.xmget(fname,i4);
								(*changep).mathset(tmp);
							}
							else if (i3 == 6) {
								cout << "������������ɼ�" << endl;
								cin >> tmp;
								student* changep = stuList.xmget(fname,i4);
								(*changep).Foreign_languageset(tmp);
							}
							else if (i3 == 7) {
								cout << "�����������γɼ�" << endl;
								cin >> tmp;
								student* changep = stuList.xmget(fname,i4);
								(*changep).politicsset(tmp);
							}
							else if (i3 == 8) {
								cout << "��������רҵ�γɼ�" << endl;
								cin >> tmp;
								student* changep = stuList.xmget(fname,i4);
								(*changep).majorset(tmp);
							}
							else if (i3 == -1) {
								flag = false;
							}
							else {
								cout << "�����������ȷ���룡" << endl;
								cin >> i3;//Ҫ����������i3
							}
							/*cout << "�޸���ɣ��������������ַ��أ�" << endl;
							cin >> i11;*/
							i3 = -1;//����һ���˵�
						}
						i2 = -1;
					}
					else {
						//����ʧ��
						cout << "���޴��ˣ�" << endl;
						/*cout << "�������������ַ��أ�" << endl;
						cin >> i11;*/
						i2 = -1;
					}
				}
				else if (i2 == 2) {//׼��֤��ѯ
					cout << "�������ѯ��׼��֤�ţ�" << endl;
					string xh;
					cin >> xh;
					system("cls");
					if (stuList.xhfind(xh) == true) {
						//���ҳɹ�
						flag = true;
						cout << "��ѯ�ɹ���" << endl;
						change_panel_display();//�޸�ѡ�����
						while (i3 != -1) {
							cin >> i3;
							//system("cls");
							if (i3 == 1) {//�޸�����
								cout << "������������" << endl;
								cin >> tmp;
								student* changep = stuList.xhget(xh);
								(*changep).nameset(tmp);
							}
							else if (i3 == 2) {
								cout << "��������׼��֤��" << endl;
								cin >> tmp;
								if (stuList.xhfind(tmp) == true) {//��׼��֤�ż��
									cout << "���������������ظ�,���ʧ�ܣ��������������ַ���" << endl;
									cin >> i11;
									i2 = -1;
									system("cls");
								}
								else {
									student* changep = stuList.xhget(xh);
									(*changep).numberset(tmp);
								}
							}
							else if (i3 == 3) {
								cout << "��������רҵ��" << endl;
								cin >> tmp;
								student* changep = stuList.xhget(xh);
								(*changep).majornameset(tmp);
							}
							else if (i3 == 4) {
								cout << "���޸��Ƿ�ΪӦ����" << endl;
								cin >> tmp;
								student* changep = stuList.xhget(xh);
								(*changep).boolfreshset(tmp);
							}
							else if (i3 == 5) {
								cout << "����������ѧ�ɼ�" << endl;
								cin >> tmp;
								student* changep = stuList.xhget(xh);
								(*changep).mathset(tmp);
							}
							else if (i3 == 6) {
								cout << "������������ɼ�" << endl;
								cin >> tmp;
								student* changep = stuList.xhget(xh);
								(*changep).Foreign_languageset(tmp);
							}
							else if (i3 == 7) {
								cout << "�����������γɼ�" << endl;
								cin >> tmp;
								student* changep = stuList.xhget(xh);
								(*changep).politicsset(tmp);
							}
							else if (i3 == 8) {
								cout << "��������רҵ�γɼ�" << endl;
								cin >> tmp;
								student* changep = stuList.xhget(xh);
								(*changep).majorset(tmp);
							}
							else if (i3 == -1) {
								flag = false;
							}
							else {
								cout << "�����������ȷ���룡" << endl;
								cin >> i3;//Ҫ����������i2
							}
							/*cout << "�޸���ɣ��������������ַ��أ�" << endl;
							cin >> i11;*/
							i3 = -1;
						}
						i2 = -1;//���أ�֮����Ǹ�д��
					}
					else {
						//����ʧ��
						cout << "���޴��ˣ�" << endl;
						/*cout << "�������������ַ��أ�" << endl;
						cin >> i11;*/
						i2 = -1;
					}
				}
				else if (i2 == -1) {
					flag = false;
				}
				else {
					cout << "�����������ȷ���룡" << endl;
					cin >> i2;//Ҫ����������i2
				}
			}
			if (flag == true) {
				rewrite(stuList);//��д
				cout << "�޸Ĳ���д���,�����������ַ���" << endl;
			}
			else {
				cout << "�޸�ʧ�ܣ��������������ַ���" << endl;
			}
			cin >> i11;
			system("cls");
		}
		else if (i1 == 3) {//ɾ����Ϣ
			cout << "ɾ����Ϣ" << endl;
			select_panel_display();
			while (i2 != -1) {//i2������-1��һֱɾ����Ϣ
				cin >> i2;
				system("cls");
				if (i2 == 1) {//������ѯ
					cout << "������������" << endl;
					string fname;
					cin >> fname;
					int xmcount = 0;//���ݳ��ִ���
					if (stuList.xmfind(fname,xmcount) == true) {
						//���ҳɹ�
						if (xmcount == 1) {
							cout << "��ѯ�ɹ���" << endl;
							i4 = 1;
						}
						else {
							//cout << xmcount << endl;//������
							stuList.dataprint(fname);
							cout << "���ظ�����������������ѡ��Ҫɾ���Ķ���" << endl;
							cin >> i4;
							if (i4 > xmcount) i2 = -1;
							else {
								cout << "ѡ��ɹ�" << endl;
							}
						}
						cout << "����1ȷ��ɾ�����������������˳�" << endl;
						cin >> qd;
						if (qd == 1) {
							student* deletep = stuList.xmget(fname,i4);
							stuList.remove(deletep);
							rewrite(stuList);//��д
							cout << "ɾ������д�ɹ����������������ַ��أ�" << endl;
							cin >> i11;
							system("cls");
							i2 = -1;//���ص�һ��
						}
						else {
							system("cls");
							i2 = -1;
						}

					}
					else {
						//����ʧ��
						cout << "���޴��ˣ�" << endl;
						cout << "�������������ַ��أ�" << endl;
						cin >> i11;
						system("cls");
						i2 = -1;
					}
				}
				else if (i2 == 2) {//׼��֤�Ų�ѯ
					cout << "������׼��֤�ţ�" << endl;
					string xh;
					cin >> xh;
					if (stuList.xhfind(xh) == true) {
						//���ҳɹ�
						cout << "��ѯ�ɹ���" << endl;
						cout << "����1ȷ��ɾ�����������������˳�" << endl;
						cin >> qd;
						if (qd == 1) {
							student* deletep = stuList.xhget(xh);
							stuList.remove(deletep);
							rewrite(stuList);//��д
							cout << "ɾ������д�ɹ����������������ַ��أ�" << endl;
							cin >> i11;
							system("cls");
							i2 = -1;//���ص�һ��
						}
						else {
							i2 = -1;
						}

					}
					else {
						//����ʧ��
						cout << "���޴��ˣ�" << endl;
						cout << "�������������ַ��أ�" << endl;
						cin >> i11;
						i2 = -1;
					}
				}
				else if(i2==-1){}
				else {
					cout << "�����������ȷ���룡" << endl;
					cin >> i2;//Ҫ����������i2
				}

			}
		}
		else if (i1 == 4) {//¼ȡ����
			cout << "--------¼ȡ����------" << endl;
			cout << "����������ܷ�Ҫ��" << endl;
			cin >> totalmin;
			cout << "��������ѧ��ͷ�Ҫ��" << endl;
			cin >> mathmin;
			cout << "������������ͷ�Ҫ��" << endl;
			cin >> flmin;
			cout << "������������ͷ�Ҫ��" << endl;
			cin >> plmin;
			cout << "������רҵ����ͷ�Ҫ��" << endl;
			cin >> mjmin;
			//���������ɸѡ��������
			AdmitList = stuList.filter(totalmin, mathmin, flmin, plmin, mjmin);
			AdmitList.sort();
			//���¼ȡ���,�ֱ�����Ļ���ļ����������
			resultout(AdmitList);
			cout << "�����ɣ��������������ַ���" << endl;
			cin >> i11;
			system("cls");
		}
		else if(i1==-1){}
		else {
			cout << "�����������������" << endl;
			function_panel_display();
			cin >> i1;
		}
	}

	cout << endl;
	cout << "ллʹ��" << endl;
	return 0;
}
void function_panel_display() {
	cout << "---------���˵�-------" << endl;
	cout << "1.������Ϣ" << endl;
	cout << "2.�޸���Ϣ" << endl;
	cout << "3.ɾ����Ϣ" << endl;
	cout << "4.¼ȡ����" << endl;
	cout << "----------------------" << endl;
	cout << "��ѡ��(1/2/3/4,-1Ϊ����)" << endl;
}
void select_panel_display() {
	cout << "---------��ѯ---------" << endl;
	cout << "1.������ѯ" << endl;
	cout << "2.׼��֤�Ų�ѯ" << endl;
	cout << "----------------------" << endl;
	cout << "��ѡ��(1/2/,-1Ϊ����)" << endl;
}
void change_panel_display() {
	cout << "---------�޸�---------" << endl;
	cout << "1.�޸�����" << endl;
	cout << "2.�޸�׼��֤��" << endl;
	cout << "3.�޸ı���רҵ" << endl;
	cout << "4.�޸��Ƿ�Ӧ����" << endl;
	cout << "5.�޸���ѧ�ɼ�" << endl;
	cout << "6.�޸�����ɼ�" << endl;
	cout << "7.�޸����γɼ�" << endl;
	cout << "8.�޸�רҵ�γɼ�" << endl;
	cout << "----------------------" << endl;
	cout << "��ѡ��(1~8,-1Ϊ����)" << endl;
}
void rewrite(StudentList rList) {//ˢ�¸�д
	ofstream outfile("D:/stuinformation.txt", ios::out);//���ļ���������������
	student* p = rList.gethead();
	while (p != NULL) {
		outfile << (*p).getname() << ' ' << (*p).getnumber() << ' ' << (*p).getmajorname() << ' ';
		outfile << (*p).getboolfresh() << ' ' << (*p).getmath() << ' ' << (*p).getForeign_language() << ' ';
		outfile << (*p).getpolitics() << ' ' << (*p).getmajor() << endl;
		p = p->next;
	}
	outfile.close();
}
void resultout(StudentList rList) {//������
	ofstream routfile("D:/ADMIT.txt", ios::out);//���ļ���������������
	student* p = rList.gethead();
	while (p != NULL) {
		//�ļ����
		routfile << (*p).getname() << ' ' << (*p).getnumber() << ' ' << (*p).getmajorname() << ' ';
		routfile << (*p).getboolfresh() << ' ' << (*p).getmath() << ' ' << (*p).getForeign_language() << ' ';
		routfile << (*p).getpolitics() << ' ' << (*p).getmajor() << "�ܷ�:" << (*p).totalscore() << endl;
		//��Ļ���
		cout << (*p).getname() << ' ' << (*p).getnumber() << ' ' << (*p).getmajorname() << ' ';
		cout << (*p).getboolfresh() << ' ' << (*p).getmath() << ' ' << (*p).getForeign_language() << ' ';
		cout << (*p).getpolitics() << ' ' << (*p).getmajor() << "�ܷ�:" << (*p).totalscore() << endl;
		p = p->next;
	}
	routfile << "¼ȡ������" << rList.getsize() << endl;
	cout << "¼ȡ������" << rList.getsize() << endl;
	routfile.close();//�ر�
}