#ifndef COALDEPOSIT_H
#define COALDEPOSIT_H

#include "Client.h"
class CoalDeposit: public Client
{
public:
	CoalDeposit();
    Order MakeOrder();
};

#endif //COALDEPOSIT_H
