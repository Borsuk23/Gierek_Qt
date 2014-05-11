#include "Order.h"

Order::Order()
{
    this->coalA = 0;
    this->coalB = 0;
}
Order::Order(CoalTypeA *coalA, CoalTypeB *coalB)
{
	this->coalA = coalA;
	this->coalB = coalB;
}
