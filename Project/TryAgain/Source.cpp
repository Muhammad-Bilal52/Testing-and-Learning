#include <ctime>
#include <Windows.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
const int assigop = 0;
class carparking
{
	string vecmodel;
	long int vecno;
	char vecreg;
	int vecrent;
	char vectype;
	SYSTEMTIME enter;
	SYSTEMTIME exit;
	SYSTEMTIME spent;
public:
	carparking()
	{
		vecrent = 0;
		int(exit) = assigop;

		int(spent) = assigop;
	}
	void input(carparking a[],int i)
	{
		/*cout<<"Enter Vehicle Type (C/B)"<<endl;
		cin>>vectype;
		if (vectype == 'C' && vectype == 'B')
		{*/
			do
	{
		cout<<"Enter Vehicle Type (C/B)"<<endl;
		cin>>vectype;
	} while (vectype != 'C' && vectype != 'B');

	
		/*
		if (vectype != 'C' || vectype != 'B')
		{
			cout<<"ReEnter Vec Type Either 'C' or 'B'"<<endl;
			cin>>vectype;
		}*/
		cout<<"Enter Vehicle Number"<<endl;
		cin>>vecno;
		for (int z = 0; z < i; z++)
		{
			if (vecno == a[z].vecno)
			{
				do
				{
					cout<<"Enter Vehicle Number Again"<<endl;
					cin>>vecno;
				} while (vecno == a[z].vecno);
			}
		}
		
		cout<<"Enter Vehicle Model"<<endl;
		cin>>vecmodel;
		do
			{
		cout<<"Enter Vehicle Registration (Y/N)"<<endl;
		cin>>vecreg;
			} while (vecreg != 'Y' && vecreg != 'N');

		if (vectype == 'C')
		{
			vecrent = 10;
		}
		else if(vectype == 'B')
		{
			vecrent = 5;
		}
		/*time_t t = time(0);*/
		GetLocalTime(&enter);
	}
	void display()
	{
		cout<<"Vehicle Type :\t";
		if (vectype == 'C')
		{
			cout<<"Car"<<endl;
		}
		else 
		{
			cout<<"Bike"<<endl;
		}
		cout<<"Vehicle Model Name : \t"<<vecmodel<<endl;
		cout<<"Vehicle Plate No : \t"<<vecno<<endl;
		/*cout<<"Vehicle Registration Status : \t";
		if (vecreg == 'Y')
		{
			cout<<"Yes"<<endl;
		}
		else
			cout<<"No"<<endl;*/
		if (vecreg == 'N')
			{
				vecrent = 0;
			}
		else
			{
			cout<<"Vehicle Rent : \t"<<vecrent<<endl;
			}
		/*cout<<"Enter Time :\t";
		cout << (enter->tm_year + 1900) << '-' 
         << (enter->tm_mon + 1) << '-'
         <<  enter->tm_mday
         << "\n"<<endl;*/
		cout<<"Day : "<<enter.wDay<<" Month : "<<enter.wMonth<<" Year : "<<enter.wYear<<endl;
		cout<<"Enter Time :\t";
		cout<<"Hours : "<<enter.wHour<<"  Minute :  "<<enter.wMinute<<"  Seconds :  "<<enter.wSecond<<endl;
		/*cout<<"Exit Time :\t";
		cout<<"Hours : "<<exit.wHour<<"  Minutes :  "<<exit.wMinute<<"  Seconds :  "<<exit.wSecond<<endl;
		*//*cout<<"Enter Time :\t"<<enter->tm_hour<< '-'<<enter->tm_min<< '-'<<enter->tm_sec<<endl;*/
		cout<<"Exit Time :\t";
		if (int(exit.wHour) == int(52428))
		{
			cout<<"Car is Still in Parking"<<endl;
		}
		else
		{
			cout<<"Hours : "<<exit.wHour<<"  Minutes :  "<<exit.wMinute<<"  Seconds :  "<<exit.wSecond<<endl;
		}

		if (vecreg == 'Y')
					{
						cout<<"Vehicle Registration Status : \t";
						cout<<"Yes"<<endl;
					}
					else
					{
						cout<<"Vehicle Registration Status : \t";
						cout<<"No"<<endl;
					}
		
		cout<<"Spent Time :\t";
		if (int(exit.wHour) == 52428)
		{
				cout<<"Car is Still in Parking"<<endl;
		}
		else
		{
				spent.wHour = exit.wHour-enter.wHour;
				spent.wMinute = exit.wMinute-enter.wMinute;
				spent.wSecond = exit.wSecond-enter.wSecond;
			if (exit.wSecond-enter.wSecond<0)
			{
				SYSTEMTIME so;
				so.wMinute = (exit.wMinute-enter.wMinute) - 1;
				so.wSecond = (exit.wSecond-enter.wSecond) + 60;
				cout<<"Hours : "<<spent.wHour<<" Minute : "<<so.wMinute<<" Seconds : "<<so.wSecond<<endl;
			}
			else
			{
			cout<<"Hours : "<<spent.wHour<<" Minute : "<<spent.wMinute<<" Seconds : "<<spent.wSecond<<endl;
			}
		}
		if (vecreg == 'N')
		{
			if ((exit.wHour) == 52428)
			{
				vecrent = 10;
				cout<<"Vehicle Rent : \t"<<vecrent<<endl;
				
			}
			else if((exit.wHour - enter.wHour) == 0)
			{
					vecrent = 10;
					cout<<"Vehicle Rent : \t"<<vecrent<<endl;
			}
			else
			{
					vecrent = 10*(exit.wHour-enter.wHour);
				    cout<<"Vehicle Rent : \t"<<vecrent<<endl;
			
			}
		
		}
	}
	void checkout()
	{
		GetLocalTime(&exit);
	
	}
	int vecre()
	{
		return vecno;
	}
	int rent()
	{
		carparking a;
		a.vecrent;
		return vecrent;
	}
};
void menu()
{
	cout<<"\t\tPress 1 to Enter Vehicle"<<endl;
	cout<<"\t\tPress 2 to View Vehicle"<<endl;
	cout<<"\t\tPress 3 to Checkout Vehicle"<<endl;
	cout<<"\t\tPress 4 to Check Income Amount"<<endl;
	cout<<"\t\tPress 5 to Exit"<<endl;
	
}
void main()
{
	carparking vec[10];
	int income=0;
	int checking = 0;
	int choice=0,i=0,k=0;
	int searchno;
	fstream vecstore;
	do
	{
		menu();
		cin>>choice;
		if (choice == 1)
		{
			if (i<10)
				{
				vec[i].input(vec,i);
				i++;
				}
			else
				cout<<"Space is Full"<<endl;
		}
		else if (choice == 2)
		{
			if (i>0)
			{
				for (k = 0; k < i; k++)
				{
					vec[k].display();
				}
			}
			else
				cout<<"Enter Some Data First"<<endl;
		}
		else if (choice == 3)
		{
			if (i>0)
			{
			cout<<"Enter VecNo You want to Checkout"<<endl;
			cin>>searchno;
			if (searchno == checking)
			{
				cout<<"\t\t\t\t\t\t\tCar is Already Checked Out"<<endl;
			}
			else{
			for (int k = 0; k < i; k++)
			{
				if (searchno == vec[k].vecre())
					{
						vec[k].checkout();
						checking = searchno;	
					}
			}
			}}
			else
			{
				cout<<"Enter Some Data First"<<endl;
				}
		}
		else if (choice == 4)
		{
			for (int z = 0; z < i; z++)
			{
				int variable = vec[z].rent();
				income = variable + income;
				
			}
			cout<<"Income :\t"<<income<<endl;
			
		}		
	
	}while (choice != 5);
	system("pause");
}