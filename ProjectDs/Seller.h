#pragma once
#include <iostream>
#include <string>
#include "Product.h"
using namespace std;
class Seller{
	int id;
	string name;
	string email;
	string password;
public :
	string getemail();
	Seller(string name, string email, string password);
	static int SellerNum;
	string getName();
	string getPass();
	Product addProduct();
	int mainMenuSeller();
};