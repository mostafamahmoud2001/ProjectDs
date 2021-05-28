#include "Seller.h"
#include<iostream>
using namespace std;
int Seller::SellerNum = 0;
string Seller::getemail()
{
	return email;
}
Seller::Seller(string name, string email, string password)
{
	this->email = email;
	this->id = SellerNum + 1001;
	this->name = name;
	this->password = password;
	SellerNum++;
}
string Seller::getPass()
{
	return password;
}
Product Seller::addProduct()
{
	string name;
	float price;
	string category;
	int sellerId = this->id , temp;
	int quantity;
	cout << "Enter product name : ";
	cin >> name;
	cout << endl << "Enter product category :"<<endl<< "1 - book  "<<endl<<"2 - laptop"<<endl<< "3 - mobile"<<endl;
		while (1)
		{
			cin >> temp;
			if (temp >= 1 && temp <= 3)
				break;
			cout << "Invalid number"<<endl;
		}
	switch (temp)
	{
	case 1 :
		category = "book";
		break;
	case 2 :
		category = "laptop";
		break;
	case 3 :
		category = "mobile";
		break;
	default:
		break;
	}
	cout << endl << "Enter price : ";
	cin >> price;
	cout << endl << "Enter Quantity : ";
	cin >> quantity;
	Product p(name, category, price, sellerId,quantity);
	return p;
}
int Seller::mainMenuSeller()
{
	int choice = -1;
	cout << "1 - Add product " << endl;
	cout << "2 - logout"<<endl;
		while (1) {
			cin >> choice;
			if (choice == 1 || choice == 2)
				break;
			cout << "Invalid number" << endl;
		}
	return choice;
}
string Seller::getName()
{
	return name;
}
