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
		if(c=='1') //����ѧ���˿�
		{
			system("cls");
			cout<<"���������ѧ�ţ�"<<endl;
			char num[15];
			int i;
			Student s;
			cin>>num;
			i=t.search1(num);
			if(i==-1)
			cout<<"δ�ܲ��ҵ����ѧ��"<<endl;
			else
			{
			s=t.getstu(i);
			s.infor_print();
			}
		}
		else
			if(c=='2')//�����ʦ�˿�
			{
				system("cls");
				teacherpage();
				char m;
				cin>>m;
				switch(m)
				{
				case '1':{			//���һ���˵���Ϣ��
							system("cls");
							t.add1 ();		
							break;
							}
				case '2':{		//ɾ��ѧ����Ϣ
							system("cls");
							t.delete1();
							break;
							}
				case '3':{		//�޸�ѧ����Ϣ
							system("cls");
							t.modify1 ();
							break;
							}
				case '4':{		//ѧ���ܳɼ�����
							system("cls"); 
							t.score_sort1();	
							break;
							}
				case '5':{      //��ӡ���еǼ�ѧ������Ϣ
						 system("cls");
						 t.show();
						 }
				case '6':{	//�޸���ʦ�ʺź�����
							system("cls");
							t.edit_secret1();
						 }
				case '7':{
						 system("cls");
						 t.write_student1();
						 cout<<"��Ϣд��ɹ�"<<endl;
						 }
				case '8':{
						 system("cls");
						 t.read_student1();
						 
						 }
				default:{
							system("cls");
							cout<<"�������"<<endl;
							break;
						}
				}
			}
			else
			cout<<"�������"<<endl;
	}
return 0;
}
void mainpage()
{
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
	cout<<"                             ********************"<<endl;
	cout<<"                             * ѧ���ɼ�����ϵͳ *"<<endl; 
	cout<<"                             *     1.ѧ���˿�   *"<<endl; 
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
	cout<<"                             *     2.��ʦ�˿�   *"<<endl;
	cout<<"                             ********************"<<endl;
	cout<<"                             ��ѡ����Ҫ����Ķ˿�"<<endl;
	cout<<"                             choose  your   house"<<endl; 
}

void teacherpage()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
	cout<<endl<<endl<<endl<<endl<<endl;	
	cout<<"                             ***********************"<<endl;
	cout<<"                             *  1.���ѧ������Ϣ   *"<<endl; 
	cout<<"                             *  2.ɾ��ѧ����Ϣ     *"<<endl;
	cout<<"                             *  3.�޸�ѧ����Ϣ     *"<<endl;
	cout<<"                             *  4.ѧ���ɼ�����     *"<<endl;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
	cout<<"                             *  5.��ӡ����ѧ���ɼ� *"<<endl;
	cout<<"                             *  6.�޸���ʦ�ʺ����� *"<<endl;
	cout<<"                             *  7.���汾��ѧ����Ϣ *"<<endl;
	cout<<"                             *  8.�����ϴ�ѧ����Ϣ *"<<endl;
	cout<<"                             ***********************"<<endl;
	cout<<"                             ��ѡ����Ҫ����Ķ˿�"<<endl;
	cout<<"                             choose  your   house"<<endl;
}
