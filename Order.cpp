#include "Order.h"

Order::Order()
{
    this->coalA = new CoalTypeA();
    this->coalB = new CoalTypeB();
}
Order::Order(CoalTypeA *_coalA, CoalTypeB *_coalB)
{
    this->coalA = new CoalTypeA(_coalA->GetAmount(),_coalA->GetPrice());
    this->coalB = new CoalTypeB(_coalB->GetAmount(),_coalB->GetPrice());
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
