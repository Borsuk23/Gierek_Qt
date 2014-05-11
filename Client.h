#ifndef CLIENT_H
#define CLIENT_H

#include "CommonIncludes.h"
#include "Order.h"

class Client
{
public:
    QString name;
    Order *avarageOrder;
public:
    Client();
    Order MakeOrder();
    QString GetName();
};

#endif //CLIENT_H
