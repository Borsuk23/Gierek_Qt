#pragma once
#include "Client.h"
class HeatingPlant: Client
{
public:
	HeatingPlant();
    HeatingPlant(int _difficulty);
    Order* MakeOrder(int _date);
};

