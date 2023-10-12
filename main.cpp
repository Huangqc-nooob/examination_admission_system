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
	int i11 = 0;//返回用工具人
	int i1 = 0;//一级选择
	int i2 = 0;//二级选择
	int i3 = 0;//三级选择
	int i4 = 0;//四级选择
	int qd = 0;//确定键
	string tmp;//输入用暂时存储
	StudentList stuList;//构建学生链表
	StudentList AdmitList;//录取链表
	int totalmin, mathmin,flmin, plmin, mjmin;//记录最低分数
	ifstream infile("D:/stuinformation.txt", ios::in);//读取信息
	if (!infile)//打开文件的检错
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	string vname, num1, mname, bf, num2, num3, num4, num5;
	while (infile >> vname >> num1 >> mname >> bf >> num2 >> num3 >> num4 >> num5) {
		student stu(vname, num1, mname, bf, num2, num3, num4, num5);
		//链表添加
		stuList.add(stu);
	}
	infile.close();//关闭了先
	if (stuList.chachong() == true) {
		cerr << "准考证号重复，文件有误！" << endl;
		exit(1);
	}
	while (i1 != -1) {//主程序
		i2 = 0;//刷新一下
		i3 = 0;
		function_panel_display();//功能面板的显示
		cin >> i1;
		system("cls");
		if (i1 == 1) {//新增信息，无限新增这个功能到时候再看吧，反正一个while的事情
			cout << "新增信息" << endl;
			cout << "请输入姓名，准考证号，专业名，是否应届生，数学成绩，外语成绩，政治成绩，专业成绩" << endl;
			cin >> vname >> num1 >> mname >> bf >> num2 >> num3 >> num4 >> num5;
			student stu(vname, num1, mname, bf, num2, num3, num4, num5);
			if (stuList.xhfind(num1) == true) {
				cout << "输入与现有数据重复,添加失败，请输入任意数字返回" << endl;
				cin >> i11;
				system("cls");
			}
			else {
				stuList.add(stu);//链表添加
				rewrite(stuList);//覆写
				cout << "添加并覆写完成,输入任意数字返回" << endl;
				cin >> i11;
				system("cls");
			}
		}
		else if (i1 == 2) {//修改信息
			bool flag;
			cout << "修改信息" << endl;
			select_panel_display();
			while (i2 != -1) {//i2不等于-1就一直在修改信息
				//cout << "输入i2" << endl;
				flag = false;
				cin >> i2;
				system("cls");
				if (i2 == 1) {//姓名查询
					cout << "请输入查询的姓名！" << endl;
					string fname;
					cin >> fname;
					system("cls");
					int xmcount = 0;//传递出现次数
					if (stuList.xmfind(fname,xmcount) == true) {
						//查找成功
						flag = true;
						if (xmcount == 1) {
							cout << "查询成功！" << endl;
							i4 = 1;
						}
						else {
							//cout << xmcount << endl;//测试用
							stuList.dataprint(fname);//展示重复姓名
							cout << "有重复姓名，请输入数字选择要修改的对象" << endl;
							cin >> i4;
							if (i4 > xmcount) {
								i3 = -1;
								i2 = -1;
								flag = false;
								cout << "选择错误！" << endl;
							}
							else {
								cout << "选择成功" << endl;
							}
						}
						
						while (i3 != -1) {
							change_panel_display();//修改选择面板
							cin >> i3;
							//system("cls");
							if (i3 == 1) {//修改名字
								cout << "请输入新名字" << endl;
								cin >> tmp;
								student* changep = stuList.xmget(fname,i4);
								(*changep).nameset(tmp);
							}
							else if (i3 == 2) {
								cout << "请输入新准考证号" << endl;
								cin >> tmp;
								if (stuList.xhfind(tmp) == true) {//对准考证号检错
									cout << "输入与现有数据重复,添加失败，请输入任意数字返回" << endl;
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
								cout << "请输入新专业名" << endl;
								cin >> tmp;
								student* changep = stuList.xmget(fname,i4);
								(*changep).majornameset(tmp);
							}
							else if (i3 == 4) {
								cout << "请修改是否为应届生" << endl;
								cin >> tmp;
								student* changep = stuList.xmget(fname,i4);
								(*changep).boolfreshset(tmp);
							}
							else if (i3 == 5) {
								cout << "请输入新数学成绩" << endl;
								cin >> tmp;
								student* changep = stuList.xmget(fname,i4);
								(*changep).mathset(tmp);
							}
							else if (i3 == 6) {
								cout << "请输入新外语成绩" << endl;
								cin >> tmp;
								student* changep = stuList.xmget(fname,i4);
								(*changep).Foreign_languageset(tmp);
							}
							else if (i3 == 7) {
								cout << "请输入新政治成绩" << endl;
								cin >> tmp;
								student* changep = stuList.xmget(fname,i4);
								(*changep).politicsset(tmp);
							}
							else if (i3 == 8) {
								cout << "请输入新专业课成绩" << endl;
								cin >> tmp;
								student* changep = stuList.xmget(fname,i4);
								(*changep).majorset(tmp);
							}
							else if (i3 == -1) {
								flag = false;
							}
							else {
								cout << "输入错误，请正确输入！" << endl;
								cin >> i3;//要求重新输入i3
							}
							/*cout << "修改完成，请输入任意数字返回！" << endl;
							cin >> i11;*/
							i3 = -1;//返回一级菜单
						}
						i2 = -1;
					}
					else {
						//查找失败
						cout << "查无此人！" << endl;
						/*cout << "请输入任意数字返回！" << endl;
						cin >> i11;*/
						i2 = -1;
					}
				}
				else if (i2 == 2) {//准考证查询
					cout << "请输入查询的准考证号！" << endl;
					string xh;
					cin >> xh;
					system("cls");
					if (stuList.xhfind(xh) == true) {
						//查找成功
						flag = true;
						cout << "查询成功！" << endl;
						change_panel_display();//修改选择面板
						while (i3 != -1) {
							cin >> i3;
							//system("cls");
							if (i3 == 1) {//修改名字
								cout << "请输入新名字" << endl;
								cin >> tmp;
								student* changep = stuList.xhget(xh);
								(*changep).nameset(tmp);
							}
							else if (i3 == 2) {
								cout << "请输入新准考证号" << endl;
								cin >> tmp;
								if (stuList.xhfind(tmp) == true) {//对准考证号检错
									cout << "输入与现有数据重复,添加失败，请输入任意数字返回" << endl;
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
								cout << "请输入新专业名" << endl;
								cin >> tmp;
								student* changep = stuList.xhget(xh);
								(*changep).majornameset(tmp);
							}
							else if (i3 == 4) {
								cout << "请修改是否为应届生" << endl;
								cin >> tmp;
								student* changep = stuList.xhget(xh);
								(*changep).boolfreshset(tmp);
							}
							else if (i3 == 5) {
								cout << "请输入新数学成绩" << endl;
								cin >> tmp;
								student* changep = stuList.xhget(xh);
								(*changep).mathset(tmp);
							}
							else if (i3 == 6) {
								cout << "请输入新外语成绩" << endl;
								cin >> tmp;
								student* changep = stuList.xhget(xh);
								(*changep).Foreign_languageset(tmp);
							}
							else if (i3 == 7) {
								cout << "请输入新政治成绩" << endl;
								cin >> tmp;
								student* changep = stuList.xhget(xh);
								(*changep).politicsset(tmp);
							}
							else if (i3 == 8) {
								cout << "请输入新专业课成绩" << endl;
								cin >> tmp;
								student* changep = stuList.xhget(xh);
								(*changep).majorset(tmp);
							}
							else if (i3 == -1) {
								flag = false;
							}
							else {
								cout << "输入错误，请正确输入！" << endl;
								cin >> i3;//要求重新输入i2
							}
							/*cout << "修改完成，请输入任意数字返回！" << endl;
							cin >> i11;*/
							i3 = -1;
						}
						i2 = -1;//返回，之后就是覆写了
					}
					else {
						//查找失败
						cout << "查无此人！" << endl;
						/*cout << "请输入任意数字返回！" << endl;
						cin >> i11;*/
						i2 = -1;
					}
				}
				else if (i2 == -1) {
					flag = false;
				}
				else {
					cout << "输入错误，请正确输入！" << endl;
					cin >> i2;//要求重新输入i2
				}
			}
			if (flag == true) {
				rewrite(stuList);//覆写
				cout << "修改并覆写完成,输入任意数字返回" << endl;
			}
			else {
				cout << "修改失败，请输入任意数字返回" << endl;
			}
			cin >> i11;
			system("cls");
		}
		else if (i1 == 3) {//删除信息
			cout << "删除信息" << endl;
			select_panel_display();
			while (i2 != -1) {//i2不等于-1就一直删除信息
				cin >> i2;
				system("cls");
				if (i2 == 1) {//姓名查询
					cout << "请输入姓名！" << endl;
					string fname;
					cin >> fname;
					int xmcount = 0;//传递出现次数
					if (stuList.xmfind(fname,xmcount) == true) {
						//查找成功
						if (xmcount == 1) {
							cout << "查询成功！" << endl;
							i4 = 1;
						}
						else {
							//cout << xmcount << endl;//测试用
							stuList.dataprint(fname);
							cout << "有重复姓名，请输入数字选择要删除的对象" << endl;
							cin >> i4;
							if (i4 > xmcount) i2 = -1;
							else {
								cout << "选择成功" << endl;
							}
						}
						cout << "输入1确认删除，输入其他数字退出" << endl;
						cin >> qd;
						if (qd == 1) {
							student* deletep = stuList.xmget(fname,i4);
							stuList.remove(deletep);
							rewrite(stuList);//覆写
							cout << "删除并覆写成功，请输入任意数字返回！" << endl;
							cin >> i11;
							system("cls");
							i2 = -1;//返回到一级
						}
						else {
							system("cls");
							i2 = -1;
						}

					}
					else {
						//查找失败
						cout << "查无此人！" << endl;
						cout << "请输入任意数字返回！" << endl;
						cin >> i11;
						system("cls");
						i2 = -1;
					}
				}
				else if (i2 == 2) {//准考证号查询
					cout << "请输入准考证号！" << endl;
					string xh;
					cin >> xh;
					if (stuList.xhfind(xh) == true) {
						//查找成功
						cout << "查询成功！" << endl;
						cout << "输入1确认删除，输入其他数字退出" << endl;
						cin >> qd;
						if (qd == 1) {
							student* deletep = stuList.xhget(xh);
							stuList.remove(deletep);
							rewrite(stuList);//覆写
							cout << "删除并覆写成功，请输入任意数字返回！" << endl;
							cin >> i11;
							system("cls");
							i2 = -1;//返回到一级
						}
						else {
							i2 = -1;
						}

					}
					else {
						//查找失败
						cout << "查无此人！" << endl;
						cout << "请输入任意数字返回！" << endl;
						cin >> i11;
						i2 = -1;
					}
				}
				else if(i2==-1){}
				else {
					cout << "输入错误，请正确输入！" << endl;
					cin >> i2;//要求重新输入i2
				}

			}
		}
		else if (i1 == 4) {//录取设置
			cout << "--------录取设置------" << endl;
			cout << "请输入最低总分要求" << endl;
			cin >> totalmin;
			cout << "请输入数学最低分要求" << endl;
			cin >> mathmin;
			cout << "请输入外语最低分要求" << endl;
			cin >> flmin;
			cout << "请输入政治最低分要求" << endl;
			cin >> plmin;
			cout << "请输入专业课最低分要求" << endl;
			cin >> mjmin;
			//对链表进行筛选，并排序
			AdmitList = stuList.filter(totalmin, mathmin, flmin, plmin, mjmin);
			AdmitList.sort();
			//输出录取结果,分别在屏幕和文件中输出排序
			resultout(AdmitList);
			cout << "输出完成，请输入任意数字返回" << endl;
			cin >> i11;
			system("cls");
		}
		else if(i1==-1){}
		else {
			cout << "输入错误！请重新输入" << endl;
			function_panel_display();
			cin >> i1;
		}
	}

	cout << endl;
	cout << "谢谢使用" << endl;
	return 0;
}
void function_panel_display() {
	cout << "---------主菜单-------" << endl;
	cout << "1.新增信息" << endl;
	cout << "2.修改信息" << endl;
	cout << "3.删除信息" << endl;
	cout << "4.录取设置" << endl;
	cout << "----------------------" << endl;
	cout << "请选择(1/2/3/4,-1为结束)" << endl;
}
void select_panel_display() {
	cout << "---------查询---------" << endl;
	cout << "1.姓名查询" << endl;
	cout << "2.准考证号查询" << endl;
	cout << "----------------------" << endl;
	cout << "请选择(1/2/,-1为结束)" << endl;
}
void change_panel_display() {
	cout << "---------修改---------" << endl;
	cout << "1.修改姓名" << endl;
	cout << "2.修改准考证号" << endl;
	cout << "3.修改报考专业" << endl;
	cout << "4.修改是否应届生" << endl;
	cout << "5.修改数学成绩" << endl;
	cout << "6.修改外语成绩" << endl;
	cout << "7.修改政治成绩" << endl;
	cout << "8.修改专业课成绩" << endl;
	cout << "----------------------" << endl;
	cout << "请选择(1~8,-1为结束)" << endl;
}
void rewrite(StudentList rList) {//刷新覆写
	ofstream outfile("D:/stuinformation.txt", ios::out);//打开文件，拷贝链表输入
	student* p = rList.gethead();
	while (p != NULL) {
		outfile << (*p).getname() << ' ' << (*p).getnumber() << ' ' << (*p).getmajorname() << ' ';
		outfile << (*p).getboolfresh() << ' ' << (*p).getmath() << ' ' << (*p).getForeign_language() << ' ';
		outfile << (*p).getpolitics() << ' ' << (*p).getmajor() << endl;
		p = p->next;
	}
	outfile.close();
}
void resultout(StudentList rList) {//输出结果
	ofstream routfile("D:/ADMIT.txt", ios::out);//打开文件，拷贝链表输入
	student* p = rList.gethead();
	while (p != NULL) {
		//文件输出
		routfile << (*p).getname() << ' ' << (*p).getnumber() << ' ' << (*p).getmajorname() << ' ';
		routfile << (*p).getboolfresh() << ' ' << (*p).getmath() << ' ' << (*p).getForeign_language() << ' ';
		routfile << (*p).getpolitics() << ' ' << (*p).getmajor() << "总分:" << (*p).totalscore() << endl;
		//屏幕输出
		cout << (*p).getname() << ' ' << (*p).getnumber() << ' ' << (*p).getmajorname() << ' ';
		cout << (*p).getboolfresh() << ' ' << (*p).getmath() << ' ' << (*p).getForeign_language() << ' ';
		cout << (*p).getpolitics() << ' ' << (*p).getmajor() << "总分:" << (*p).totalscore() << endl;
		p = p->next;
	}
	routfile << "录取人数：" << rList.getsize() << endl;
	cout << "录取人数：" << rList.getsize() << endl;
	routfile.close();//关闭
}