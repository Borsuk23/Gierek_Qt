#pragma once
#include "Client.h"
class Ironworks: Client
{
public:
	Ironworks();
    Ironworks(int _difficulty);
    Order* MakeOrder(int _date);
};

