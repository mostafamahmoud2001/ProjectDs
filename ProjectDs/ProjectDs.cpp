#include <iostream>
#include <vector>
#include <string>
#include "Customer.h"
#include "Seller.h"
#include "Product.h"
#include "Admin.h"
using namespace std;
//Done
int  customer_signin (vector<Customer> &v1 )
{
	string name;
	bool valid = false;
	string password;
	int index = -1;
	cout << "                                          ______  Sign in(Customer)  ______" << endl;
	cout << "Enter your email : " ;
	cin >> name;
	cout << "Enter your password : " ;
	cin >> password;

	for (int i = 0; i < v1.size(); i++)
	{
		if (name == v1[i].getemail() && password == v1[i].getPass())
		{
			valid = true;
			index = i;
			break;
		}		
	}
	if (valid == true)
		cout << "You loged in successfully" << endl;
	else
		cout << "Incorrect email or password " << endl;
	cout << endl << "________________________________________________________________________________________________________________________" << endl;
	return index;
}
//Done
void customer_signup(vector<Customer> &s1)
{
	string phone;
	string name, password, address, email;
	cout << "                                          ______  Sign up(Customer)  ______" << endl;
	cout << "Enter your name : ";
	cin >> name;
	cout << "Enter your password : ";
	for (;true;)
	{
	cin >> password;
	if (password.length() >= 6)
		break;
	else  {
	cout << "The password should be more than 6 digits : ";
	}
	}
	cout << "Enter your address : " ;
	cin >> address;
	cout << "Enter your email : ";
	while (true)
	{
		bool mail = false;
		cin >> email;
	for (int i = 0;i<email.size();i++)
	{
		if (email[i] == '@')
		{
			mail = true;
			break;
		}
	}
	if (mail == true)
		break;
	else
	{
		cout << "Invalid email, Enter your e-mail again : ";
		
	}
	}
	cout << "Enter your phone number : ";
	for (;true;)
	{
	cin >> phone;
	if (phone.size() == 11)
	{
		break;
	}
	else
	{
		cout << "Invalid phone number, Enter your phone number again : ";	
	}
	}
	cout << endl << "________________________________________________________________________________________________________________________" << endl;
	Customer c3(name, email, password, phone, address);
	s1.push_back(c3);
}
//Done
int seller_signin(vector<Seller> v1) 
{
	string name;
	bool valid = false;
	string password;
	int index = -1;
	cout << "                                          ______  Sign in(Seller)  ______" << endl;
	cout << "Enter your email : " ;
	cin >> name;
	cout << "Enter your password : ";
	cin >> password;
	for (int i = 0; i < v1.size(); i++)
	{
		if (name == v1[i].getemail() && password == v1[i].getPass())
		{
			valid = true;
			index = i;
			break;
		}
	}
	if (valid == true)
		cout << "You loged in successfully" << endl;
	else
		cout << "Incorrect e-mail or password " << endl;
	cout << endl << "________________________________________________________________________________________________________________________" << endl;
	return index;
}
//Done
void seller_signup(vector<Seller>& s1) 
{
	string name, password, email;
	cout << "                                          ______  Sign up(Seller)  ______" << endl;
	cout << "Enter your name : ";
	cin >> name;
	cout << "Enter your password : ";
	for (; true;)
	{
		cin >> password;
		if (password.length() >= 6)
			break;
		else {
			cout << "The password should be more than 6 digits : ";
		}
		}
	cout << "Enter your e-mail : " ;
	while (true)
	{
		bool mail = false;
		cin >> email;
		for (int i = 0; i < email.size(); i++)
		{
			if (email[i] == '@')
			{
				mail = true;
				break;
			}
		}
		if (mail == true)
			break;
		else
		{
			cout << "Invalid email, Enter your e-mail again : ";
		}
	}
	cout << endl << "________________________________________________________________________________________________________________________" << endl;
	Seller c3(name, email, password);
	s1.push_back(c3);
}
int main()
{
	cout << "                                ___________  Welcome to the online market  ___________"<<endl;
	Admin admin("admin", "admin", "admin@gmail.com");
	vector<Product> productes;
	//mobile
	Product x1( "sony", "mobile", 30,  1001,20);
	Product x2( "iphon", "mobile", 50,  1001,31);
	Product x3( "ixomy", "mobile", 60,  1001,35);
	Product x4( "samsong", "mobile", 70,  1001,36);
	Product x5( "oppo", "mobile", 80,  1001,48);
	//books
	Product x6( "herkel", "book", 90,  1001,22);
	Product x7( "lord of the ring", "book", 10,  1001,12);
	Product x8( "breaking bad", "book", 110,  1001,55);
	Product x9( "viking", "book", 120,  1001,11);
	Product x10( "peaky blinders", "book", 130,  1001,65);

	//labtops
	Product x11( "sony", "labtop", 140,  1001,22);
	Product x12( "appale", "labtop", 150,  1001,65);
	Product x13("lG", "labtop", 113, 1001,65);
	Product	 x14( "lenovo", "labtop", 170,  1001,12);
	Product x15( "hp", "labtop", 190,  1001,65);
	productes.push_back(x1);
	productes.push_back(x2);
	productes.push_back(x3);
	productes.push_back(x4);
	productes.push_back(x5);
	productes.push_back(x6);
	productes.push_back(x7);
	productes.push_back(x8);
	productes.push_back(x9);
	productes.push_back(x10);
	productes.push_back(x11);
	productes.push_back(x12);
	productes.push_back(x13);
	productes.push_back(x14);
	productes.push_back(x15);
	//=================================================================================================
	vector<Customer> customers;
	vector<Seller> sellers;
	Customer c1("mostafa", "mostafa@gmail.com","12345", "01211542545", "zsd");
	Customer c2("magdy", "magdy@gmail.com", "123445","15457575572", "zsdd");
	Seller s1("yousef","yousef@gmail.com","123456");
	customers.push_back(c1);
	customers.push_back(c2);
	sellers.push_back(s1);
	//========================================================================
	while (true)
	{
		int index = 0;
		cout << endl<<endl;
		cout << " 1- Seller                     2- Customer                      3-Admin                     4- Close the program " << endl;
		cout << endl;
		int num;
		cout << "Your choice : ";
		cin >> num;
		cout << endl << "________________________________________________________________________________________________________________________"<<endl;
		
		if (num == 1)
		{
			cout << "1- Sign in                     2- sign up" << endl << endl;;
			cout << "Your choice : ";
			int x;
			while (1)
			{
				cin >> x;
				if (x != 1 && x != 2)
					cout << "Invalid, Enter your choice again : ";
				else
					break;
			}
			cout << endl << "________________________________________________________________________________________________________________________" << endl;
			if (x == 1)
			{
				 index = seller_signin(sellers);
				 if (index == -1)
					 continue;
				 cout <<endl<< "Hello " << sellers[index].getName() << endl;
				 while (1)
				 {
					 int x= sellers[index].mainMenuSeller();
					 if (x == 1)
					 {
						 admin.pushToWaited(sellers[index].addProduct());
					 }
					 else
						 break;
				 }
			}
			else if (x == 2)
			{
				seller_signup(sellers);
			}
		}
		else if (num == 2)
		{
			cout << "1- Sign in                     2- sign up" << endl << endl;;
			cout << "Your choice : ";
			int x;
			while (1)
			{
				cin >> x;
				if (x != 1 && x != 2)
					cout << "Invalid, Enter your choice again : ";
				else
					break;
			}
			cout << endl << "________________________________________________________________________________________________________________________" << endl;
			if (x == 1)
			{
				 index = customer_signin(customers);
				if (index == -1)
				{
					continue;
				}
				while (1) 
				{
					int choose = customers[index].mainMenuCustomer();
					if (choose == 1)
							customers[index].browseByCategory(productes);
					else if (choose == 2)
						customers[index].browseByName(productes);
					else if (choose == 3)
					{
						//Saloha
						cout << "Are you want to confrim the buying ? " << endl << endl;
						cout << "If you want to confirm press 1 " << endl;
						cout << "confirmation done Successfully!" << endl;
						customers[index].display_total(customers[index].cart, productes);
						customers[index].display_rates(productes);
					}
					else
						break;
				}
			}
			else if (x == 2)
			{
				customer_signup(customers);

			}
		}
		else if (num == 3)
		{
			string email,pass;
			cout << "                                          ______  Sign in(Admin)  ______" << endl;
			cout << "Enter your email : ";
			cin >> email;
			cout << "Enter your Password : ";
			cin >> pass;
	
			if (email == admin.getEmail() && pass == admin.getpassword())
			{
				cout << endl << "________________________________________________________________________________________________________________________" << endl;
				while (true)
				{
					int x = admin.AdminMainMenu();
					if (x == 1)
					{
						admin.viewWaitedProduct(productes);
					}
					else
						cout << endl << "________________________________________________________________________________________________________________________" << endl;
						break;
				}
			}
			
		}
	}
		cout <<endl<<endl<< "=================================================================" << endl;
	
		cout << customers.size() << endl;
		vector<Customer>().swap(customers);
}
