#include<iostream>
#include <vector>
#include "Customer.h"
#include  "Product.h"
using namespace std;
int Customer::CustomerNum = 0;
Customer::Customer(string n, string email, string password, string pn, string add)
{
	id = CustomerNum + 1001;
	name = n;
	this->email = email;
	this->phoneNumber = pn;
	this->address = add;
	this->password = password;
	CustomerNum++;
}
int Customer::getID()
{
	return this->id;
}
string Customer::getPass()
{
	return password;
}
string Customer::getname()
{
	return name;
}
string Customer::getaddress()
{
	return address;
}
string Customer::getemail()
{
	return email;
}
//Done
int Customer::mainMenuCustomer()
{

	int choose;
	cout << "Hello : " << getname() <<endl;
	cout << "_____________" << endl;
	cout << "1- Search by category " << endl;
	cout << "2- Search by name of product " << endl;
	cout << "3- Display the total price " << endl;
	cout << "4- Display all receipt " << endl;
	cout << "5- Logout" << endl;
	cout << "Your choice : ";
	while (true) 
	{
		cin >> choose;
		if (choose == 1 || choose == 2 || choose == 3 || choose == 4 || choose == 5 )
			return choose;
		else
			cout << "Enter valid number : " ;
	}
	cout << "________________________________________________________________________________________________________________________" << endl;
	return choose;
}
//Done
void Customer::browseByCategory(vector<Product>&v1 )
{
	cout << endl << "________________________________________________________________________________________________________________________" << endl;
	cout << "                                             *______ Categories ______*"<<endl;
	int  inp; 
	string inp2;
	int inp3 = 0;
	int x = 1;
	string cat;
	cout << "1- Mobile"<<endl<<"2- Tv"<<endl<<"3- Labtop" << endl;
	
		cout << "Your choice : ";
		cin >> inp;
		switch (inp)
		{
		case 1:
			cat = "mobile";
			break;
		case 2:
			cat = "tv";
			break;
		case 3:
			cat = "labtop";
			break;
		}
	cout << endl << "________________________________________________________________________________________________________________________" << endl;
	for (int i = 0; i < v1.size(); i++)
	{
		if (v1[i].getcategory() == cat)
		{
			cout << "          Product ("<<x<<")"<<endl;
			
			cout  <<"Name : "<< v1[i].getname() << endl;
			cout  << "Rate : " << v1[i].rate << endl;
			cout  << "Price : "<<v1[i].getprice() << endl;
			cout << "_________________________________" << endl;
			x++;
		}
	}
	cout << endl << "Enter product name to buy and no to exit : ";
	int quan;
	cin >> inp2;
	if (inp2 == "no")
		return;
	cout << "Enter the quantity you want : ";
	cin >> quan;
	for (int v = 0; v < v1.size(); v++)
	{
		if (v1[v].getname() == inp2)
		{
			while (1)
			{
				if (v1[v].getquantity() >= quan)
					break;
				cout << "This quantity is not avilable, Enter new quantity or enter (0) to go back : ";
				cin >> quan;
			}
			if (!quan)
			   break;
			cout << endl << "________________________________________________________________________________________________________________________" << endl;
			this->cart.push_back(v1[v].getid());
			this->quantity.push_back(quan);
			v1[v].setquantity(v1[v].getquantity() - quan);
			break;
		}
	}
}
//Done
void Customer::browseByName(vector<Product>& v1)
{
	int num;
	string namep;
	cout << "Enter the product name : " ;
	cin >> namep;
	int q;
	cout << "Enter the quantity : ";
	cin >> q;

	bool y=false ;
	for (int i = 0; i < v1.size(); i++)
	{
		if (v1[i].getname() == namep)
		{
			y = true;
			cout << endl << "________________________________________________________________________________________________________________________" << endl;
			cout << "    ______ Available products _______" << endl<<endl;
			cout << "Name : "<< v1[i].getname() << endl;
			cout << "Rate : " << v1[i].rate << endl;
			cout << "Price : " << v1[i].getprice() << endl;
			cout  << "________________________________________" << endl;
			cout << "1- Buy"<<endl;
			cout << "2- Go back to the menu"<<endl;
			cout << "3- Search again"<<endl;
			cout << "Your choice : ";
			cin >> num;
			if (num == 1)
			{
				this->cart.push_back(v1[i].getid());
				quantity.push_back(q);
				cout  << "________________________________________________________________________________________________________________________" << endl;
				break;
			}
			else if (num == 2)
			{
				cout  << "________________________________________________________________________________________________________________________" << endl;
				break;
			}
			else if (num == 3)
			{
				browseByName(v1);
				break;
			}
		}
	}
	if (y == false)
	{
		cout<<"The product is not available";
		cout << endl << "________________________________________________________________________________________________________________________" << endl;
	}

}
//Done
float Customer::cal_rate(vector<int> v)
{
	float sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		sum += v[i];
	}
	float rate = (sum) / (v.size());
	return rate;
}
//Done
void Customer::rate_product(vector<Product> & p, vector<int> id)
{
	int rate;
	int choice;
	int id_val;
	for (int i = 0; i < id.size(); i++)
	{
		id_val = Product::getIndex(id[i],p);
		rate = 0;
		cout << "Press 1 to rate " << p[id_val].getname() << " and 2 to skip : ";
		//validation for choice
		for (; true;)
		{
			cin >> choice;
			if (choice == 1 || choice == 2)
				break;
			else
				cout << "Enter valid choice : ";
		}
		if (choice == 1)
		{
			cout << "Enter rate for " << p[id_val].getname() << " (0 to 10) : ";
			//validation for rate
			for (; true;)
			{
				cin >> rate;
				if (rate >= 0 && rate <= 10)
				{
					p[id_val].rates.push_back(rate);
					p[id_val].rate = cal_rate(p[id_val].rates);
					break;
				}
				else
					cout << "please enter valid rate : ";
			}
			cout << "_____________________________________" << endl;
		}
		else if (choice == 2)
		{
			cout <<  "_____________________________________" << endl;
		}
	}
}
//Done
void Customer::sort_product(vector<Product> &p)
{
	for (int i = 0; i < p.size(); i++)
	{
		for (int j = i + 1; j < p.size(); j++)
		{
			if (p[i].rate < p[j].rate)
			{
				swap(p[i], p[j]);
			}
		}
	}
}
//Done
void Customer::display_total(vector<int> &cart , vector<Product> &p)
{
	if (cart.size() == 0)
	{
		cout << "Your cart is empty !" << endl;
		return;
	}
	float total = 0;
	for (int i = 0; i < cart.size(); i++)
	{
		int j = Product::getIndex(cart[i],p);
				total += p[j].getprice() * quantity[i];
	}
	cout << "The total price is : " << total;
	cout << endl << "_____________________________________" << endl;
	cout << "If you want to confirm "<<endl;
	cout << "1- Yes"<<endl;
	cout << "2- No"<<endl;
	int s;
	cout << "Your choice : ";
	cin >> s ;
	if (s == 1)
	{
		cout << "*Confirmation successful*";
		cout << endl << "_____________________________________" << endl;
		this->receipt.push_back(Receipt::storeReceipt(cart, p, quantity, this->getID()));
		cout << "If you want to rate the product " << endl;
		cout << "1- Yes" << endl;
		cout << "2- No" << endl;
		int t;
		cout << "Your choice : ";
		cin >> t;
		if (t == 1)
			rate_product(p, cart);
		cart.clear();
		quantity.clear();
		cout << "If you want to display the receipt " << endl;
		cout << "1- Yes" << endl;
		cout << "2- No" << endl;
		cout << "Your choice : ";
		cin >> s;
		cout  << "_____________________________________" << endl;
		if (s == 1)
		{
			receipt[receipt.size() - 1].showReciept(p);
			cout << endl;
		}
		else
			return;
	}
	else
	{
		cout << endl << "________________________________________________________________________________________________________________________";
		return;
	}
}
//Done
void Customer::display_allreceipt(vector<Product>p)
{
	cout  << "________________________________________________________________________________________________________________________";
	cout << "                                              *_____ All receipts _____*"<<endl;
	for (int i = 0; i < receipt.size(); i++)
	{
		cout << "Receipt (" << i + 1<<")" << endl;
		cout << "____________" << endl;
		receipt[i].showReciept(p);
	}
}
