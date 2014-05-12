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
    Storehouse(int _difficulty);
    CoalTypeA* StoreCoal(CoalTypeA *_coalA);
    CoalTypeB* StoreCoal(CoalTypeB *_coalB);
    CoalTypeA* TakeCoal(CoalTypeA *_coalA);
    CoalTypeB* TakeCoal(CoalTypeB *_coalB);
	double GetStorageCost();
    double ExtendStorage(CoalTypeA const *_coalA, double _budget);
    double ExtendStorage(CoalTypeB const *_coalB, double _budget);
    double GetStorageAmount(CoalTypeA const *_coal);
    double GetStorageAmount(CoalTypeB const *_coal);
    double GetStoredCoal(CoalTypeA const *_coal);
    double GetStoredCoal(CoalTypeB const *_coal);
};

