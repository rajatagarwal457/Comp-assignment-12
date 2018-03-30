#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<iomanip>
#include<process.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
using namespace std;

class publisher
{
    char PubName[50],Address[50];
    long int Telephone;
public:
    void InpPub();
    void DispPub();
};

class author
{
    char AuName[50];
    long int Telephone;
public:
    void InpAuthor();
    void DispAuthor();
};

class book:public publisher, public author
{
    int code, InStock;
    char Name[50];
    float Price;
    static int y;
public:
    void InpBook();
    book()
    {
        y++;
    }
    ~book()
    {
        y--;
    }
    void DispBook();
};

int book::y=0;

class manage
{
    book obj[10];
public:
    void GetDetails();
    void ShowDetails();
};


void publisher::InpPub()
{
    cout<<"enter publisher name : ";
    cin.ignore();
    cin.getline(PubName, 50);
    cout<<"enter publisher Address : ";

    cin>>Address;
    cout<<"enter publisher Telephone : ";
    cin>>Telephone;
}

void publisher::DispPub()
{
    cout<<"\npublisher name : "<<PubName;
    cout<<"\npublisher Address : "<<Address;
    cout<<"\npublisher Telephone NO. : "<<Telephone;

}

void author::InpAuthor()
{
    cout<<"enter Author Name : ";
    cin.ignore();
    cin.getline(AuName, 50);
    cout<<"enter Author Telephone : ";
    cin>>Telephone;
}

void author::DispAuthor()
{
    cout<<"\n\n\n\nAuthor name : "<<AuName;
    cout<<"\nAuthor Telephone NO. : "<<Telephone;
}

void book::InpBook()
{
    system("cls");
    author::InpAuthor();
    cout<<"enter book Name : ";
    cin.ignore();
    cin.getline(Name, 50);
    cout<<"enter book code : ";
    cin>>code;
    cout<<"enter no. of book in stock : ";
    cin>>InStock;
    cout<<"enter book price : ";
    cin>>Price;
    publisher::InpPub();
}

void book::DispBook()
{
    author::DispAuthor();
    cout<<"\nBook name : "<<Name;
    cout<<"\nBook code : "<<code;
    cout<<"\nBook price : "<<Price;
    cout<<"\nNo. of books in stock : "<<InStock;
    publisher::DispPub();
}
int count=0;
void manage::GetDetails()
{
    cout<<"enter no. of books : ";
    int x;
    cin>>x;
    for(int i=0;i<x;i++)
    {
        obj[count].InpBook();
        count++;
    }
}

void manage::ShowDetails()
{

    for(int i=0;i<count;i++)
    {

            obj[i].DispBook();

    }
}

int main()
{
    int ch;
    manage o;
    while(1)
    {
        system("cls");
        cout<<"\n1.Enter book(s)";
        cout<<"\n2.display book";
        cout<<"\n3.exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1:o.GetDetails();break;
            case 2:o.ShowDetails();cout<<"\n press any key to continue";
            getch();break;
            case 3:exit(0);
        }
    }
}
