#include "Order.h"

Order::Order()
{
    this->coalA = new CoalTypeA();
    this->coalB = new CoalTypeB();
}
Order::Order(CoalTypeA *coalA, CoalTypeB *coalB)
{
	this->coalA = coalA;
	this->coalB = coalB;
}

CoalTypeA* Order::GetCoalA()
{
    return this->coalA;
}

CoalTypeB* Order::GetCoalB()
{
    return this->coalB;
}

void Order::SetCoalA(CoalTypeA *_coal)
{
    this->coalA=_coal;
}

void Order::SetCoalB(CoalTypeB *_coal)
{
    this->coalB=_coal;
}
