#include<iostream>
#include<math.h>
#include<stdlib.h>
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
		void inp();
		void sort();
		void display_ca();
		void insert();
		void delete_c();
		void display_co();
		void display_all();
		
};
int courses::y=0;
courses obj[10];

void courses::inp()
{
	cout<<"enter course id : ";
	cin>>CourseId;
	cout<<"enter no. of seats : ";
	cin>>Noofseats;
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
	char temp[50];
	for(int i=0;i<y:i++)
	{
		
		min=i;
		for(int j=i+1;j<y;j++)
		{
			if(strcmpi(obj[min].CourseName, obj[j].CourseName)<0)
			{
				min=j;
			}
		}
		temp=obj[i].CourseName;
		obj[i].CourseName=obj[min].CourseName;
		obj[min].CourseName=temp;
	}
}


