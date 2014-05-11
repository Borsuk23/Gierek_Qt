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

};

