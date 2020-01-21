#include<iostream>
#include<fstream>
#include<conio.h>  //arjinder.20858@lpu.co.in
#include<windows.h>
#include<stdlib.h>
using namespace std;

class shop
{
	int cno;
	char name[50] , address[50];
	int cph ,csn;
	float bno;
	public:
		
		
		void input()
		{
			cout<<" Enter Customer I.D :"<<endl;
			cin>>cno;
			cout<<" Enter Name :"<<endl;
			cin>>name;
			cout<<" Enter Address :"<<endl;
			cin>>address;
			cout<<" Customer Phone Number :"<<endl;
			cin>>cph;
			cout<<" Customer Service number :"<<endl;
		    cin>>csn;
		    cout<<" Customer Bill Number :"<<endl;
		    cin>>bno;
		    
		}
		
		void output()
		{
			cout<<" Customer Data Sheet "<<endl;
			cout<<" ------------------- "<<endl;
	        cout<<" Customer I.D :"<<cno<<endl;
			cout<<" Customer Name :"<<name<<endl;
			cout<<" Customer Address :"<<address<<endl;
			cout<<" Customer Phone Number :"<<cph<<endl;
			cout<<" Customer Service Number :"<<csn<<endl;	
			cout<<" Customer Bill Number :"<<bno<<endl;
		}
		int rno()
		{
			return cno;
		}
};

void write()
{
	char ch;
		shop c;
		fstream f1;
		c.input();
		f1.open("XYZ.txt",ios::app|ios::binary);
		cout<<"\n\n\tDO you want to save the record(y/n)\t";
		cin>>ch;
		if(ch=='y')
		{
		f1.write((char*)&c,sizeof(c));
		}
		f1.close();
}

void read()
{
	    shop c;
		fstream f1;
		f1.open("XYZ.txt",ios::in|ios::binary);
		while(!f1.eof())
		{
		f1.read((char*)&c,sizeof(c));
		c.output();
		if(f1.eof())
		{
		cout<<"\n\n   End of the file reached\n\n";
		}
		}
		f1.close();
}
 void modify()
 {
 	    shop c;
		fstream f1("XYZ.txt",ios::in | ios::out | ios::binary);
		int rn;
		long pos;
		char found='f';
		cout<<"\n\n Enter the Customer ID you want to MODIFY :\t";
		cin>>rn;
		while(!f1.eof())
		{
		pos=f1.tellg();
		f1.read((char*)&c,sizeof(c));
		if(c.rno()==rn)
		{
		c.input();
		f1.seekg(pos);
		f1.write((char*)&c,sizeof(c));
		found='t';
		break;
		}
		}
		if(found=='f')
		cout<<"\n\n\tRECORD NOT FOUND\n";
		f1.seekg(0);
		cout<<"\n Now the file contains\n\n";
		c.output();
		f1.close();
 }
 
 void search()
 {
 	shop c;
		int rn;
		char found='n';
		ifstream f1("XYZ.txt",ios::in);
		cout<<"\n\n Enter Customer ID you want to SEARCH :\t";
		cin>>rn;
		while(!f1.eof())
		{
		f1.read((char*)&c,sizeof(c));
		if(c.rno()==rn)
		{
		c.output();
		found='y';
		break;
		}
		}
		if(found=='n')
		cout<<"\n\n\tRECORD NOT FOUND!!!!!!!!!!!!!\n"<<endl;
		f1.close();
	}
class billing
{		
public:
		
