#include <iostream>
#include <vector>
#include<string>
#include"Customer.h"
using namespace std;
int main()
{
	vector<Customer> customers;
	Customer c1("mostafa", "mostafa@gmail.com","12345", 01211542545, "zsd");
	Customer c2("magdy", "magdy@gmail.com", "123445",154257575572, "zsdd");
	customers.push_back(c1);
	customers.push_back(c2);
}
