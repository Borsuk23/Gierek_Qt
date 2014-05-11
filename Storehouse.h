#pragma once
#include "CoalTypeA.h"
#include "CoalTypeB.h"
class Storehouse
{
private:
	double cost;
	CoalTypeA *storageA;
	CoalTypeB *storageB;
	CoalTypeA *coalA;
	CoalTypeB *coalB;
public:
	Storehouse();
	CoalTypeA* StoreCoal(CoalTypeA *coalA);
	CoalTypeB* StoreCoal(CoalTypeB *coalB);
	CoalTypeA* TakeCoal(CoalTypeA *coalA);
	CoalTypeB* TakeCoal(CoalTypeB *coalB);
	double GetStorageCost();
	bool ExtendStorage(CoalTypeA const *coalA, double budget);
	bool ExtendStorage(CoalTypeB const *coalB, double budget);
};

