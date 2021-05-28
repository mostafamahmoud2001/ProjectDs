#pragma once
#include <string>
using namespace std;
class Receipt
{
public:
	int id;
	string Products_names;
	int amount_of_each_product;
	int Customer_ID;
	float total_price;
	float Shipment_price = 30;
	vector<Product> pro;
	Receipt();
	void display_receipt(vector<int> cart, vector<Product> p, vector<Receipt> &r);
};

