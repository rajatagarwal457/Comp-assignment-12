#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<iomanip>
#include<process.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
using namespace std;

class courses
{
	int CourseId,NoofSeats;
	long int fee;
	static int y;
	char CourseName[50], Category[50], department[5];
public:
	courses()
	{
		y++;
	}
	~courses()
	{
		y--;
	}
	void inp();
	void sort();
	void display_ca();
	void insert();
	void delete_c();
	void display_c();
	void display_all();


};
int courses::y=0;
courses obj[10];

void courses::inp()
{
	system("cls");
	cout<<"enter course id : ";
	cin>>CourseId;
	cout<<"enter no. of seats : ";
	cin>>NoofSeats;
	cout<<"enter Fee : ";
	cin>>fee;
	cout<<"enter course name : ";
	cin>>CourseName;
	cout<<"enter category : ";
	cin>>Category;
	cout<<"enter dept. : ";
	cin>>department;
}

void courses::sort()
{
	int min;
	courses temp;
	for(int i=0;i<y;i++)
	{

		min=i;
		for(int j=i+1;j<y;j++)
		{
			if(strcmpi(obj[min].CourseName, obj[j].CourseName)<0)
			{
				min=j;
			}
		}
		temp=obj[i];
		obj[i]=obj[min];
		obj[min]=temp;
	}
}

void courses::delete_c()
{
	system("cls");
	cout<<"enter course to be deleted : ";
	char name[50];
	cin>>name;
	for(int i=0;i<y;i++)
	{
		if(strcmpi(name, obj[i].CourseName)==0)
		{
			for(int j=i;j<y;j++)
			{
				obj[j]=obj[j+1];
				y--;
			}
		}
	}
}

void courses::display_c()
{
	system("cls");
	cout<<"enter course name : ";
	char sn[50];
	cin>>sn;
	cout.ios::fixed;
	cout<<setw(15)<<"course name"<<setw(10)<<"course id"<<setw(15)<<"category"<<setw(5)<<"fee"<<setw(15)<<"department"<<setw(10)<<"seats";
	for(int i=0;i<y;i++)
	{
		if(strcmpi(sn, obj[i].CourseName)==0)
		{
			if(obj[i].fee!=0)
			{
				cout<<endl;
				cout.ios::fixed;
				cout<<setw(15)<<obj[i].CourseName<<setw(10)<<obj[i].CourseId<<setw(15)<<obj[i].Category<<setw(5)<<obj[i].fee<<setw(15)<<obj[i].department<<setw(10)<<obj[i].NoofSeats;

			}
		}
	}
}

void courses::display_ca()
{
	system("cls");
	cout<<"enter category name : ";
	char sc[50];
	cin>>sc;
	cout.ios::fixed;
	cout<<setw(15)<<"course name"<<setw(10)<<"course id"<<setw(15)<<"category"<<setw(5)<<"fee"<<setw(15)<<"department"<<setw(10)<<"seats";
	for(int i=0;i<y;i++)
	{
		if(strcmpi(sc, obj[i].Category)==0)
		{
			if(obj[i].fee!=0)
			{
				cout<<endl;
				cout.ios::fixed;
				cout<<setw(15)<<obj[i].CourseName<<setw(10)<<obj[i].CourseId<<setw(15)<<obj[i].Category<<setw(5)<<obj[i].fee<<setw(15)<<obj[i].department<<setw(10)<<obj[i].NoofSeats;

			}
		}
	}
}

void courses::display_all()
{
	system("cls");
	cout.ios::fixed;
	cout<<setw(15)<<"course name"<<setw(10)<<"course id"<<setw(15)<<"category"<<setw(5)<<"fee"<<setw(15)<<"department"<<setw(10)<<"seats";
	for(int i=0;i<y;i++)
	{
		if(obj[i].fee!=0)
		{
			cout<<endl;
			cout.ios::fixed;
			cout<<setw(15)<<obj[i].CourseName<<setw(10)<<obj[i].CourseId<<setw(15)<<obj[i].Category<<setw(5)<<obj[i].fee<<setw(15)<<obj[i].department<<setw(10)<<obj[i].NoofSeats;

		}
	}
}


void courses::insert()
{
	system("cls");
	cout<<"enter position at which course is to be inserted : ";
	int x;
	cin>>x;
	system("cls");
	courses temp;
	for(int i=y-1;i>x;i--)
	{
		obj[i]=obj[i-1];
	}
	temp.inp();
	obj[x]=temp;
}

int main()
{
	int ch;
	cout<<"enter no. of courses : ";
	int no;
	cin>>no;
	for(int u=0;u<no;u++)
	{
		obj[u].inp();
	}
	while (1)
	{
		system("cls");
		cout<<"\n1. sort";
		cout<<"\n2. display by category";
		cout<<"\n3. insert a new course";
		cout<<"\n4. delete a course";
		cout<<"\n5. display by name";
		cout<<"\n6. display all";
		cout<<"\n7. exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:obj[0].sort();cout<<"\npress any key to continue";getch();break;
			case 2:obj[0].display_ca();cout<<"\npress any key to continue";getch();break;
			case 3:obj[0].insert();cout<<"\npress any key to continue";getch();break;
			case 4:obj[0].delete_c();cout<<"\npress any key to continue";getch();break;
			case 5:obj[0].display_c();cout<<"\npress any key to continue";getch();break;
			case 6:obj[0].display_all();cout<<"\npress any key to continue";getch();break;
			case 7:exit(0);
		}
	}

}
