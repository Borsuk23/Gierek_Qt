#pragma once
#include "Client.h"
class CoalDeposit: public Client
{
public:
	CoalDeposit();
	Order MakeOrder();
};

