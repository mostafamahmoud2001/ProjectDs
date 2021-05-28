#pragma once
#include "Product.h"
class receipt
{
	int id;
	int customer_id;
	float total_price ;
	int shipment_price;
	vector <Product> receipts;
};

