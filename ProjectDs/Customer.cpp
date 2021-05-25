#include "Customer.h"
int Customer::CustomerNum = 0;
Customer::Customer(string n, string email, string password, int pn, string add)
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
	cout << "Enter number : ";
	while (true) {
		cin >> choose;
		if (choose == 1 || choose == 2)
			return choose;
		else
			cout << "Enter valid number!" << endl;
	}
	return choose;
}

void Customer::browseByCategory()
{
	cout << "category";
}

void Customer::browseByName()
{
	cout << "Search name";
}

