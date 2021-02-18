#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<dos.h>
#include<string.h>

class employee
{
	int empno;
	float hra,gross,tax,salary,da,net;
	char name[50],desi[20];
	public:
	void input()
	{
		cout<<"\n Enter Information of Employee";
		cout<<"\n\n Enter Employee Number ";
		cin>>empno;
		cout<<"\n Enter Employee Name ";
		gets(name);
		cout<<"\n Designation (officer\ manager\ clerk)";                                                        
		cin>>desi;
cout<<"\n Enter Employee Basic Salary ";
		cin>>salary;

		calculate();
	}
	void calculate()
	{
		if(strcmpi(desi,"officer")==0)
		{
			 da= salary*0.8;
			 hra=salary*0.7;
			 tax=salary*0.6;
			 gross=salary+hra+da;
			 net=gross-tax;
		}
		else if(strcmpi(desi,"manager")==0)
		{
			 da= salary*0.7;
			 hra=salary*0.6;
			 tax=salary*0.5;
			 gross=salary+hra+da;
			 net=gross-tax;
		}
		else if(strcmpi(desi,"clerk")==0)
		{
			 da= salary*0.6;
			 hra=salary*0.5;
			 tax=salary*0.4;
			 gross=salary+hra+da;          
			 net=gross-tax;
		}
	}
	void set_increment(int pr)
	{
		salary+=(salary*pr/100.0);
	}
	void display()
	{
		cout<<"\n"<<empno<<"\t"<<name<<"\t"<<salary<<"\t"<<desi;
	}

void display1 ( )
	{
		cout<<"\n"<<empno<<"   "<<name<<"  "<<salary<<"\t"<<desi<<"\t "<<da<<"\t "<<hra<<"\t"<<tax<<"\t"<<gross<<"\t"<<net;
	}
	void display2()
	{
	cout<<"\n ===============================================================================    ";
	cout<<"\n  NAME : "<<name;                       cout<<"\t\t\t\t  EMPLOYEE NO: "<<empno;
	cout<<"\n  DESIGNATION      : "<<desi;           cout<<"\t\t  GROSS SALARY  : "<<gross;
                                                                                         
	cout<<"\n  BASIC SALARY     : "<<salary;         cout<<"\t\t  TAX           :+ "<<tax;
	cout<<"\n  DA               :+ "<<da;            cout<<"\t\t                _____________";
	cout<<"\n  HRA              :+ "<<hra;           cout<<"\t\t  NET SALARY    :="<<net;
	cout<<"\n                   _______________ ";   cout<<"\t                _____________ ";
	cout<<"\n  GROSS SALARY      = "<<gross;
	cout<<"\n                   _______________ ";
	cout<<"\n ===============================================================================    ";
	}
	int get_empno()
	{
		return empno;
	}
};
void main()
{
	clrscr();
	char ch;
	int choice,choice1,flag,eno,loc,n;
	float t;
	fstream file,file1;
	employee ob;
	do                                                      
	{
		clrscr();
		gotoxy(35,12);
		cout<<"WELCOME";
		delay(900);
		clrscr();
		cout<<"\n *********************************************************** ";
		cout<<"\n *                         MENU                            * ";
		cout<<"\n *********************************************************** ";
		cout<<"\n * 1 for Adding all records                                * ";
		cout<<"\n * 2 for displaying all records                            * ";
		cout<<"\n * 3 for displaying particular record                      * ";
		cout<<"\n * 4 for fresh records                                     * ";
		cout<<"\n * 5 for deleting a record                                 * ";
		cout<<"\n * 6 for modifying a record                                * ";
		cout<<"\n * 7 for reports and query                                 * ";
		cout<<"\n * 8 for displaying a particular record (record no. basis) * ";
		cout<<"\n * 9 to count all the records                              * ";                                                                                   
		cout<<"\n * 10 to quit                                              * ";
		cout<<"\n *********************************************************** ";
		cout<<"\n\n enter choice ";
		cin>>choice;
switch(choice)
		{
			case 1:
			file.open("empl.dat",ios::app|ios::binary);
			do
			{
				ob.input();
				file.write((char*)&ob,sizeof(ob));
				cout<<"\n new records(Y/N) ";
				cin>>ch;
			}
			while(ch=='Y'||ch=='y');
			file.close();
			break;
			case 2:
			file.open("empl.dat",ios::in|ios::binary);
			cout<<"\n============================================ ";
									
			cout<<"\nEMPNO\tNAME\t\tSALARY\tDESIGNATION";
			cout<<"\n============================================ ";
			while(file.read((char*)&ob,sizeof(ob)))
			{
				ob.display();
			}
			cout<<"\n============================================ ";
			file.close();
			break;
			case 3:
			cout<<"\n Enter Number Of Employee ";
			cin>>eno;
			flag=0;
			file.open("empl.dat",ios::in|ios::binary);
			while(file.read((char*)&ob,sizeof(ob)))
				{
					if(ob.get_empno()==eno)
					{
						ob.display();
						flag=1;              
						break;
					}
				}

			file.close();
			if(flag==0)
			cout<<"Record Doesn't Exist ";
			break;
			case 4:
			file.open("empl.dat",ios::out|ios::binary);
			do
				{
					ob.input();

					file.write((char*)&ob,sizeof(ob));
					cout<<"\n new records(Y/N) ";
					cin>>ch;
				}
				while(ch=='Y'||ch=='y');
				file.close();
				break;
			case 5:
			cout<<"\n Enter employee No ";
			cin>>eno;
			flag=0;
			file.open("empl.dat",ios::in|ios::binary);
			file1.open("tempt.dat",ios::out|ios::binary);
			while(file.read((char*)&ob,sizeof(ob)))
			{
				if(ob.get_empno()!=eno)
				{
					file1.write((char*)&ob,sizeof(ob));
				}
				else
				{
					flag=1;
				}
			}
			file.close();
			file1.close();
			if(flag==0)
			{
				cout<<"\n Record Not Found ";
				remove("tempt.dat");
			}
			else
			{
				remove("empl.dat");
				rename("tempt.dat","empl.dat");
			}       					
			break;
			case 6:
			file.open("empl.dat",ios::in|ios::out|ios::binary|ios::ate);
				cout<<"\n Enter Number Of Employee ";
				cin>>eno;
				flag=0;
				file.seekg(0);
				while(file.read((char*)&ob,sizeof(ob)))
				{
					if(ob.get_empno()==eno)
					{
						flag=1;
						loc=file.tellg()-sizeof(ob);
						break;
					}
				}
				if(flag==1)
				{
					cout<<"\n Old Record ";
					ob.display();
					cout<<"\n Enter Modification ";
					ob.input();
					file.seekg(loc);		   
					file.write((char*)&ob,sizeof(ob));
					cout<<"\n Modification done ";
				}
				else
				{
					cout<<"\n Record Not Found ";
				}
				break;
			case 7:
			do
			{
			clrscr();
			cout<<"\n REPORTS of SUBHA Private Limited ";
			delay(900);
			clrscr();
			cout<<"\n =================================== ";
			cout<<"\n |             MENU                | ";
			cout<<"\n =================================== ";
			cout<<"\n | 1 for Payroll                   | ";
			cout<<"\n | 2 for Pay Slip                  | ";																			
			cout<<"\n | 3 for Increment Of Basic Salary | ";
			cout<<"\n | 4 to Return To Main Menu        | ";
			cout<<"\n =================================== ";
			cout<<"\n\n Enter Your Choice ";
			cin>>choice1;
			switch(choice1)
				{
					case 1:
					clrscr();
					cout<<"\n\t\t\t PAYROLL of SUBHA Private Limited \n";
					file.open("empl.dat",ios::in|ios::binary);
					cout<<"\n================================================================================";
					cout<<"\nEMPNO\tNAME\t  SALARY  DESIGNATION   DA\tHRA\tTAX\tGROSS\tNET ";
					cout<<"\n================================================================================";
					while(file.read((char*)&ob,sizeof(ob)))
					{				
					ob.display1();
					cout<<"\n--------------------------------------------------------------------------------";
					}
					file.close();
					break;
					case 2:
					clrscr();
					cout<<"\n\t\t\t PAYSLIP of Employee Of SUBHA Private Limited \n";
					cout<<"\n Enter Number Of Employee ";
					cin>>eno;
					flag=0;
					file.open("empl.dat",ios::in|ios::binary);
					while(file.read((char*)&ob,sizeof(ob)))
					{
						if(ob.get_empno()==eno)
						{
						ob.display2();
						flag=1;
						break;
						}
					}

					file.close();
					if(flag==0)		  
					cout<<"Record Doesn't Exist ";
					break;
					case 3:
					clrscr();
					file.open("empl.dat",ios::in|ios::out|ios::binary|ios::ate);
					cout<<"\n Enter Employee Number ";
					cin>>eno;
					flag=0;
					file.seekg(0);
					while(file.read((char*)&ob,sizeof(ob)))
					{
						if(ob.get_empno()==eno)
						{
						flag=1;
						loc=file.tellg()-sizeof(ob);
						break;
						}
					}
					if(flag==1)
					{
					cout<<"\n Old Record ";
					ob.display();
					file.seekg(loc);             
					cout<<"\n\n Enter The Percentage Of Incement ";
					cin>>t;
					ob.set_increment(t);
					ob.calculate();
					file.write((char*)&ob,sizeof(ob));
					cout<<"\n Modification done ";
					}
					else
					{
					cout<<"\n Record Not Found ";
					}
					break;
					case 4:
					cout<<"\n Back To Main Menu ";
					break;
					default:
					cout<<"\n Wrong Choice ";
				}
				cout<<"\n Press Any Key ";
				getch();
			}
			while(choice1!=4);
			break;
			case 8:					  
			cout<<"\n Enter Record Number ";
			cin>>n;
			flag=0;
			int t=0;
			file.open("empl.dat",ios::in|ios::binary);
			while(file.read((char*)&ob,sizeof(ob)))
				{
					t=t++;
					if(t==n)
					{
						ob.display();
						flag=1;
						break;
					}
				}
			file.close();
			if(flag==0)
			cout<<"Record Doesn't Exist ";
			break;
			case 9:
			int p=0;
file.open("empl.dat",ios::in|ios::binary);
			while(file.read((char*)&ob,sizeof(ob)))
			{
				p++;
			}
			file.close();     				
			cout<<"\n"<<p;
			break;
			case 10:
			cout<<"\n Thank You……. ";
			break;
			default:
			cout<<"\n WRONG CHOICE ";
		}
		cout<<"\n Press Any Key ";
		getch();
	}
		while(choice!=10);
}