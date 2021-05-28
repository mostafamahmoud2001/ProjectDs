#include "Receipt.h"
#include <iostream>
#include<string>
#include <vector>
#include "Product.h"
using namespace std;
Receipt::Receipt()
{
	this->Shipment_price = 30;
}
void Receipt::display_receipt(vector<int> cart , vector<Product> p , vector<Receipt> &r)
{
	Receipt re;
	r.push_back(re);
	for (int i = 0; i < cart.size(); i++)
	{
		int j = cart[i] - 100001;
		re.pro.push_back(p[j]);
	}

}
