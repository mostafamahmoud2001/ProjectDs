#include "Seller.h"
#include<iostream>
using namespace std;
int Seller::SellerNum = 0;

Seller::Seller(string name, string email, string password)
{
	this->email = email;
	this->id = SellerNum + 1001;
	this->name = name;
	this->password = password;
	SellerNum++;
}
