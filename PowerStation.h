#pragma once
#include "Client.h"
class PowerStation: Client
{
public:
	PowerStation();
    PowerStation(int _difficulty);
    Order* MakeOrder(int _date);
};

