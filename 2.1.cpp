#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<iomanip>
#include<process.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
using namespace std;

char grade(float f)
{
    if(f>=90) return 'A';
    else if(f>=70) return 'B';
    else if(f>=50) return 'C';
    else return 'F';

}

class school
{
    char Name[20],Address[50];
    long int Telephone;
public:
    void InpInfo();
    void showInfo();
};

class student : school
{
    int RollNo, Class;
    char Section, Name[10];
public:
    void GetInfo();
    void DispInfo();
};

class primary : public student
{
    float English, Maths, Science;
public:
    void InpMarks();
    void DispReportCard();
};

class middle : public student
{
    float English, Maths, Physics, Chemistry, Biology;
public:
    void InpMarks();
    void DispReportCard();
};

class highschool : public student
{
    float English, Maths, Elective_Marks;
    char Elective_Name[10];
public:
    void InpMarks();
    void DispReportCard();
};


void school::InpInfo()
{
    cout<<"enter school name : ";
    cin.ignore();
    gets(Name);

    cout<<"enter school address : ";
    cin.ignore();
    cin>>Address;
    cout<<"enter school phone number : ";
    cin>>Telephone;
}

void school::showInfo()
{
    cout<<"\t\t\t";
    puts(Name);
    cout<<"\t\tReport Card - 2018-19";
}

void student::GetInfo()
{
    school::InpInfo();
    cout<<"enter student name : ";
    cin.ignore();
    cin.getline(Name, 10);

    cout<<"enter student Roll no : ";
    cin>>RollNo;
    cout<<"enter student Class : ";
    cin>>Class;
    cout<<"enter student Section : ";
    cin>>Section;

}

void student::DispInfo()
{
    school::showInfo();
    cout<<"\n"<<"Student Name : "<<Name<<"\tClass : "<<Class<<"\tSection : "<<Section;
}

void primary::InpMarks()
{
    student::GetInfo();
    cout<<"enter English marks : ";
    cin>>English;
    cout<<"enter Maths marks : ";
    cin>>Maths;
    cout<<"enter Science marks : ";
    cin>>Science;

}

void primary::DispReportCard()
{
    student::DispInfo();
    cout<<endl;
    cout.ios::fixed;
    cout<<setw(10)<<"Subject"<<setw(10)<<"Marks"<<setw(10)<<"Grade";
    cout<<"\n"<<setw(10)<<"English"<<setw(10)<<English<<setw(10)<<grade(English);
    cout<<"\n"<<setw(10)<<"Maths"<<setw(10)<<Maths<<setw(10)<<grade(Maths);
    cout<<"\n"<<setw(10)<<"Science"<<setw(10)<<Science<<setw(10)<<grade(Science);
}


void middle::InpMarks()
{
    student::GetInfo();

    cout<<"enter English marks : ";
    cin>>English;
    cout<<"enter Maths marks : ";
    cin>>Maths;
    cout<<"enter Physics marks : ";
    cin>>Physics;
    cout<<"enter Chemistry marks : ";
    cin>>Chemistry;
    cout<<"enter Biology marks : ";
    cin>>Biology;

}

void middle::DispReportCard()
{
    student::DispInfo();
    cout<<endl;
    cout.ios::fixed;
    cout<<setw(10)<<"Subject"<<setw(10)<<"Marks"<<setw(10)<<"Grade";
    cout<<"\n"<<setw(10)<<"English"<<setw(10)<<English<<setw(10)<<grade(English);
    cout<<"\n"<<setw(10)<<"Maths"<<setw(10)<<Maths<<setw(10)<<grade(Maths);
    cout<<"\n"<<setw(10)<<"Physics"<<setw(10)<<Physics<<setw(10)<<grade(Physics);
    cout<<"\n"<<setw(10)<<"Chemistry"<<setw(10)<<Chemistry<<setw(10)<<grade(Chemistry);
    cout<<"\n"<<setw(10)<<"Biology"<<setw(10)<<Biology<<setw(10)<<grade(Biology);
}



void highschool::InpMarks()
{
    student::GetInfo();
    cout<<"enter English marks : ";
    cin>>English;
    cout<<"enter Maths marks : ";
    cin>>Maths;
    cout<<"enter Elective Name : ";
    cin>>Elective_Name;
    cout<<"enter ELective marks : ";
    cin>>Elective_Marks;

}

void highschool::DispReportCard()
{
    student::DispInfo();
    cout<<endl;
    cout.ios::fixed;
    cout<<setw(10)<<"Subject"<<setw(10)<<"Marks"<<setw(10)<<"Grade";
    cout<<"\n"<<setw(10)<<"English"<<setw(10)<<English<<setw(10)<<grade(English);
    cout<<"\n"<<setw(10)<<"Maths"<<setw(10)<<Maths<<setw(10)<<grade(Maths);
    cout<<"\n"<<setw(10)<<Elective_Name<<setw(10)<<Elective_Marks<<setw(10)<<grade(Elective_Marks);
}

int main()
{
    cout<<"enter Category, Primary(p), MIddle(m), HIgh school(h) : ";
    char x;
    cin>>x;
    highschool objh;
    primary objp;
    middle objm;
    switch(x)
    {
        case 'p':
                  objp.InpMarks();
                  objp.DispReportCard();
                  break;
        case 'm':
                  objm.InpMarks();
                  objm.DispReportCard();
                  break;
        case 'h':
                  objh.InpMarks();
                  objh.DispReportCard();
                  break;
    }
}
