#include "Product.h"
int Product::productNum = 0;
Product::Product(string name, string category, float price, int sellerId , int quantity)
{
	this->name = name;
	this->category = category;
	this->price = price;
	this->sellerId = sellerId;
	this->quantity = quantity;
	id = productNum + 100001;
	productNum++;
}
string Product::getcategory()
{
	return category;
}
string Product::getname()
{
	return name;
}
int Product::getid()
{
	return id;
}
float Product::getprice()
{
	return price;
}
int Product::getquantity()
{
	return quantity;
}
void Product::setquantity(int q)
{
	this->quantity = q;
}
int Product::getIndex(int id ,vector<Product>p)
{
	for (int i = 0; i < p.size(); i++)
	{
		if (p[i].getid() == id)
			return i;
	}
	return -1;
}
