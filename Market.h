#ifndef MARKET_H
#define MARKET_H


#include "Client.h"
#include "Order.h"
#include <QVector>

class Market
{
public:
    QVector<Client*> clients;
    QVector<Order*> orderList;
    QVector<Order*> offerList;
public:
    Market();
    Market(int _difficulty);
	void AddOrder(Order *newOrder);
	Order AccomplishTransaction(Order *offer);
};

#endif //MARKET_H
