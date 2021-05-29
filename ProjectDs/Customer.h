#pragma once
#include <iostream>
#include <string>
#include "Product.h"
#include<vector>
#include "Receipt.h"

using namespace std;
class Customer
{
	int id;
	string address;
	string phoneNumber;
	string email;
	string password;
	string name;
	vector <Receipt> receipt;
public:
	vector<int>quantity;
	vector<int>cart;
	static int CustomerNum;
	Customer(string name , string email, string password, string pn , string add);
	int getID();
	string getPass();
	string getname();
	string getaddress();
	string getemail();
	int mainMenuCustomer();
	void browseByCategory( vector<Product>& v1);
	void browseByName(vector<Product>& v1);
	float cal_rate(vector<int> v);
	void rate_product(vector<Product> &p, vector<int> id);
	void sort_product(vector<Product>& p);
	void display_total(vector<int> &cart , vector<Product> &p);
	void display_allreceipt(vector<Product>p);
};

