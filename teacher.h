#include<iostream>
#include<string.h>
#include<fstream>
#include"student.h"
using namespace std;
class Teacher{
public:
	Teacher();			   //���캯��
	int own_num();
	Student getstu(int tem)
	{
		return student[tem];
	}
	void show();
	void write_student1(); //д��ѧ����Ϣ
	void read_student1(); //��ȡѧ����Ϣ
	void delete1();		//ɾ��ѧ����Ϣ
	void add1();				//����ѧ����Ϣ
	void modify1();			   //�޸�ѧ����Ϣ
	void score_sort1();			//��ѧ����Ϣ���� 
	void edit_secret1();	//������ʦ�˺ŵ�����
	int search1(char *num); //����ѧ������ 
	//void search1(char *name)		 ������������
private:
	char log_num[15];			//��ʦ���ʺ�
	char log_secret[15];		//��ʦ������
	Student student[100];		//��ʦ�����ѧ����Ŀ
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
		cout<<"��Ϣ�����ɹ�"<<endl;
	}
	else
		cout<<"�ļ���ʧ��"<<endl;
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
		cout<<"����ʧ��"<<endl;
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
	cout<<"��������ԭ�ȵ����룺"<<endl;
	cin>>log_secret1;
	k=strcmp(log_secret,log_secret1);
	if(k==0)
	{
		cout<<"��������Ҫ�޸ĵ�����:"<<endl;
		cin>>log_num;
	}
	else
		cout<<"��Ϊ�����ԭ���������⣬�������������޸�"<<endl;
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
		cout<<"����֧��100��ѧ����¼��"<<endl;
		else
		{
			cout<<"�����������ѧ����������"<<endl;
			cin>>stu_name1;
			strcpy(student[i].name,stu_name1);
			cout<<"�����������ѧ����ѧ�ţ�"<<endl;
			cin>>student[i].stu_num;
			cout<<"���������룬Ӣ�����������c++��ģ�磬��ʷ������";
			student[i].all_score=0;
			for(int j=0;j<7;j++)
			{
				cin>>student[i].stu_score[j];
				student[i].all_score=student[i].all_score+student[i].stu_score[j];
			}	
			cout<<"ѧ�����ܷ���Ϊ��"<<student[i].all_score<<endl;
		}
	}
}
void Teacher::delete1()
{	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
	int m=own_num();
	Student s2;
	cout<<"��������Ҫɾ����ѧ����ѧ�ţ�"<<endl;
	char num[15];
	cin>>num;
	int  tem=search1(num);
	if(tem==-1)
	cout<<"δ���ҵ���Ҫ���ҵ�ѧ��"<<endl;
	else
	{ 
		strcpy(student[tem].name,"0\0");
		strcpy(student[tem].stu_num,"0\0");
		for(int i=0;i<7;i++)
		student[tem].stu_score[i]=0;
		student[tem].all_score=0;
		cout<<"�Ѿ�ɾ����ѧ����Ϣ"<<endl;
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
	cout<<"������Ҫ�޸�ѧ����ѧ��"<<endl; 
	cin>>num;
	int tem=search1(num);
	if(tem==-1)
	cout<<"δ���ҵ������ҵ�ѧ��ѧ��,����ѧ��"<<endl;
	else
	 {
		cout<<"�밴�����±���޸ģ�"<<endl; 
		cout<<"                   1.�޸�����"<<endl;
		cout<<"                   2.�޸�ѧ��"<<endl; 
		cout<<"                   3.�޸�ѧ���ɼ���Ϣ"<<endl; 
		cin>>c;
		switch(c)
		{
		case 'a' :{
					cout<<"������Ҫ�޸ĵ�����"<<endl;		
					cin>>tem_name;
					strcpy(student[tem].name,tem_name);
					break;
				}
		case 'b' :{
					cout<<"������Ҫ�޸ĵ�ѧ��"<<endl;
					cin>>tem_num;
					strcpy(student[tem].stu_num ,tem_num);
					break;
				}
		case 'c':{
					cout<<"������Ҫ�޸ĵĳɼ���Ϣ,��ע���Ŀ������˳��"<<endl; 
					for(int i=0;i<7;i++)
					{
						cin>>student[tem].stu_score[i];
					}
					break;
				}
		default:{
			cout<<"��������"<<endl; 
			break;
		}	
		}			
	}
} 

