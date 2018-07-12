#include<iostream>
#include"teacher.h"
#include"windows.h"
using namespace std;

int main()
{
	void mainpage();
	void teacherpage();
	Teacher t;
	char c;
	while(1)
	{
		mainpage();
		cin>>c;
		if(c=='1') //进入学生端口
		{
			system("cls");
			cout<<"请输入你的学号："<<endl;
			char num[15];
			int i;
			Student s;
			cin>>num;
			i=t.search1(num);
			if(i==-1)
			cout<<"未能查找到你的学号"<<endl;
			else
			{
			s=t.getstu(i);
			s.infor_print();
			}
		}
		else
			if(c=='2')//进入教师端口
			{
				system("cls");
				teacherpage();
				char m;
				cin>>m;
				switch(m)
				{
				case '1':{			//添加一个人的信息。
							system("cls");
							t.add1 ();		
							break;
							}
				case '2':{		//删除学生信息
							system("cls");
							t.delete1();
							break;
							}
				case '3':{		//修改学生信息
							system("cls");
							t.modify1 ();
							break;
							}
				case '4':{		//学生总成绩排序
							system("cls"); 
							t.score_sort1();	
							break;
							}
				case '5':{      //打印所有登记学生的信息
						 system("cls");
						 t.show();
						 }
				case '6':{	//修改老师帐号和密码
							system("cls");
							t.edit_secret1();
						 }
				case '7':{
						 system("cls");
						 t.write_student1();
						 cout<<"信息写入成功"<<endl;
						 }
				case '8':{
						 system("cls");
						 t.read_student1();
						 
						 }
				default:{
							system("cls");
							cout<<"输入错误"<<endl;
							break;
						}
				}
			}
			else
			cout<<"输入错误；"<<endl;
	}
return 0;
}
void mainpage()
{
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
	cout<<"                             ********************"<<endl;
	cout<<"                             * 学生成绩管理系统 *"<<endl; 
	cout<<"                             *     1.学生端口   *"<<endl; 
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
	cout<<"                             *     2.教师端口   *"<<endl;
	cout<<"                             ********************"<<endl;
	cout<<"                             请选择你要进入的端口"<<endl;
	cout<<"                             choose  your   house"<<endl; 
}

void teacherpage()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
	cout<<endl<<endl<<endl<<endl<<endl;	
	cout<<"                             ***********************"<<endl;
	cout<<"                             *  1.添加学生的信息   *"<<endl; 
	cout<<"                             *  2.删除学生信息     *"<<endl;
	cout<<"                             *  3.修改学生信息     *"<<endl;
	cout<<"                             *  4.学生成绩排序     *"<<endl;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
	cout<<"                             *  5.打印所有学生成绩 *"<<endl;
	cout<<"                             *  6.修改老师帐号密码 *"<<endl;
	cout<<"                             *  7.保存本次学生信息 *"<<endl;
	cout<<"                             *  8.读入上次学生信息 *"<<endl;
	cout<<"                             ***********************"<<endl;
	cout<<"                             请选择你要进入的端口"<<endl;
	cout<<"                             choose  your   house"<<endl;
}
