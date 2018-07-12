#include<iostream>
#include<string.h>
#include<fstream>
#include"student.h"
using namespace std;
class Teacher{
public:
	Teacher();			   //构造函数
	int own_num();
	Student getstu(int tem)
	{
		return student[tem];
	}
	void show();
	void write_student1(); //写入学生信息
	void read_student1(); //读取学生信息
	void delete1();		//删除学生信息
	void add1();				//增加学生信息
	void modify1();			   //修改学生信息
	void score_sort1();			//将学生信息排序 
	void edit_secret1();	//设置老师账号的密码
	int search1(char *num); //按照学号搜索 
	//void search1(char *name)		 按照名字搜索
private:
	char log_num[15];			//老师的帐号
	char log_secret[15];		//老师的密码
	Student student[100];		//老师管理的学生数目
};
void Teacher::write_student1()
{
	ofstream os("student",ios_base::out|ios_base::binary);
	int tem=own_num();
	for(int i=0;i<tem;i++)
	{
	os.write(reinterpret_cast<char*>(&student[i]),sizeof(student[i]));
	os.close();
	}
}
void Teacher::read_student1()
{
	ifstream is("student",ios_base::in|ios_base::binary);
	int tem=own_num();
	if(is)
	{
		for(int i=0;i<tem;i++)
		{
			is.read(reinterpret_cast<char*>(&student[i]),sizeof(student[i]));
		}
		cout<<"信息读出成功"<<endl;
	}
	else
		cout<<"文件打开失败"<<endl;
	is.close();
}
void Teacher::show()
{
	int m=own_num();
	for(int i=0;i<m;i++)
	{
	student[i].infor_print();
	}
}
int Teacher::own_num()
{
	int i,j;
	for(i=0;;i++)
	{
		j=strcmp(student[i].stu_num,"0\0");
		if(j==0)
		break;
	}
return i;	
}
int Teacher::search1(char *num)
{
	int i=0;
	bool b=0;
	while(b==0)
	{
		int j;
		j=strcmp(num,student[i].stu_num);
		if(j==0)
			{
				b=1;
				break;
			}
		else
			b=0;
		if(i==100)
		{
		cout<<"查找失败"<<endl;
		break;
		}
		i++;
	}
	if(b==1)
	return i;
	else
	return -1;
}
Teacher::Teacher()
{
	strcpy(log_num,"0\0");
	strcpy(log_secret,"0\0");
}
void Teacher::edit_secret1()
{	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
	char log_secret1[15];
	bool k;
	cout<<"请输入你原先的密码："<<endl;
	cin>>log_secret1;
	k=strcmp(log_secret,log_secret1);
	if(k==0)
	{
		cout<<"请输入需要修改的密码:"<<endl;
		cin>>log_num;
	}
	else
		cout<<"因为输入的原密码有问题，不能完成密码的修改"<<endl;
}
void Teacher::add1()
{	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
	int i=own_num();
	char stu_name1[15];
	char stu_num[15];
	for(;i<100;i++)
	{
		if(strcmp(student[i].stu_num,"0\0"))
		break;
		if(i>=100)
		cout<<"仅仅支持100名学生的录入"<<endl;
		else
		{
			cout<<"请输入所添加学生的姓名："<<endl;
			cin>>stu_name1;
			strcpy(student[i].name,stu_name1);
			cout<<"请输入所添加学生的学号："<<endl;
			cin>>student[i].stu_num;
			cout<<"请依次输入，英语，高数，物理，c++，模电，历史，体育";
			student[i].all_score=0;
			for(int j=0;j<7;j++)
			{
				cin>>student[i].stu_score[j];
				student[i].all_score=student[i].all_score+student[i].stu_score[j];
			}	
			cout<<"学生的总分数为："<<student[i].all_score<<endl;
		}
	}
}
void Teacher::delete1()
{	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
	int m=own_num();
	Student s2;
	cout<<"请输入你要删除的学生的学号："<<endl;
	char num[15];
	cin>>num;
	int  tem=search1(num);
	if(tem==-1)
	cout<<"未能找到你要查找的学号"<<endl;
	else
	{ 
		strcpy(student[tem].name,"0\0");
		strcpy(student[tem].stu_num,"0\0");
		for(int i=0;i<7;i++)
		student[tem].stu_score[i]=0;
		student[tem].all_score=0;
		cout<<"已经删除该学生信息"<<endl;
		for(int i=tem;i<m-1;i++)
		student[i]=student[i+1];
	}
}
void Teacher::score_sort1() 
{
	int tem=own_num();
	Student s;
	for(int j=0;j<tem;j++)
	{
		s=student[j];
		for(int m=j;m<tem;m++)
		{
			if(student[m].all_score>s.all_score )
				s=student[m];
		}
		student[j]=s;
	}	
}
void Teacher::modify1()
{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
	char num[15];
	char tem_name[15];
	char tem_num[15];
	float tem_score[7];
	char c;
	cout<<"请输入要修改学生的学号"<<endl; 
	cin>>num;
	int tem=search1(num);
	if(tem==-1)
	cout<<"未能找到所查找的学生学号,请检查学号"<<endl;
	else
	 {
		cout<<"请按照以下编号修改："<<endl; 
		cout<<"                   1.修改姓名"<<endl;
		cout<<"                   2.修改学号"<<endl; 
		cout<<"                   3.修改学生成绩信息"<<endl; 
		cin>>c;
		switch(c)
		{
		case 'a' :{
					cout<<"请输入要修改的姓名"<<endl;		
					cin>>tem_name;
					strcpy(student[tem].name,tem_name);
					break;
				}
		case 'b' :{
					cout<<"请输入要修改的学号"<<endl;
					cin>>tem_num;
					strcpy(student[tem].stu_num ,tem_num);
					break;
				}
		case 'c':{
					cout<<"请输入要修改的成绩信息,请注意科目的输入顺序"<<endl; 
					for(int i=0;i<7;i++)
					{
						cin>>student[tem].stu_score[i];
					}
					break;
				}
		default:{
			cout<<"输入有误"<<endl; 
			break;
		}	
		}			
	}
} 

