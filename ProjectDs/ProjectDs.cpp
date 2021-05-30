#include <iostream>
#include <vector>
#include <string>
#include "Customer.h"
#include "Seller.h"
#include "Product.h"
#include "Admin.h"
using namespace std;
int  customer_signin (vector<Customer> v1 )
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
		cout << "Invalid email or password, Try again!" << endl;
	cout << endl << "________________________________________________________________________________________________________________________" << endl;
	return index;
}
void customer_signup(vector<Customer> &s1)
{
	string phone;
	string name, password, address, email;
	cout << "                                          ______  Sign up(Customer)  ______" << endl;
	cout << "Enter your name : ";
	cin >> name;
	cout << "Enter your address : " ;
	cin >> address;
	cout << "Enter your email : ";
	while (true)
	{
		bool mail = false;
		bool exist = false;
		cin >> email;
		for (int i = 0; i < email.size(); i++)
		{
			if (email[i] == '@')
			{
				mail = true;
				break;
			}
		}
		if (mail == false)
		{
			cout << "Invalid email, Enter your email again : ";
		}
		for (int i = 0; i < s1.size(); i++)
		{
			if (s1[i].getemail() == email)
			{
				exist = true;
				cout << "The email is already exist, Try another email : ";
			}
		}
		if (mail == true && exist == false)
			          break;
	}
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
	cout << "You loged up successfully!" << endl;
	cout  << "________________________________________________________________________________________________________________________" << endl;
	Customer c3(name, email, password, phone, address);
	s1.push_back(c3);
}
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
		cout << "Invalid email or password, Try again!" << endl;
	cout  << "________________________________________________________________________________________________________________________" << endl;
	return index;
}
void seller_signup(vector<Seller>& s1) 
{
	string name, password, email;
	cout << "                                          ______  Sign up(Seller)  ______" << endl;
	cout << "Enter your name : ";
	cin >> name;
	cout << "Enter your e-mail : " ;
	while (true)
	{
		bool mail = false;
		bool exist = false;
		cin >> email;
		for (int i = 0; i < email.size(); i++)
		{
			if (email[i] == '@')
			{
				mail = true;
				break;
			}
		}
		if(mail==false)
		{
		cout << "Invalid email, Enter your email again : ";
		}
		for (int i = 0; i < s1.size(); i++)
		{
			if (s1[i].getemail() == email)
			{
				exist = true;
				cout << "The email is already exist, Try another email : ";
			}
		}
		if (mail == true&&exist==false)
			break;
		cout << "Enter your password : ";
		for (; true;)
		{
			cin >> password;
			if (password.length() >= 6)
				break;
			else 
			{
				cout << "The password should be more than 6 digits : ";
			}
		}
	}
	cout << "You loged up successflly!" << endl;
	cout << "________________________________________________________________________________________________________________________" << endl;
	Seller c3(name, email, password);
	s1.push_back(c3);
}
int main()
{
	cout << "                                ___________  Welcome to the online market  ___________"<<endl;
	//______________________________________________________________________________________________________
	//All Products
	vector<Product> productes;
	//mobile
	Product p1( "Sony", "mobile", 3300,  1001,20);
	Product p2( "Iphone", "mobile",6000,  1001,31);
	Product p3( "Nokia", "mobile", 2500,  1001,35);
	Product p4( "Huawei","mobile", 4000,  1001,36);
	Product p5( "Oppo", "mobile", 3500,  1001,48);
	//tv
	Product p6( "Toshiba", "tv", 7200,  1001,22);
	Product p7( "LG", "tv", 8500, 1001,12);
	Product p8( "Samsung", "tv", 12500,  1001,55);
	Product p9( "Panasonic", "tv", 9400,  1001,11);
	Product p10( "Fresh", "tv", 6500,  1001,65);
	//labtops
	Product p11( "Lenovo", "labtop", 12000,  1001,22);
	Product p12( "Dell", "labtop", 15000,  1001,65);
	Product p13("Mac", "labtop", 20000, 1001,65);
	Product	p14( "Asus", "labtop", 18000,  1001,12);
	Product p15( "Hp", "labtop", 13000,  1001,65);
	productes.push_back(p1);
	productes.push_back(p2);
	productes.push_back(p3);
	productes.push_back(p4);
	productes.push_back(p5);
	productes.push_back(p6);
	productes.push_back(p7);
	productes.push_back(p8);
	productes.push_back(p9);
	productes.push_back(p10);
	productes.push_back(p11);
	productes.push_back(p12);
	productes.push_back(p13);
	productes.push_back(p14);
	productes.push_back(p15);
	//_________________________________________________________________________________________
	
	//All Persons
	Admin admin("admin", "admin", "admin@gmail.com");
	vector<Customer> customers;
	vector<Seller> sellers;
	Customer c1("mostafa", "mostafa@gmail.com","12345", "01211542545", "zsd");
	Customer c2("magdy", "magdy@gmail.com", "123445","15457575572", "zsdd");
	Seller s1("yousef","yousef@gmail.com","123456");
	customers.push_back(c1);
	customers.push_back(c2);
	sellers.push_back(s1);
	//The Program
	while (true)
	{
		int index = 0;
		cout << endl;
		cout << "1- Seller "<<endl<<"2- Customer"<<endl<<"3- Admin"    <<endl<<     "4- Close the program " << endl;
		cout << endl;
		int num;
		cout << "Your choice : ";
		cin >> num;
		cout  << "________________________________________________________________________________________________________________________"<<endl;
		//Seller
		if (num == 1)
		{
			cout << "1- Sign in"<<endl<<"2- sign up" << endl<<endl;
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
			cout << "________________________________________________________________________________________________________________________" <<endl;
			//sign in
			if (x == 1)
			{
				 index = seller_signin(sellers);
				 if (index == -1)
					 continue;
				 cout << endl << "Hello " << sellers[index].getName() << endl ;
			      cout <<      "_____________" << endl;

				 while (1)
				 {
					 int x= sellers[index].mainMenuSeller();
					 if (x == 1)
					 {
						 cout << "_____________________________________________" << endl;
						 admin.pushToWaited(sellers[index].addProduct());
					 }
					 else
					 {
						 cout  << "________________________________________________________________________________________________________________________" << endl;
						 break;
					 }
				 }
			}
			//sign up
			else if (x == 2)
			{
				seller_signup(sellers);
			}
		}
		//================================================================================================
		//Customer
		else if (num == 2)
		{
			cout << "1- Sign in" << endl << "2- sign up" << endl << endl;
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
			cout  << "________________________________________________________________________________________________________________________" << endl;
			//sign in
			if (x == 1)
			{
				 index = customer_signin(customers);
				if (index == -1)
				{
					continue;
				}
				while (1) 
				{
					customers[index].sort_product(productes);
					int choose = customers[index].mainMenuCustomer();
					if (choose == 1)
						customers[index].browseByCategory(productes);
					else if (choose == 2)
						customers[index].browseByName(productes);
					else if (choose == 3)
					{
						customers[index].display_total(customers[index].cart, productes);
					}
					else if (choose == 4)
						customers[index].display_allreceipt(productes);
					else
						break;
				}
			}
			//sign up
			else if (x == 2)
			{
				customer_signup(customers);
			}
		}
		//================================================================================================
		//Admin
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
		//================================================================================================
		//Close the program
		else if (num == 4)
		{
		   break;
        }
		//================================================================================================
		//Wrong choice
		else
		{
		   cout << "Invalid choice"<<endl;
		   cout << "________________________________________________________________________________________________________________________" << endl;
        }
	}
	//_________________________________________________________________________________________
	//The End
		cout << "                                          Thanks for using the market !" << endl;
		cout << "                                          _____________________________" << endl;
}
