#pragma once
#include <string>
#include<vector>
#include"Product.h"
using namespace std;
class Receipt
{
public:
	static int numID;
	int id;
	int Customer_ID;
	float total_price;
	static float Shipment_price;
	vector<Product> pro;
public:
	Receipt();
	static Receipt storeReceipt(vector<int> cart, vector<Product> p, vector<int> q, int cusID);
	void showReciept(vector <Product> p);

};
