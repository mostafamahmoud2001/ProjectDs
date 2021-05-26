#pragma once
#include <iostream>
#include <string>
using namespace std;
class Seller{
	int id;
	string name;
	string email;
	string password;
public :
	Seller(string name, string email, string password);
	static int SellerNum;
	string getName();
	string getPass();
};