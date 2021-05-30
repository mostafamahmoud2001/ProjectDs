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
	cout << endl << "What category do you want to add your product in ?"<<endl<< "1- TV  "<<endl<<"2- Laptop"<<endl<< "3- Mobile"<<endl;
	cout << "Your choice : ";
		while (1)
		{
			cin >> temp;
			if (temp >= 1 && temp <= 3)
				break;
			cout << "Invalid choice : ";
		}
	switch (temp)
	{
	case 1 :
		category = "tv";
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
	cout << "Enter product name : ";
	cin >> name;
	cout  << "Enter price : ";
	cin >> price;
	cout  << "Enter quantity : ";
	cin >> quantity;
	Product p(name, category, price, sellerId,quantity);
	cout << "You added the product successfully!"<<endl;
	cout  << "________________________________________________________________________________________________________________________" << endl;
	return p;
}
int Seller::mainMenuSeller()
{
	int choice = -1;
	cout << "1- Add product " << endl;
	cout << "2- Logout"<<endl;
	cout << "Your choice : ";
		while (1) 
		{
			cin >> choice;
			if (choice == 1 || choice == 2)
				break;
			cout << "Invalid choice : " ;
		}
	return choice;
}
string Seller::getName()
{
	return name;
}
