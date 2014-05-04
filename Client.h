#pragma once
#include "Order.h"
class Client
{
public:
	std::string name;
	Order *avarageOrder;
public:
	Client();
	Order MakeOrder();
};

