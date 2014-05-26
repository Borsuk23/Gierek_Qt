#pragma once
#include "Client.h"
class PowerStation: public Client
{
public:
	PowerStation();
    PowerStation(int _difficulty);
    Order* MakeOrder(int _date);
};

