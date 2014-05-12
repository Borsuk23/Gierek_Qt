#ifndef COALDEPOSIT_H
#define COALDEPOSIT_H

#include "Client.h"
class CoalDeposit: public Client
{
public:
	CoalDeposit();
    CoalDeposit(int _difficulty);
    Order* MakeOrder(int _date);
};

#endif //COALDEPOSIT_H
