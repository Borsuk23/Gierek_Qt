#include "pch.h"
#include "Storehouse.h"


Storehouse::Storehouse()
{
	this->coalA = new CoalTypeA();
	this->coalB = new CoalTypeB();
	this->storageA = new CoalTypeA(50000, 0);
	this->storageB = new CoalTypeB(30000, 0);
	this->cost = 10;
}

double Storehouse::GetStorageCost()
{
	double amount = 0;
	amount += coalA->amount;
	amount += coalB->amount;
	return cost*amount;
}

bool Storehouse::ExtendStorage(CoalTypeA const *coalA, double budget)
{
	if (budget > 10000)
	{
		budget -= 10000;
		storageA->amount += 10000;
		return true;
	}
	else
		return false;
}

bool Storehouse::ExtendStorage(CoalTypeB const *coalB, double budget)
{
	if (budget > 10000)
	{
		budget -= 10000;
		storageB->amount += 10000;
		return true;
	}
	else
		return false;
}

CoalTypeA* Storehouse::StoreCoal(CoalTypeA *coalA)
{
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
}

CoalTypeB* Storehouse::StoreCoal(CoalTypeB *coalB)
{
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
}

CoalTypeA* Storehouse::TakeCoal(CoalTypeA *coalA)
{
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
}

CoalTypeB* Storehouse::TakeCoal(CoalTypeB *coalB)
{
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
}
