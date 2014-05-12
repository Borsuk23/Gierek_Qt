#ifndef CLIENT_H
#define CLIENT_H

#include "CommonIncludes.h"
#include "Order.h"

class Client
{
protected:
    QString name;
    Order *avarageOrder;
public:
    Client();
    Client(int _difficulty);
    Order* MakeOrder(int _date);
    QString GetName();
};

#endif //CLIENT_H
