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
	char name[100];//书名  
	char author[100]; //作者
    double price;//价格 
	int number;//库存数 
};
struct stu
{
	char name[100];//姓名
	char xh[100];//学号
	int	 date1;//借书日期 
	char bn[100];//书名 
	char bh[100];//书本编号 
};
void initialize_screen()
{
	int pw,count=0;
	for(int i=0;i<mid;i++)	cout<<" ";
	cout<<"***图书管理系统***\n";
	for(int i=0;i<=6;i++)
	{
		for(int j=0;j<mid;j++)	cout<<" ";
		if(i==0)	cout<<"1 借阅图书\n"; 
		if(i==1)	cout<<"2 归还图书\n"; 
		if(i==2)	cout<<"3 新添图书\n"; 
		if(i==3)	cout<<"4 图书信息查询\n";
		if(i==4)	cout<<"5 图书信息修改\n";
		if(i==5)	cout<<"6 学生借阅信息查询\n";
		if(i==6)	cout<<"7 退出\n"; 
	}
}
void add_books()  //书籍入库 
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
	cout<<"书名：";
	cin>>books[count].name; 
	cout<<"作者：";
	cin>>books[count].author;
    cout<<"价格：";
	cin>>books[count].price;  
	cout<<"入库数目：";
	cin>>books[count].number; 
	fin.open("books.data");
	for(int i=0;i<=count;i++)
    	fin.write((char *)&books[i],sizeof books[i]);
    fin.close(); 
    cout<<"信息已更新\n";
}
void lend_books() //借阅书籍 
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
	cout<<"图书名字：";
	cin>>bn;
	for(int i=0;i<count;i++)
	{
		if(!strcmp(bn,books[i].name))
		{
			++count1;
			if(books[i].number==0)
			{
				cout<<"本书已借完！\n";
				break; 
			}
			else
			{
				cout<<"借书人学号："; 
				cin>>students[c].xh;
				cout<<"借书人姓名："; 
				cin>>students[c].name;
				cout<<"书本编号："; 
				cin>>students[c].bh;
				cout<<"借书日期：";
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
				cout<<"信息已更新！\n"; 
				break;		
			}	
		}
	}
	if(count1==0)	cout<<"没有这本书！\n";	
}
void return_books() //归还图书 
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
	cout<<"归还的书名："; 
	cin>>temp;
	cout<<"学生姓名："; 
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
	cout<<"信息已更新！\n"; 
}
void search_books() //信息搜索 
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
	cout<<"需要查询的书本名字：\n";
	cin>>temp;
	for(int i=0;i<count;i++)
	{
	    if(!strcmp(temp,books[i].name))
	    {
            cout<<"书名:"<<books[i].name<<endl;
	        cout<<"作者:"<<books[i].author<<endl;
	        cout<<"价格:"<<books[i].price<<endl;
	        cout<<"库存剩余:"<<books[i].number<<endl;
            for(int i=0;i<c;i++) 
	        {
                if(!strcmp(temp,students[i].bn))
		        {
                    ++count1; 
			        if(count1==1)    cout<<"借阅信息如下:\n";
                    cout<<"学生姓名: "<<students[i].name<<" ";
			        cout<<"借书时间: "<<students[i].date1<<endl;	
		        }
            }
            if(count1==0)    cout<<"该书未借出!"<<endl;                	
	        break; 
        }
	    if(i==count-1)	cout<<"此书不存在！\n";
	}
}
void manage_books() //图书信息修改 
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
	cout<<"需要修改信息的书本：\n";
	cin>>temp;
	for(int i=0;i<count;i++)
	{
		if(!strcmp(temp,books[i].name))
		{
			cout<<"选择需要修改的信息：\n"<<"0 删除该书(前提是该书未借出)\n"<<"1 书名\n"
			<<"2 作者\n"<<"3 库存剩余\n"<<"4 图书价格\n";
			choose=getch();
			if(choose=='0')
			{
                for(int k=0;k<c;k++)
                {
                    if(!strcmp(temp,students[k].bn))
                    {
                        cout<<"删除失败,该书已借出！\n";
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
				cout<<"输入修改后的书名：";
				cin>>books[i].name;
			}
			else if(choose=='2')
			{
				cout<<"输入修改后的作者姓名：";
				cin>>books[i].author;
			}
			else if(choose=='3')
			{
				cout<<"输入修改后的库存剩余：";
				cin>>books[i].number;
			}
			else if(choose=='4')
			{
				cout<<"输入修改后的书本价格：";
				cin>>books[i].price;
			}
			fin.open("books.data");
			for(int i=0;i<count;i++)
    			fin.write((char *)&books[i],sizeof books[i]);
			fin.close();
			cout<<"信息已更新\n";
			break; 
		}
		if(i==count-1)	cout<<"此书不存在！\n";
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
	cout<<"需要查询的学生学号：\n";
	cin>>temp;
	for(int i=0;i<c;i++)
	{
		if(!strcmp(temp,students[i].xh))
		{
			++count1; 
			if(count1==1)    cout<<"同学姓名:"<<students[i].name<<endl;
			cout<<"书名:"<<students[i].bn<<endl;
			cout<<"编号:"<<students[i].bh<<endl;
			cout<<"借书时间："<<students[i].date1<<endl;	
		}
	}
	if(0==count1)	cout<<"该同学未借阅书籍！\n";
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
	cout<<"***图书管理系统***\n";
	for(int i=0;i<mid;i++)	cout<<" ";
	cout<<"账号：01\n";
	for(int i=0;i<mid;i++)	cout<<" ";
	cout<<"密码：";
	cin>>pw;
	while(pw!=a)
	{
		++count;
		if(count==3)
		{
			for(int i=0;i<mid;i++)	cout<<" ";
			cout<<"系统强制退出！";
			exit(0); 
		}
		for(int i=0;i<mid;i++)	cout<<" ";
		cout<<"密码错误,您还有"<<3-count<<"次机会.\n";
		for(int i=0;i<mid;i++)	cout<<" ";
		cout<<"密码：";
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
			cout<<"欢迎使用！" ; 
			return 0;
		}	
		
		if(choose=='6')
		{
			system("cls");
			search_students();
			cout<<"继续查询？(Y / N):\n";
			do
			{
				a=getch();
				while(a!='Y'&&a!='y'&&a!='N'&&a!='n')	a=getch();	 
				if(a=='y'||a=='Y')
				{
					search_students();
					cout<<"继续查询？(Y / N):\n";
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
			cout<<"继续还书？(Y / N):\n";
			do
			{
				a=getch();
				while(a!='Y'&&a!='y'&&a!='N'&&a!='n')	a=getch();	 
				if(a=='y'||a=='Y')
				{
					return_books();
					cout<<"继续还书？(Y / N):\n";
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
			cout<<"继续查询？(Y / N):\n";
			do
			{
				a=getch();
				while(a!='Y'&&a!='y'&&a!='N'&&a!='n')	a=getch();	 
				if(a=='y'||a=='Y')
				{
					search_books();
					cout<<"继续查询？(Y / N):\n";
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
			cout<<"继续修改？(Y / N):\n";
			do
			{
				a=getch();
				while(a!='Y'&&a!='y'&&a!='N'&&a!='n')	a=getch();	 
				if(a=='y'||a=='Y')
				{
					manage_books();
					cout<<"继续修改？(Y / N):\n";
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
			cout<<"继续对下一本书进行操作？(Y/N)\n";
			do
			{
				a=getch();
				while(a!='Y'&&a!='y'&&a!='N'&&a!='n')	a=getch();	 
				if(a=='y'||a=='Y')
				{
					add_books();
					cout<<"继续对下一本书进行操作？(Y/N)\n";
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
			cout<<"继续借书？(Y / N):\n";
			do
			{
				a=getch();
				while(a!='Y'&&a!='y'&&a!='N'&&a!='n')	a=getch();	 
				if(a=='y'||a=='Y')
				{
					lend_books();
					cout<<"继续借书？(Y / N):\n";
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
		cout<<"输入原密码：";
		cin>>t;
		if(a==t)	
		{
			cout<<"输入修改后的密码：";
			cin>>t;
			fin.open("code1.data");
			fin.write((char *)&t,sizeof t);
			fin.close(); 
			cout<<"修改成功！"; 
			delay();
		}
		else
		{
			cout<<"原密码输入错误！";
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
		cout<<"输入权限验证码：";
		cin>>t;
		if(a==t)
		{
			cout<<"输入新的密码：";
			cin>>t;
			fin.open("code1.data");
			fin.write((char *)&t,sizeof t);
			fin.close(); 
			cout<<"密码修改成功！"; 
			delay();
		}
		else
		{
			cout<<"权限验证码输入错误！";
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
	cout<<"***图书管理系统***\n";
	for(int i=0;i<mid;i++)	cout<<" ";
	cout<<"1 管理员登陆\n";
	for(int i=0;i<mid;i++)	cout<<" ";
	cout<<"2 密码修改\n";
	for(int i=0;i<mid;i++)	cout<<" ";
	cout<<"3 密码找回\n";
	for(int i=0;i<mid;i++)	cout<<" ";
	cout<<"(初始管理员登陆密码为:123456)\n";
	log_in1();
}
