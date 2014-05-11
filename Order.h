#pragma once
#include "CoalTypeA.h"
#include "CoalTypeB.h"

class Order
{
private:
    CoalTypeA *coalA;
    CoalTypeB *coalB;

public:
	Order();
	Order(CoalTypeA *coalA, CoalTypeB *coalB);
    CoalTypeA* GetCoalA();
    CoalTypeB* GetCoalB();
    void SetCoalA(CoalTypeA *_coal);
    void SetCoalB(CoalTypeB *_coal);

};

