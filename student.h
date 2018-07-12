#include<iostream>
#include<windows.h>
#include<string.h>
using namespace std;
class Student{
	public:
	Student();
	Student(Student & s);
	void infor_print();
	char name[15];
	char stu_num[15];
	float all_score;//学生的总分数
	float stu_score[7];//在一个数组中将所有科目的数据储存
};
Student::Student()
{
	strcpy(name,"0\0");
	//strcpy(major,"0\0");
	strcpy(stu_num,"0\0");
	for(int i=0;i<7;i++)
	{
		stu_score[i]=0;
	}
	all_score=0;
}
Student::Student(Student &s)
{
	strcpy(name,s.name);
	strcpy(stu_num,s.stu_num);
	for(int i=0;i<7;i++)
	{
		stu_score[i]=s.stu_score[i];
	}
	all_score=s.all_score;
}
void Student:: infor_print()
	{	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
		cout<<"********************************************************"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
		cout<<"姓名:";
		cout<<name<<endl;
		cout<<"学号:";
		cout<<stu_num<<endl;
		cout<<"专业:";
		//cout<<major<<endl;
		cout<<"英语"<<"    "<<"高数"<<"    "<<"物理"<<"    "<<"c++"<<"    "<<"模电"<<"    "
		<<"历史"<<"    "<<"体育"<<endl;
		for(int i=0;i<7;i++)
		{
			cout<<stu_score[i]<<"\t";
		}
		cout<<endl;
		
	}
