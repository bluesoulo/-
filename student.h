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
	float all_score;//ѧ�����ܷ���
	float stu_score[7];//��һ�������н����п�Ŀ�����ݴ���
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
		cout<<"����:";
		cout<<name<<endl;
		cout<<"ѧ��:";
		cout<<stu_num<<endl;
		cout<<"רҵ:";
		//cout<<major<<endl;
		cout<<"Ӣ��"<<"    "<<"����"<<"    "<<"����"<<"    "<<"c++"<<"    "<<"ģ��"<<"    "
		<<"��ʷ"<<"    "<<"����"<<endl;
		for(int i=0;i<7;i++)
		{
			cout<<stu_score[i]<<"\t";
		}
		cout<<endl;
		
	}
