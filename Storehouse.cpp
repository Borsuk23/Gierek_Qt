#include "Storehouse.h"


Storehouse::Storehouse()
{
	this->coalA = new CoalTypeA();
	this->coalB = new CoalTypeB();
	this->storageA = new CoalTypeA(50000, 0);
	this->storageB = new CoalTypeB(30000, 0);
    this->cost = 5;
}

Storehouse::Storehouse(int _difficulty)
{

}

CoalTypeA* Storehouse::StoreCoal(CoalTypeA *coalA)
{/*
    if (coalA->amount <= (storageA->amount - this->coalA->amount))
    {
        this->coalA->amount += coalA->amount;
        return nullptr;
    }
    else
    {
        this->coalA->amount = storageA->amount;
        coalA->amount -= (storageA->amount - this->coalA->amount);
        return coalA;
    }
    */return coalA;
}

CoalTypeB* Storehouse::StoreCoal(CoalTypeB *coalB)
{
    /*
    if (coalB->amount <= (storageB->amount - this->coalB->amount))
    {
        this->coalB->amount += coalB->amount;
        return nullptr;
    }
    else
    {
        this->coalB->amount = storageB->amount;
        coalB->amount -= (storageB->amount - this->coalB->amount);
        return coalB;
    }
    */return coalB;
}

CoalTypeA* Storehouse::TakeCoal(CoalTypeA *coalA)
{
    /*
    if (coalA->amount < this->coalA->amount)
    {
        this->coalA->amount -= coalA->amount;
        return coalA;
    }
    else
    {
        coalA->amount = this->coalA->amount;
        this->coalA->amount = 0;
        return coalA;
    }
    */return coalA;
}

CoalTypeB* Storehouse::TakeCoal(CoalTypeB *coalB)
{/*
    if (coalB->amount < this->coalB->amount)
    {
        this->coalB->amount -= coalB->amount;
        return coalB;
    }
    else
    {
        coalB->amount = this->coalB->amount;
        this->coalB->amount = 0;
        return coalB;
    }
    */return coalB;
}

double Storehouse::GetStorageCost()
{
	double amount = 0;
    amount += coalA->GetAmount();
    amount += coalB->GetAmount();
    return this->cost*amount;
}

double Storehouse::ExtendStorage(CoalTypeA const *_coalA, double _budget)
{
    if (_budget > 10000)
    {
        _budget -= 10000;
        storageA->Add(10000);
        return _budget;
    }
    else
        return _budget;
}

double Storehouse::ExtendStorage(CoalTypeB const *_coalB, double _budget)
{
    if (_budget > 10000)
    {
        _budget -= 10000;
        storageB->Add(10000);
        return _budget;
    }
    else
        return _budget;
}

double Storehouse::GetStorageAmount(CoalTypeA const *_coal)
{
    return this->storageA->GetAmount();
}

double Storehouse::GetStorageAmount(CoalTypeB const *_coal)
{
    return this->storageB->GetAmount();
}

double Storehouse::GetStoredCoal(CoalTypeA const *_coal)
{
    return this->coalA->GetAmount();
}

double Storehouse::GetStoredCoal(CoalTypeB const *_coal)
{
    return this->coalB->GetAmount();
}
