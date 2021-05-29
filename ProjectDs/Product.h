#pragma once
#include <iostream>
#include <string>
#include<vector>
using namespace std;
class Product
{
	int id;
	string name;
	float price;
	string category;
	int sellerId;
	int quantity;
public:
	float rate;
	vector<int>rates;
	static int productNum;
	Product(string name, string category, float price, int sellerId, int quantity);
	string getcategory();
	string getname();
	int getid();
	float getprice();
	int getquantity();
	void setquantity(int);
	static int getIndex(int, vector<Product>p);
};
