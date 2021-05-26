#pragma once
#include <iostream>
#include <string>
#include  "Product.h"
#include<vector>
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
	vector<int>cart;
	static int CustomerNum;
	Customer(string name , string email, string password, int pn , string add);
	int getID();
	string getPass();
	string getname();
	string getaddress();
	string getemail();
	int mainMenuCustomer();
	void browseByCategory( vector<Product>& v1);
	void browseByName(vector<Product>& v1);
	float cal_rate(vector<int> v);
	void rate_product(vector<Product> p, vector<int> id);
	void sort_product(vector<Product> p);
};

