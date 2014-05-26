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
    Order *stats;
public:
    Market();
    QList<Order*> GetOrdersList();
    QList<Order*> GetOffersList();
    void AddOrder(Order *_order);
    void AddOffer(Order *_offer);
    Order* AccomplishTransaction(Order *offer);
    Order* GetStats();
};

#endif //MARKET_H
