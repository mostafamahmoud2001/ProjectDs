#include "Receipt.h"
#include<string>
#include <iostream>
#include <vector>
#include "Product.h"
using namespace std;
int Receipt::numID = 0;
float Receipt::Shipment_price = 30.0;
Receipt::Receipt()
{
	Customer_ID = 0;
	id = 0;
	total_price = 0;
	numID++;
}
Receipt Receipt::storeReceipt(vector<int> cart, vector<Product>p, vector<int> q, int cusID)
{
	Receipt tempReceipt;
	float total = 0;
	for (int i = 0; i < cart.size(); i++)
	{
		int index = Product::getIndex(cart[i], p);
		p[index].setquantity(q[i]);
		total += p[index].getprice() * p[index].getquantity();
		tempReceipt.pro.push_back(p[index]);
	}
	tempReceipt.id = numID;
	tempReceipt.Customer_ID = cusID;
	tempReceipt.total_price = total + Shipment_price;
	return tempReceipt;
}
void Receipt::showReciept(vector <Product> p)
{
	cout << "Recipt ID : " << this->id << endl;
	cout << "Customer ID : " << this->Customer_ID << endl;
	cout << "All product : " << endl;
	for (int i = 0; i < pro.size(); i++)
	{
		int index = Product::getIndex(pro[i].getid(), p);
		cout << "Product ("<<i + 1<<")"<<endl;
	    cout<< "Name :" << pro[i].getname() << endl;
		cout << "Quantity of product is " << pro[i].getquantity() << endl;
		cout << "Rate of product is " << p[index].rate << endl;
		cout << "The price of the product is " << pro[i].getprice() << endl;
		cout << "_________________________________" << endl;
	}
	cout << "Total Price with shipment is " << total_price << endl;
	cout << "________________________________________________________________________________________________________________________" << endl;
}