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
int Customer::mainMenuCustomer()
{
	int choose;
	cout << "Hello : " << getname() << endl;
	cout << "1 - search by category " << endl;
	cout << "2 - search by name of product " << endl;
	cout << "3 - display the total price " << endl;
	cout << "4 - logout" << endl;
	cout << "Enter number : ";
	while (true) {
		cin >> choose;
		if (choose == 1 || choose == 2 || choose == 3 || choose == 4)
			return choose;
		else
			cout << "Enter valid number!" << endl;
	}
	return choose;
}
void Customer::browseByCategory(vector<Product>&v1 )
{
	cout << "category";

	//Customer b("mkmksd", "email", " password", 5, " add");
	//b.card.push_back(v1[0].id);

	int  inp;
	string inp2;
	int inp3 = 0;
	int x = 1;
	string cat;
	cout << "there are all categories if u want eny of these ples enter name of  1,2,3 or 4" << endl;
	cout << "1: mobile" << endl << "2: book" << endl << "3: labtop" << endl;

	cin >> inp;
	switch (inp)
	{
	case 1:
		cat = "mobile";
		break;
	case 2:
		cat = "book";
		break;
	case 3:
		cat = "labtop";
		break;

	default:
		break;
	}
	for (int i = 0; i < v1.size(); i++)
	{
		if (v1[i].getcategory() == cat)
		{
			cout << x << "::" << v1[i].getname() << endl;
			x++;
		}
	}
	cout << endl << " if u want buy enything of these  press 1,2,3,4,5 pleas " << endl;
	//customers[i].card[0] = v1[0].id;

	cin >> inp2;
	for (int v = 0; v < v1.size(); v++)
	{

		if (v1[v].getname() == inp2)
		{
			this->cart.push_back(v1[v].getid());
			break;
		}

	}
}
void Customer::browseByName(vector<Product>& v1)
{
	int num;
	string namep;
	cout << "enter name of  product's want :: " ;
	cin >> namep;
	bool y=false ;
	for (int i = 0; i < v1.size(); i++)
	{
		if (v1[i].getname() == namep)
		{


			y = true;
			cout << "this product esast do you want buy " << v1[i].getname() << "press eny of these num " << endl;
			cout << "1 :: take " << endl << "2 :: logout " << endl << "3 ::go to search again" << endl;
			cin >> num;
			if (num == 1)
			{
				this->cart.push_back(v1[i].getid());
				cout << "done" << endl;
				break;
			}
			else if (num == 2)
			{
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
		cout << endl << endl << endl << "didnt esast :(" << endl;
	}

}
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
void Customer::rate_product(vector<Product> p, vector<int> id)
{
	int rate;
	int choice;
	int id_val;
	for (int i = 0; i < id.size(); i++)
	{
		id_val = id[i];
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
			cout << "----------------------------------" << endl;
		}
		else if (choice == 2)
		{
			cout << "----------------------------------" << endl;
		}
	}
}
void Customer::sort_product(vector<Product> p)
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

void Customer::display_total(vector<int> &cart , vector<Product> &p)
{
		float total = 0;
		cout << cart.size() << endl;
		for (int i = 0; i < cart.size(); i++)
		{
			int j = cart[i] - 100001;
					total += p[j].getprice();
					cout << p[j].getname() << endl;
					cout << i << endl;
		}
		cout << "The total price is : " << total << endl;
}

void Customer::display_rates(vector<Product>& rate)
{
int	x = 1;

	for (int i = 0; i < rate.size(); i++)
	{
		

		cout << x << " :: rate of " << rate[i].getname() << " is ---> " << rate[i].rate << " quantety is ---> " << rate[i].getquantity() << endl;
		cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- "<< endl;



	}

}
