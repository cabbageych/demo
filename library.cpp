#include<iostream>
#include<cstdlib>
#include<string>
#include<windows.h>
#include<fstream>
#include<ctime>
#include<conio.h>
#define mid 28
using namespace std;
struct lib
{
	char name[100];//����  
	char author[100]; //����
    double price;//�۸� 
	int number;//����� 
};
struct stu
{
	char name[100];//����
	char xh[100];//ѧ��
	int	 date1;//�������� 
	char bn[100];//���� 
	char bh[100];//�鱾��� 
};
void initialize_screen()
{
	int pw,count=0;
	for(int i=0;i<mid;i++)	cout<<" ";
	cout<<"***ͼ�����ϵͳ***\n";
	for(int i=0;i<=6;i++)
	{
		for(int j=0;j<mid;j++)	cout<<" ";
		if(i==0)	cout<<"1 ����ͼ��\n"; 
		if(i==1)	cout<<"2 �黹ͼ��\n"; 
		if(i==2)	cout<<"3 ����ͼ��\n"; 
		if(i==3)	cout<<"4 ͼ����Ϣ��ѯ\n";
		if(i==4)	cout<<"5 ͼ����Ϣ�޸�\n";
		if(i==5)	cout<<"6 ѧ��������Ϣ��ѯ\n";
		if(i==6)	cout<<"7 �˳�\n"; 
	}
}
void add_books()  //�鼮��� 
{
	char a;
	FILE *p;
	ofstream fin;
	ifstream fout;
	lib books[1000];
	int count=0;
	double price; 
	char bh[100]; 
	fout.open("books.data");
	while(!fout.eof())	fout.read((char *)&books[count++],sizeof books[count-1]);
	fout.close();
	cout<<"������";
	cin>>books[count].name; 
	cout<<"���ߣ�";
	cin>>books[count].author;
    cout<<"�۸�";
	cin>>books[count].price;  
	cout<<"�����Ŀ��";
	cin>>books[count].number; 
	fin.open("books.data");
	for(int i=0;i<=count;i++)
    	fin.write((char *)&books[i],sizeof books[i]);
    fin.close(); 
    cout<<"��Ϣ�Ѹ���\n";
}
void lend_books() //�����鼮 
{
	char a;
	FILE *p; 
	ofstream fin,fin1;
	ifstream fout,fout1;
	char bn[100],pn[100];
	int	count=0,count1=0,date1,c=0;
	lib books[1000];
	stu students[1000]; 
	fout.open("books.data");
	while(!fout.eof())	fout.read((char *)&books[count++],sizeof books[count-1]);
	fout.close();
	fout1.open("students.data");
	while(!fout1.eof())	fout1.read((char *)&students[c++],sizeof students[c-1]);
	fout1.close();
	cout<<"ͼ�����֣�";
	cin>>bn;
	for(int i=0;i<count;i++)
	{
		if(!strcmp(bn,books[i].name))
		{
			++count1;
			if(books[i].number==0)
			{
				cout<<"�����ѽ��꣡\n";
				break; 
			}
			else
			{
				cout<<"������ѧ�ţ�"; 
				cin>>students[c].xh;
				cout<<"������������"; 
				cin>>students[c].name;
				cout<<"�鱾��ţ�"; 
				cin>>students[c].bh;
				cout<<"�������ڣ�";
				cin>>date1;
				students[c].date1=date1;
				strcpy(students[c].bn,books[i].name);
				books[i].number-=1;
				fin.open("books.data");
				for(int i=0;i<count;i++)
    				fin.write((char *)&books[i],sizeof books[i]);
				fin.close();
				fin1.open("students.data");
				for(int i=0;i<c+1;i++)
    				fin1.write((char *)&students[i],sizeof students[i]);
				fin1.close();
				cout<<"��Ϣ�Ѹ��£�\n"; 
				break;		
			}	
		}
	}
	if(count1==0)	cout<<"û���Ȿ�飡\n";	
}
void return_books() //�黹ͼ�� 
{
	char a;
	FILE *p; 
	ofstream fin,fin1;
	ifstream fout,fout1;
	char bn[100],pn[100],temp[100],temp1[100];
	int	count=0,count1=0,c=0;
	lib books[1000];
	stu students[1000];
	fout.open("books.data");
	while(!fout.eof())	fout.read((char *)&books[count++],sizeof books[count-1]);
	fout.close();
	fout1.open("students.data");
	while(!fout1.eof())	fout1.read((char *)&students[c++],sizeof students[c-1]);
	fout1.close();
	cout<<"�黹��������"; 
	cin>>temp;
	cout<<"ѧ��������"; 
	cin>>temp1;
	for(int i=0;i<count;i++)
	{
		if(!strcmp(temp,books[i].name))
		{
			books[i].number+=1;
			fin.open("books.data");
			for(int i=0;i<count;i++)
    			fin.write((char *)&books[i],sizeof books[i]);
			fin.close();
			break;
		}
	}
	
	for(int i=0;i<c;i++)
	{
		if((!strcmp(temp,students[i].bn))&&(!strcmp(temp1,students[i].name
        )))
		{
			for(int j=i;j<c-1;j++)
			{
				students[j]=students[j+1];
			}
			fin1.open("students.data");
			for(int i=0;i<c-1;i++)
    			fin1.write((char *)&students[i],sizeof students[i]);
			fin1.close();
			break;
		}
	}
	cout<<"��Ϣ�Ѹ��£�\n"; 
}
void search_books() //��Ϣ���� 
{
	char a;
	FILE *p; 
	ofstream fin,fin1;
	ifstream fout,fout1;
	char bn[100],pn[100],temp[100];
	int	count=0,count1=0,c=0;
	char choose;
	lib books[1000];
	stu students[1000];
	fout.open("books.data");
	while(!fout.eof())	fout.read((char *)&books[count++],sizeof books[count-1]);
	fout.close();
	fout1.open("students.data");
	while(!fout1.eof())	fout1.read((char *)&students[c++],sizeof students[c-1]);
	fout1.close();
	cout<<"��Ҫ��ѯ���鱾���֣�\n";
	cin>>temp;
	for(int i=0;i<count;i++)
	{
	    if(!strcmp(temp,books[i].name))
	    {
            cout<<"����:"<<books[i].name<<endl;
	        cout<<"����:"<<books[i].author<<endl;
	        cout<<"�۸�:"<<books[i].price<<endl;
	        cout<<"���ʣ��:"<<books[i].number<<endl;
            for(int i=0;i<c;i++) 
	        {
                if(!strcmp(temp,students[i].bn))
		        {
                    ++count1; 
			        if(count1==1)    cout<<"������Ϣ����:\n";
                    cout<<"ѧ������: "<<students[i].name<<" ";
			        cout<<"����ʱ��: "<<students[i].date1<<endl;	
		        }
            }
            if(count1==0)    cout<<"����δ���!"<<endl;                	
	        break; 
        }
	    if(i==count-1)	cout<<"���鲻���ڣ�\n";
	}
}
void manage_books() //ͼ����Ϣ�޸� 
{
	char a;
	FILE *p; 
	ofstream fin,fin1;
	ifstream fout,fout1;
	char bn[100],pn[100],temp[100],temp1[100];
	int	count=0,count1=0,count2=0,c=0;
	char choose;
	lib books[1000];
	stu students[1000];
	fout.open("books.data");
	while(!fout.eof())		fout.read((char *)&books[count++],sizeof books[count-1]);
	fout.close();
	fout1.open("students.data");
	while(!fout1.eof())	fout1.read((char *)&students[c++],sizeof students[c-1]);
	fout1.close();
	cout<<"��Ҫ�޸���Ϣ���鱾��\n";
	cin>>temp;
	for(int i=0;i<count;i++)
	{
		if(!strcmp(temp,books[i].name))
		{
			cout<<"ѡ����Ҫ�޸ĵ���Ϣ��\n"<<"0 ɾ������(ǰ���Ǹ���δ���)\n"<<"1 ����\n"
			<<"2 ����\n"<<"3 ���ʣ��\n"<<"4 ͼ��۸�\n";
			choose=getch();
			if(choose=='0')
			{
                for(int k=0;k<c;k++)
                {
                    if(!strcmp(temp,students[k].bn))
                    {
                        cout<<"ɾ��ʧ��,�����ѽ����\n";
                        count2=1;
                        break;                                
                    }        
                } 
                if(count2==1)    break;                                             
				for(int j=i;j<count-1;j++)	books[j]=books[j+1];
				count--;
			}
			if(choose=='1')
			{
				cout<<"�����޸ĺ��������";
				cin>>books[i].name;
			}
			else if(choose=='2')
			{
				cout<<"�����޸ĺ������������";
				cin>>books[i].author;
			}
			else if(choose=='3')
			{
				cout<<"�����޸ĺ�Ŀ��ʣ�ࣺ";
				cin>>books[i].number;
			}
			else if(choose=='4')
			{
				cout<<"�����޸ĺ���鱾�۸�";
				cin>>books[i].price;
			}
			fin.open("books.data");
			for(int i=0;i<count;i++)
    			fin.write((char *)&books[i],sizeof books[i]);
			fin.close();
			cout<<"��Ϣ�Ѹ���\n";
			break; 
		}
		if(i==count-1)	cout<<"���鲻���ڣ�\n";
	}
}
void search_students()
{
	char a;
	FILE *p; 
	ofstream fin1;
	ifstream fout1;
	char bn[100],pn[100],temp[100],temp1[100];
	int	count=0,count1=0,choose,c=0;
	//lib books[1000];
	stu students[1000];
	fout1.open("students.data");
	while(!fout1.eof())	fout1.read((char *)&students[c++],sizeof students[c-1]);
	fout1.close();
	cout<<"��Ҫ��ѯ��ѧ��ѧ�ţ�\n";
	cin>>temp;
	for(int i=0;i<c;i++)
	{
		if(!strcmp(temp,students[i].xh))
		{
			++count1; 
			if(count1==1)    cout<<"ͬѧ����:"<<students[i].name<<endl;
			cout<<"����:"<<students[i].bn<<endl;
			cout<<"���:"<<students[i].bh<<endl;
			cout<<"����ʱ�䣺"<<students[i].date1<<endl;	
		}
	}
	if(0==count1)	cout<<"��ͬѧδ�����鼮��\n";
}
void log_in2()
{
	int pw,count=0,choose,a;
	FILE *p; 
	ofstream fin;
	ifstream fout;
	fout.open("code1.data");
	fout.read((char *)&a,sizeof a);
	fout.close();
	for(int i=0;i<mid;i++)	cout<<" ";
	cout<<"***ͼ�����ϵͳ***\n";
	for(int i=0;i<mid;i++)	cout<<" ";
	cout<<"�˺ţ�01\n";
	for(int i=0;i<mid;i++)	cout<<" ";
	cout<<"���룺";
	cin>>pw;
	while(pw!=a)
	{
		++count;
		if(count==3)
		{
			for(int i=0;i<mid;i++)	cout<<" ";
			cout<<"ϵͳǿ���˳���";
			exit(0); 
		}
		for(int i=0;i<mid;i++)	cout<<" ";
		cout<<"�������,������"<<3-count<<"�λ���.\n";
		for(int i=0;i<mid;i++)	cout<<" ";
		cout<<"���룺";
		cin>>pw;
	}
}
void log_in1(); 
void initialize_screen2();
void delay()
{
	clock_t delay=1.8*CLOCKS_PER_SEC;
	clock_t start=clock();
	while(clock()-start<delay);	
}
int main(void)
{
	char choose,a;
	initialize_screen2();
	log_in2(); 
	system("cls");
	initialize_screen();
	while(1)
	{
		choose=getch();
		if(choose=='7')
		{
			cout<<"��ӭʹ�ã�" ; 
			return 0;
		}	
		
		if(choose=='6')
		{
			system("cls");
			search_students();
			cout<<"������ѯ��(Y / N):\n";
			do
			{
				a=getch();
				while(a!='Y'&&a!='y'&&a!='N'&&a!='n')	a=getch();	 
				if(a=='y'||a=='Y')
				{
					search_students();
					cout<<"������ѯ��(Y / N):\n";
				}	
				else
				{
					system("cls") ;		
					break;
				}	
			}while(a!='n'||a!='N');
			initialize_screen();
		}
		
		if(choose=='2')
		{
			system("cls");
			return_books();
			cout<<"�������飿(Y / N):\n";
			do
			{
				a=getch();
				while(a!='Y'&&a!='y'&&a!='N'&&a!='n')	a=getch();	 
				if(a=='y'||a=='Y')
				{
					return_books();
					cout<<"�������飿(Y / N):\n";
				}	
				else
				{
					system("cls") ;		
					break;
				}	
			}while(a!='n'||a!='N');
			initialize_screen();
		}
		
		if(choose=='4')
		{
			system("cls");
			search_books();
			cout<<"������ѯ��(Y / N):\n";
			do
			{
				a=getch();
				while(a!='Y'&&a!='y'&&a!='N'&&a!='n')	a=getch();	 
				if(a=='y'||a=='Y')
				{
					search_books();
					cout<<"������ѯ��(Y / N):\n";
				}	
				else
				{
					system("cls") ;		
					break;
				}	
			}while(a!='n'||a!='N');
			initialize_screen();
		}
		
		if(choose=='5')
		{
			system("cls");
			manage_books();
			cout<<"�����޸ģ�(Y / N):\n";
			do
			{
				a=getch();
				while(a!='Y'&&a!='y'&&a!='N'&&a!='n')	a=getch();	 
				if(a=='y'||a=='Y')
				{
					manage_books();
					cout<<"�����޸ģ�(Y / N):\n";
				}	
				else
				{
					system("cls") ;		
					break;
				}	
			}while(a!='n'||a!='N');
			initialize_screen();
		}
		
		if(choose=='3')
		{
			system("cls");
			add_books();
			cout<<"��������һ������в�����(Y/N)\n";
			do
			{
				a=getch();
				while(a!='Y'&&a!='y'&&a!='N'&&a!='n')	a=getch();	 
				if(a=='y'||a=='Y')
				{
					add_books();
					cout<<"��������һ������в�����(Y/N)\n";
				}	
				else
				{
					system("cls") ;		
					break;
				}	
			}while(a!='n'||a!='N');
			initialize_screen();
		}
		
		if(choose=='1')
		{
			system("cls");
			lend_books();
			cout<<"�������飿(Y / N):\n";
			do
			{
				a=getch();
				while(a!='Y'&&a!='y'&&a!='N'&&a!='n')	a=getch();	 
				if(a=='y'||a=='Y')
				{
					lend_books();
					cout<<"�������飿(Y / N):\n";
				}	
				else
				{
					system("cls") ;		
					break;
				}	
			}while(a!='n'||a!='N');
    		
			initialize_screen();
		}
	}
	
	return 0;
}
void log_in1()
{
	int a,t; 
	char choose;
	FILE *p;
	ofstream fin;
	ifstream fout;
	choose=getch();
	if(choose=='1');
	else if(choose=='2')
	{
		system("cls");
		fout.open("code1.data");
		fout.read((char *)&a,sizeof a);
		fout.close();
		cout<<"����ԭ���룺";
		cin>>t;
		if(a==t)	
		{
			cout<<"�����޸ĺ�����룺";
			cin>>t;
			fin.open("code1.data");
			fin.write((char *)&t,sizeof t);
			fin.close(); 
			cout<<"�޸ĳɹ���"; 
			delay();
		}
		else
		{
			cout<<"ԭ�����������";
			delay();
		}	
		system("cls") ;
		initialize_screen2();
	}
	else if(choose=='3')
	{
		system("cls");
		fout.open("code.data");
		fout.read((char *)&a,sizeof a);
		fout.close();
		cout<<"����Ȩ����֤�룺";
		cin>>t;
		if(a==t)
		{
			cout<<"�����µ����룺";
			cin>>t;
			fin.open("code1.data");
			fin.write((char *)&t,sizeof t);
			fin.close(); 
			cout<<"�����޸ĳɹ���"; 
			delay();
		}
		else
		{
			cout<<"Ȩ����֤���������";
			delay();
		}	
		system("cls") ;	
		initialize_screen2();
	}
	system("cls");
}
void initialize_screen2()
{
	for(int i=0;i<mid;i++)	cout<<" ";
	cout<<"***ͼ�����ϵͳ***\n";
	for(int i=0;i<mid;i++)	cout<<" ";
	cout<<"1 ����Ա��½\n";
	for(int i=0;i<mid;i++)	cout<<" ";
	cout<<"2 �����޸�\n";
	for(int i=0;i<mid;i++)	cout<<" ";
	cout<<"3 �����һ�\n";
	for(int i=0;i<mid;i++)	cout<<" ";
	cout<<"(��ʼ����Ա��½����Ϊ:123456)\n";
	log_in1();
}
