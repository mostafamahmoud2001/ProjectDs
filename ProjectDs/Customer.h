#pragma once
#include <iostream>
#include <string>
using namespace std;
class Customer
{
	
	int id;
	string address;
	int phoneNumber;
	string email;
	string password;
	string name;
public:
	static int CustomerNum;
	Customer(string name , string email, string password, int pn , string add);
	int getID();
	string getPass();
	string getname();
	string getaddress();
	string getemail();
	int mainMenuCustomer();
	void browseByCategory();
	void browseByName();
};

