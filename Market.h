#ifndef MARKET_H
#define MARKET_H


#include "Client.h"
#include "Order.h"
#include <QVector>

class Market
{
private:
    QList<Order*> orderList;
    QList<Order*> offerList;
public:
    Market();
    void AddOrder(Order *_order);
    void AddOffer(Order *_offer);
    Order* AccomplishTransaction(Order *offer);
};

#endif //MARKET_H
