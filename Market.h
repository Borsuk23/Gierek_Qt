#pragma once
#include "Order.h"
class Market
{
public:
	std::vector<Order> orderList;
	std::vector<Order> offerList;
public:
	Market();
	void AddOrder(Order *newOrder);
	Order AccomplishTransaction(Order *offer);
};

