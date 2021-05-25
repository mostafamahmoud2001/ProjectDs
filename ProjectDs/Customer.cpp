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
