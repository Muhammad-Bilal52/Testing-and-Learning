#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class employee
{
	int  eid;
	char name[10];
	char desg[15];		//Increase Salary of each designation
	int  salary;
	char gender[7];		//Kickout All Females
	void getid()
	{
		fstream id;
		id.open("id.txt",ios::in | ios::binary);
		int aid=0;
		id>>aid; // id.read((char *)&aid,sizeof(aid));
		id.close();
		aid++;
		eid = aid;
		id.open("id.txt",ios::out | ios::binary);
		id<<aid; //id.write((char *)&aid,sizeof(aid));
		id.close();
	}
public:
	void input()
	{
		getid();
		cout<<"Your ID is:   "<<eid<<endl;
		cout<<"Enter Your Name:   ";
		cin>>name;
		cout<<"Enter Your Designation:   ";
		cin>>desg;
		do
		{
			cout<<"Enter Your Gender (Male or Female):   ";
			cin>>gender;
		} while (strcmp(gender, "Male") && strcmp(gender, "Female"));
		cout<<"Enter Your Salary:   ";
		cin>>salary;
	}
	void display()
	{
		cout<<"ID :\t"<<eid<<endl;
		cout<<"Name :\t"<<name<<endl;
		cout<<"Gender :\t"<<gender<<endl;
		cout<<"Designation :\t"<<desg<<endl;
		cout<<"Salary :\t"<<salary<<endl;
	}
	bool comparison (string a)
	{
		
		if (a == string(desg))
		{
			return true;
		}
		else 
			return false;
	}
	bool comparison2 (string a)
	{
		
		if (a == string(name))
		{
			return true;
		}
		else 
			return false;
	}
	void update_salary(int sal)
	{
		salary = salary + sal;
	}
	int returnid()
	{
		return eid;
	}
	bool removefemale()
	{
		if (string(gender) == "Female")
		{
			return true;
		}
		else
			return false;
	}
	void kickedoutemployee()
	{
		cout<<"\t\t\tEmployee "<< name <<" is kicked Out from the Job"<<endl;
	}
};
void menu()
{
	cout<<"\t\tPress 1 to Enter Employee information"<<endl;			
	cout<<"\t\tPress 2 to View Employee information"<<endl;				
	cout<<"\t\tPress 3 to Change Employee Salary by Desg"<<endl;
	cout<<"\t\tPress 4 to Change Salary of Single Employee"<<endl;		 
	cout<<"\t\tPress 5 to Remove All Femlae Employee"<<endl;			
	cout<<"\t\tPress 6 to Remove Single Employee By Id"<<endl;				
	cout<<"\t\tPress 7 to Remove Employee By Name"<<endl;
	cout<<"\t\tPress 8 to Exit Programm"<<endl;							
}
void main()
{
	
	employee emp;
	fstream data;
	char remove_emp[10];
	char salary_change_desg[10];
	int salary_change_amount;
	int opt=0,i=0;
	do
	{
		menu();
		cin>>opt;
		if (opt == 1)
		{
			emp.input();
			data.open("emp.txt", ios::app | ios::out | ios::binary );
			data.write((char *)&emp,sizeof(emp));
			data.close();
		}
		else if (opt == 2)
		{
			data.open("emp.txt", ios::in | ios::binary);
			while (data.read((char *)&emp,sizeof(emp)))
			{
				emp.display();
				
			}
			data.close();
		}
		else if (opt == 3)
		{
			cout<<"\t Enter Designation You want to change Salary of:\t"<<endl;
			cin>>salary_change_desg;
			cout<<"Enter Amount You Want to Add"<<endl;
			cin>>salary_change_amount;
			fstream temp;
			int c=0;
			temp.open("temp.txt", ios::app | ios::out | ios::binary );
			data.open("emp.txt", ios::in | ios::binary );
			while (data.read((char *)&emp,sizeof(emp)))
			{
				if (emp.comparison(string(salary_change_desg)) == true)
				{
					c=1;
					emp.update_salary(salary_change_amount);

				}
				temp.write((char *)&emp,sizeof(emp));
			}
			if (c == 0)
			{
				cout<<"Not Found"<<endl;
			}
			data.close();
			temp.close();
			remove("emp.txt");
			rename("temp.txt","emp.txt");
		}
		else if (opt == 4)
		{
			int checkid;
			cout<<"\t\t\tEnter ID of Employee You want to Change Pay of :"<<endl;
			cin>>checkid;
			cout<<"\t\t\tEnter Amount You Want to Add"<<endl;
			cin>>salary_change_amount;
			fstream fobj;
			fobj.open("temp.txt", ios::app | ios::out | ios::binary);
			data.open("emp.txt", ios:: in | ios::binary);
			int c=0;
			while (data.read((char *)&emp,sizeof(emp)))
			{
				if (checkid == emp.returnid())
				{
					c = 1;
					emp.update_salary(salary_change_amount);
				}
				fobj.write((char *)&emp,sizeof(emp));
			}
			if (c = 0)
			{
				cout<<"\t\t\t\tNot Found"<<endl;
			}
			data.close();
			fobj.close();
			remove("emp.txt");
			rename("temp.txt","emp.txt");
		}
		else if (opt == 5)
		{
			cout<<"\t\t\tAll Femlae Employee are Removed"<<endl;
			fstream temp;
			int c=0;
			temp.open("temp.txt", ios::app | ios::out | ios::binary);
			data.open("emp.txt", ios::in | ios::binary);
			while (data.read((char *)&emp,sizeof(emp)))
			{
				if (emp.removefemale() == true)
				{
					emp.kickedoutemployee();
					c = 1 ;
				}
				else 
					temp.write((char *)&emp,sizeof(emp));
			}
			if (c == 0)
			{
				cout<<"\t\t\t\tNo Women Found"<<endl;
			}
			data.close();
			temp.close();
			remove("emp.txt");
			rename("temp.txt","emp.txt");
		}
		else if (opt == 6)
		{
			cout<<"\t\tEnter Id you want to Kick out:\t";
			int checkid;
			cin>>checkid;
			fstream fobj;
			fobj.open("temp.txt", ios::app | ios::out | ios::binary);
			data.open("emp.txt", ios:: in | ios::binary);
			int c=0;
			while (data.read((char *)&emp,sizeof(emp)))
			{
				if (checkid == emp.returnid())
				{
					c = 1;
				}
				else
				fobj.write((char *)&emp,sizeof(emp));
			}
			if (c = 0)
			{
				cout<<"\t\t\t\tNot Found"<<endl;
			}
			data.close();
			fobj.close();
			remove("emp.txt");
			rename("temp.txt","emp.txt");
		}
		else if (opt == 7)
		{
			cout<<"\t\tEnter Name of Employee you want to remove:\t";
			cin>>remove_emp;
			fstream fobj;
			fobj.open("temp.txt", ios::app | ios::out | ios::binary);
			data.open("emp.txt", ios:: in | ios::binary);
			int c=0;
			while (data.read((char *)&emp,sizeof(emp)))
			{
				if (emp.comparison2(string(remove_emp)) == true)
				{
					 c =1;
				}
				else 
					fobj.write((char *)&emp,sizeof(emp));
			}
			if (c = 0)
			{
				cout<<"\t\t\t\tNot Found"<<endl;
			}
			data.close();
			fobj.close();
			remove("emp.txt");
			rename("temp.txt","emp.txt");

		}
	} while (opt != 8);
	system("pause");

}