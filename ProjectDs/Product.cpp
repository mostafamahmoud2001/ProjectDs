#include "Product.h"
int Product::productNum = 0;
Product::Product(string name, string category, float price, int sellerId)
{
	this->name = name;
	this->category = category;
	this->price = price;
	this->sellerId = sellerId;
	id = productNum + 100001;
}