		int amount=0, time =0;
		int prob;
		int bill_no;
		int r;
		void bill()
		{
			cout<<" Enter the bill no "<<endl;
			cin>>bill_no;
			do
			{
			cout<<" ************Billing Section************ "<<endl;
			cout<<" --------------------------------------- "<<endl;	
			cout<<" Please select the problem you are facing "<<endl;
			cout<<" Press 1 for hardware related issues"<<endl;
			cout<<" Press 2 for software related issues"<<endl;
			cout<<" Press 3 to buy accessories"<<" 				Bill no: "<<bill_no<<endl;
					
				cin>>prob;
				switch (prob)
				{
				case 1:
				 		{
						char q; 
						cout<<" *** Hardware Related Issues*** "<<endl;
						cout<<" Press 'a' for Battery replacement "<<endl;
						cout<<" Press 'b' for Sound/Speaker issue"<<endl;
						cout<<" Press 'c' for Display Issues"<<endl;
						cout<<" Press 'd' for Body repairs"<<endl;
						cin>>q;
						switch (q)
						{
							case 'a':
								cout<<" Cost of Battery replacement = Rs.3000"<<endl;
								cout<<" Time required = 7 hours"<<endl;
								amount = amount + 3000;
								time = time + 7;
								break;
							case 'b':
								cout<<" Cost of Sound Repairing = Rs. 500 "<<endl;
								cout<<" Time required = 2 hour"<<endl;
								amount = amount + 500;
								time = time + 2;
								break;
							case 'c':
								cout<<" Cost of changing the display = Rs. 1500"<<endl;
								cout<<" Time required = 6 hours"<<endl;
								amount = amount + 1500;
								time = time + 6;
								break;
							case 'd':
								cout<<" Cost of Body repairing = Rs. 600"<<endl;
								cout<<" Time Required = 1 hour"<<endl;
								break;
								default:
								cout<< " Please enter a valid choice"<<endl;
							}
							break;
						}
						
							case 2:
								{
									char q;
									cout<<" Press 'a' for installing OS "<<endl;
									cout<<" Press 'b' for installing MS Office"<<endl;
									cout<<" Press 'c' for installing Graphics card "<<endl;
									cout<<" Press 'd' for 3rd Party software issues"<<endl;
									cout<<" Press 'e' for installing Antivirus"<<endl;
									cout<<" Press 'f' for issues related to WiFi"<<endl;
									cin>>q;
									
									switch (q)
									{
										case 'a':
											cout<<"Cost of installing OS is Rs.4000"<<endl;
											cout<<"Time required 5 hours"<<endl;
											amount = amount + 4000;
											time = time + 5;
											break;
										case 'b':
											cout<<"Cost of installing MS Office is Rs.2500"<<endl;
											cout<<"Time required 1 hours"<<endl;
											amount = amount + 2500;
											time = time +1;
											break;
										case 'c':
											cout<<"Cost of installing Graphics Card is Rs.1000"<<endl;
											cout<<"Time required 2 hours"<<endl;
											amount = amount + 1000;
											time = time + 2;
											break;
										case 'd':
											cout<<"Cost of resolving 3rd Party software is Rs.500 "<<endl;
											cout<<"Time required is 4 hours"<<endl;
											amount = amount + 500;
											time = time + 4;
											break;
										case 'e':
											cout<<"Cost of installing antivirus is Rs.3200"<<endl;
											cout<<"Time required is 3 hours"<<endl;
											amount = amount + 3200;
											time = time + 3;
											break;
										case 'f':
											cout<<"Cost of resolving WiFi issues is Rs.300"<<endl;
											cout<<"Time required is 2 hours"<<endl;
											amount = amount + 300;
											time = time + 2;
											break;
										default:
										    cout<<"Please enter a valid choice"<<endl;						
								}
								break;
								}
									case 3:
										{
											char q;
											cout<<"Press 'a' for buying a new pendrive"<<endl;
											cout<<"Press 'b' for buying a new charger adapter"<<endl;
											cout<<"Press 'c' for buying a new external hard-disk"<<endl;
											cout<<"Press 'd' for buying a new cooling pad"<<endl;
											cin>>q;
											switch(q)
											{
												case 'a':
													cout<<" Cost of new pendrive is Rs.450"<<endl;
													amount = amount + 450;
													break;
												case 'b':
													cout<<"Cost of new charger adapter is Rs.850"<<endl;
													amount = amount +850;
													break;
												case 'c':
													cout<<"Cost of new external hard-disk is 1250"<<endl;
													amount = amount + 1250;
													break;
												case 'd':
													cout<<"Cost of new cooling pad is Rs.950"<<endl;
													amount = amount + 950;
													break;
												default:
												cout<<"Please select a valid option"<<endl;				
											}
											   
											break;	
											
										}
									
							
									
									
								}
								cout<<" Press 1 to Return to Main menu or any other number to Exit "<<endl;
								cin>>r;
							
			
						 } 
						 while (r==1);
					cout<<" Your Final bill amount is "<<amount<<" Rupees only "<<endl;
					cout<<" Your product will be ready in "<<time<<" Hours approx."<<endl;	 
				}
			};
void write_bill()
{
	char ch;
		billing b;
		fstream f2;
		b.bill();
		f2.open("ABC.txt",ios::app|ios::binary);
		cout<<"\n\n\tDO you want to save the record(y/n)\t";
		cin>>ch;
		if(ch=='y')
		{
		f2.write((char*)&b,sizeof(b));
		}
		f2.close();
	}
	
 main()
  {
   	int pk;
  	char q;
 	shop c;
 	billing b;
 	system("COLOR 30");
 	do{
   		for(int i=1;i<=100;i++)
  		{
  			system("CLS");

  		cout<<"                                                 -----------------------"<<endl;
  		cout<<"                                                 |   KRISHNA SOLUTIONS  |"<< endl;
		cout<<"                                                 ----------------------- "<<endl;
		cout<<"      			No.of Customers that visited today = "<<i<<endl;
		
 	cout<<"                                                       *** Choice Menu ***  "<<endl;
 	cout<<" Press 1 to enter the details of new customer"<<endl;
 	cout<<" Press 2 to search customer "<<endl;
 	cout<<" Press 3 to modify customer details"<<endl;
 	cout<<" Press 4 to show customer info"<<endl;
 	cout<<" Press 5 to enter the problems and to generate bill"<<endl;
 	cout<<" Press 6 to exit the application"<<endl;
 	cout<<" Enter your response"<<endl;
 	cin>>pk;
 	
 	switch(pk)
 	{
 		case 1:
 		{
 			write() ;
		}
		 break;
		case 2:
		{
			search();
		} 
		break;
		case 3:
		{
			modify();
		}
		break;
		case 4:
		{
			read() ;
		} 
		break;
		case 5:
		{
			write_bill();
		}
		break;
		case 6:
			{
				return 0;
			}
		default:
		cout<<"Enter a valid choice";	
		
	 }
	 q='n';
 	cout<<"Press y to continue"<<endl;
 	cin>>q;
}
}while(q=='n');
 }
 
