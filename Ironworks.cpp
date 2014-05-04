#include "pch.h"
#include "Ironworks.h"
#include "CoalTypeA.h"
#include "CoalTypeB.h"


Ironworks::Ironworks()
{
	name = "Huta";
	CoalTypeA *typeA = new CoalTypeA((1+ (rand() % 30 - 15) / 100) * 10000, 600);
	CoalTypeB *typeB = new CoalTypeB((1 + (rand() % 30 - 15) / 100) * 10000, 600);
	avarageOrder = new Order(typeA, typeB);
	delete typeA;
	delete typeB;
}

Order Ironworks::MakeOrder()
{
	Order *newOrder = new Order();

	//no market factors involved!
	//order based on random modification of avarage order 
	newOrder->coalA->amount = ((rand() % 20 - 10) / 100 + 1)*avarageOrder->coalA->amount;
	newOrder->coalA->price = avarageOrder->coalA->price;
	newOrder->coalB->amount = ((rand() % 20 - 10) / 100 + 1)*avarageOrder->coalB->amount;
	newOrder->coalB->price = avarageOrder->coalB->price;

	return *newOrder;
}