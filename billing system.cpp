#include<bits/stdc++.h>
using namespace std;
class shopping{
	
	private:
		
		int pcode;
		float price;
		float dis;
		string pname;
		
		public:
			void menu();
			void administrator();
			void buyer();
			void add();
			void edit();
			void rem();
			void list();
			void recipt();
};

void shopping::menu()
{
	m:
	int choice;
	string email;
	string password; 
	 cout<<"\t\t_________________________\n";
	 cout<<"\t\t                         \n";
	 cout<<"\t\t   supermarket menu      \n";
	 cout<<"\t\t                         \n";
	 cout<<"\t\t_________________________\n";
	 cout<<"\t\t                         \n";
	 cout<<"\t\t    1. administrator     \n";
	 cout<<"\t\t_________________________\n";
	 cout<<"\t\t    2.buyer              \n";
	 cout<<"\t\t_________________________\n";
	 cout<<"\t\t    3.exit               \n";
	 cout<<"\t\t_________________________\n";
	 cout<<"\t\t    please select          ";
	 cin>>choice;
	 
	 switch(choice)
	 {
	 	case 1:
	 		cout<<"\t\t please login \n";
	 		cout<<"\t\t enter email    ";
	 		cin>>email;
	 		cout<<"\t\t_______________\n";
	 		cout<<"\t\t enter password  ";
	 		cin>>password;
	 		
	 		if(email=="abc@gmail.com"&&password=="123abc")
	 		{
	 			administrator();
	 			
			 }
			 else
			 cout<<"ivalid email or password";
			 break;
			 
	    case 2:
			 	buyer();
			 	
		case 3:
			exit(0);
		default:
			cout<<"please select from given options";
			 	
			 
	 		
	 }
	 
	goto m; 
}

void shopping::administrator()
{
	m:
	int choice;
	cout<<"\t\t    administrator menu    ";
	cout<<"\t\t 1) add the product    ";
	cout<<"\t\t 2) modify the product ";
	cout<<"\t\t 3) delete the product ";
	cout<<"\t\t 4) back to main menu  ";
	cout<<"\t\tenter choice";
	
	cin>>choice;
	switch(choice)
	{
		case 1:
			add();
			break;
		case 2:
			edit();
			break;
		case 3:
			rem();
			break;
		case 4:
     		menu();
			break;
			
		default :
			cout<<"invlalid choice";		
					
	}
	goto m;
}

void shopping::buyer()
{
	m:
	int choice;
	cout<<"\t\t buyer \n";
	cout<<"\t\t_________________________\n";
	cout<<"\t\t                         \n";
	cout<<"\t\t 1) buy product \n";
	cout<<"\t\t                        \n";
	cout<<"\t\t go back  \n";
	cout<<"\t\tenter choice";
	cin>>choice;
	switch(choice)
	{
		case 1:
			recipt();
			break;
		case 2:
			menu();
				
		default:
			cout<<"invlid choice";
	}
	goto m;
	
}

void shopping::add()
{
	m:
	fstream data;
	int c;
	int token=0;
	float p;
	float d;
	string n;
	
	cout<<"\t\t add new product \n";
	cout<<"\t\t product code of product \n";
	cin>>pcode;
	cout<<"\t\tname of the product\n";
	cin>>pname;
	cout<<"\t\t price of product\n";
	cin>>price;
	cout<<"\t\t discount on product \n";
	cin>>dis;
	
	data.open("database.txt",ios::in);
   if(!data)
   {
	data.open("database.txt",ios::app|ios::out);
	data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
	data.close();
  }
  else
  {
  	data>>c>>n>>p>>d;
  	
  	while(!data.eof())
  	{
  		if(c==pcode)
  		{
  			token++;
		  }
		  data>>c>>n>>p>>d;
	  }
	  data.close();
	  
	  if(token==1)
	  {
	  	cout<<"product is same enter again";
	  goto m;
      }
	  else
	  {
	  	data.open("database.txt",ios::app|ios::out);
	  	data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
	  	data.close();
	  }
  }
  cout<<"\n\t\t record inserted! ";
  
}

void shopping::edit()
{
	fstream data,data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	
	cout<<"\n\t\t modify the record";
	cout<<"\n\t\t product code ";
	cin>>pkey;
	
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\t\t file doesn't exist! ";
	}
	else
	{
		data1.open("database1.txt",ios::app|ios::out);
		
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pkey==pcode)
			{
				cout<<"\n\t\t product new code ";
				cin>>c;
				cout<<"\n\t\t name of product ";
				cin>>n;
				cout<<"\n\t\t price";
				cin>>p;
				cout<<"\n\t\t discount";
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\t\t record edited";
				token++;
			}
			else
			data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		cout<<"\n\t\t record not found sorry! ";
	
			
		}
	}

	
void shopping::rem()
{
	fstream data,data1;
	int pkey;
	int token=0;

	
	cout<<"\n\t\t delete product ";
	cout<<"\n\t\t product code ";
	cin>>pkey;
	
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\t\t file doesn't exist! ";
	}
	else
	{
		data1.open("database1.txt",ios::app|ios::out);
		
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pkey==pcode)
			{
			cout<<"\n\t\t product deleted";
			token++;
			}
			else
			data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		cout<<"\n\t\t record not found sorry! ";
	
			
		}
	
	}
	
	void shopping:: list()
	{
     fstream data;
	 data.open("database.txt",ios::in);
	 cout<<"\n\n___________________\n";
	 cout<<"prono\tname\tprice\n";
	 cout<<"\n\n___________________\n";
	 data>>pcode>>pname>>price>>dis;
	 while(!data.eof())
	 {
	 	cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
	 	data>>pcode>>pname>>price>>dis;
			 }	
			 data.close();	
	}
	
	void shopping::recipt()
	{
		fstream data;
		int arrc[100];
		int arrq[100];
		char choice;
		int c=0;
		float amount=0;
		float dis=0;
		float total=0;
		
		cout<<"\n\n\t\t recipt ";
		data.open("database.txt",ios::in);
		if(!data)
		{
			cout<<"\n\n empty database";
		}
		else
		{
			data.close();
			
			list();
			    cout<<"\n___________________________\n";
				cout<<"\n                    \n";
				cout<<"\n  please place the order \n";
				cout<<"\n                   \n";
				cout<<"\n___________________________\n"; 
				
				do
				{
					m:
					cout<<"\n\nenter product code";
					cin>>arrc[c];
					cout<<"\n\nenter the product quantity";
					cin>>arrq[c];
					for(int i=0;i<c;i++)
					{
						if(arrc[c]==arrc[i])
						{
							cout<<"\n\n duplicate product code please try again!";
							goto m;
						}
					}
					c++;
					cout<<"\n\n do u want to buy another? if yes then y else n";
					
				}while(choice=='y');
				
				cout<<"\n\t\t___________receipt__________\n";
				cout<<"\nproduct no\tproduct name\t product qty \tprice\tamount\tamount with discount\n";
				for(int i=0;i<c;i++)
				{
					data.open("database.txt",ios::in);
					data>>pcode>>pname>>price>>dis;
					while(!data.eof())
					{
						if(pcode==arrc[i])
						{
							amount=price*arrq[i];
							dis=amount-(amount*dis/100);
							total=total+dis;
							cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;
						}
						data>>pcode>>pname>>price>>dis;
					}
				}
				data.close();
		}
		cout<<"\n\n________________";
		cout<<"\n total amount "<<total;
	}
	
	int main()
	{
		shopping s;
		s.menu();
	}
	
	


