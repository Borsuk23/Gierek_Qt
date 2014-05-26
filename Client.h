#ifndef CLIENT_H
#define CLIENT_H

#include "CommonIncludes.h"
#include "Order.h"

class Client
{
protected:
    QString name;
    Order *averageOrder;
public:
    Client();
    Client(int _difficulty);
    virtual Order* MakeOrder(int _date) {return NULL;}
    QString GetName();
};

#endif //CLIENT_H
