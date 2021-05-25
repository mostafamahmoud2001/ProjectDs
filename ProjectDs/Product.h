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
	int rate;
	vector<int>allRate;
public :
	static int productNum;
	Product(string name, string category, float price, int sellerId);
};

