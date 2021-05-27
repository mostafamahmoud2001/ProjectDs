#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Product.h"
#include <queue>
using namespace std;
class Admin
{
	string name;
	string email;
	string password;
	queue<Product>WaitedProduct;
public :
	Admin(string, string, string);
	string getname();
	string getpassword();
	string getEmail();
	void pushToWaited(Product p);
	void viewWaitedProduct(vector<Product>& productes);
	int AdminMainMenu();
};

