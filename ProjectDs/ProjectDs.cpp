#include <iostream>
#include <vector>
#include <string>
#include "Customer.h"
#include "Seller.h"
#include "Product.h"
using namespace std;
int  customer_signin(vector<Customer> &v1)
{
	string name;
	bool valid = false;
	string password;
	int index = -1;
	cout << "Enter your name " << endl;
	cout << "Enter your password " << endl;
	cin >> name;
	cin >> password;

	for (int i = 0; i < v1.size(); i++)
	{
		if (name == v1[i].getname() && password == v1[i].getPass())
		{
			valid = true;
			index = i;
			break;
		}		
	}
	if (valid == true)
		cout << "valid" << endl;
	else
		cout << "invalid, incorrect e-mail or password " << endl;
	return index;
}
void customer_signup(vector<Customer> &s1)
{
	int phone;
	string name, password, address, email;

	cout << "Enter your name" << endl;
	cin >> name;
	cout << "Enter your password" << endl;
	for (;true;)
	{
	cin >> password;
	if (password.length() >= 6)
		break;
	else  {
	cout << "invalid,should be more than 6"<<endl;
	cout << "-------------" << endl;
	cout << "enter password again" << endl;
	}
	}
	cout << "Enter your address" << endl;
	cin >> address;
	cout << "Enter your e-mail" << endl;
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
		cout << "invalid,should contain @" << endl;
		cout << "-------------" << endl;
		cout << "enter your e-mail again" << endl;
	}
	}
	cout << "Enter your phone" << endl;
	for (;true;)
	{
	cin >> phone;
	if (phone >= 11)
	{
		cout << "--------------------" << endl;
		cout << "valid" << endl;
		break;
	}
	else
	{
		cout << "invalid,should be equal 11" << endl;
		cout << "-------------" << endl;
		cout << "enter your phone again" << endl;
			
	}
	}
	Customer c3(name, email, password, phone, address);
	s1.push_back(c3);
}
int seller_signin(vector<Seller> v1) //////// seller sign_in
{
	string name;
	bool valid = false;
	string password;
	int index = -1;
	cout << "Enter your name " << endl;
	cout << "Enter your password " << endl;
	cin >> name;
	cin >> password;

	for (int i = 0; i < v1.size(); i++)
	{
		if (name == v1[i].getName() && password == v1[i].getPass())
		{
			valid = true;
			index = i;
			break;
		}
	}
	if (valid == true)
		cout << "valid" << endl;
	else
		cout << "invalid, incorrect e-mail or password " << endl;
	return index;
}

void seller_signup(vector<Seller>& s1) ////////// seller sign_up
{
	string name, password, email;

	cout << "Enter your name" << endl;
	cin >> name;
	cout << "Enter your password" << endl;
	for (; true;)
	{
		cin >> password;
		if (password.length() >= 6)
			break;
		else {
			cout << "invalid,should be more than 6" << endl;
			cout << "-------------" << endl;
			cout << "enter password again" << endl;
		}
	}
	cout << "Enter your e-mail" << endl;
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
			cout << "invalid,should contain @" << endl;
			cout << "-------------" << endl;
			cout << "enter your e-mail again" << endl;
		}
	}
	Seller c3(name, email, password);
	s1.push_back(c3);
}
int main()
{
	vector<Product> v1;
	//mobile
	Product x1( "sony", "mobile", 30,  1001);
	Product x2( "iphon", "mobile", 50,  1001);
	Product x3( "ixomy", "mobile", 60,  1001);
	Product x4( "samsong", "mobile", 70,  1001);
	Product x5( "oppo", "mobile", 80,  1001);

	//books
	Product x6( "herkel", "book", 90,  1001);
	Product x7( "lord of the ring", "book", 10,  1001);
	Product x8( "breaking bad", "book", 110,  1001);
	Product x9( "viking", "book", 120,  1001);
	Product x10( "peaky blinders", "book", 130,  1001);

	//labtops
	Product x11( "sony", "labtop", 140,  1001);
	Product x12( "appale", "labtop", 150,  1001);
	Product x13("lG", "labtop", 113, 1001);
	Product	 x14( "lenovo", "labtop", 170,  1001);
	Product x15( "hp", "labtop", 190,  1001);

	v1.push_back(x1);
	v1.push_back(x2);
	v1.push_back(x3);
	v1.push_back(x4);
	v1.push_back(x5);
	v1.push_back(x6);
	v1.push_back(x7);
	v1.push_back(x8);
	v1.push_back(x9);
	v1.push_back(x10);
	v1.push_back(x11);
	v1.push_back(x12);
	v1.push_back(x13);
	v1.push_back(x14);
	v1.push_back(x15);
		
	//=================================================================================================
	vector<Customer> customers;
	vector<Seller> sellers;
	Customer c1("mostafa", "mostafa@gmail.com","12345", 01211542545, "zsd");
	Customer c2("magdy", "magdy@gmail.com", "123445",15457575572, "zsdd");
	Seller s1("yousef","yousef@gmail.com","123456");
	customers.push_back(c1);
	customers.push_back(c2);
	sellers.push_back(s1);
	
	//========================================================================
	
	while (true)
	{
		int index = 0;
		cout << "for seller press 1" << endl;
		cout << "for Customer press 2" << endl;
		cout << "for admin press 3" << endl;
		cout << "close program press 4" << endl;
		int num;
		cout << "Please , Enter a number" << endl;
		cin >> num;
		if (num == 1)
		{
			cout << "for sign in press 1" << endl;
			cout << "for sign up press 2" << endl;
			int x;
			cin >> x;
			if (x == 1)
			{
				 index = seller_signin(sellers);
			}
			else if (x == 2)
			{
				seller_signup(sellers);
			}
		}
		else if (num == 2)
		{
			cout << "for sign in press 1" << endl;
			cout << "for sign up press 2" << endl;
			int x;
			cin >> x;
			if (x == 1)
			{
				 index = customer_signin(customers);
				if (index == -1)
				{
					cout << endl << endl << "=================================================================" << endl;
					continue;
				}
				while (1) {
					int choose = customers[index].mainMenuCustomer();
					if (choose == 1)
						customers[index].browseByCategory(v1);
					else if (choose == 2)
						customers[index].browseByName(v1);
					else if (choose == 3)
					{
						cout << "Are you want to confrim the buying ? " << endl << endl;
						cout << "If you want to confirm press 1 " << endl;
							cout << "confirmation done Successfully!" << endl;
							customers[index].display_total(customers[index].cart, v1);
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

		

	/*	else if (num == 3)
		{
			int id_of_customer = -1;
			id_of_customer = customers[index].getID();
			vector<Receipt> re;
			Receipt s0(1, "mobile", 2, 2, 200, 32);
			Receipt s(2, "book", 2, 2, 300, 33);
			Receipt s2(3, "labtop", 2, 2, 400, 34);
			re.push_back(s0);
			re.push_back(s);
			re.push_back(s2);

		}*/
	}
		cout <<endl<<endl<< "=================================================================" << endl;
	
		cout << customers.size() << endl;
		vector<Customer>().swap(customers);
}
