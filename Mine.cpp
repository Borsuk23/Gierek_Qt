#include "pch.h"
#include "Mine.h"


Mine::Mine()
{
}


void Mine::PaySalary()
{
	this->budget -= miners.size()*salary;
	if (budget < 0)
	{
		budget = 0;
		//endgame!
	}
}

void Mine::CheckCrew()
{
	for (std::vector<Miner>::iterator worker = miners.begin(); worker != miners.end(); ++worker)
	{
		if (!worker->Dismissal())
		{
			miners.erase(worker);
		}
	}
}

void Mine::MineCoal()
{
	CoalTypeA *coalA = new CoalTypeA();
	CoalTypeB *coalB = new CoalTypeB();
	for (Miner worker : miners)
	{
		if (coalA->amount < extractCoalA.amount)
		{
			worker.MineCoal(*coalA);

		}
		else
		{
			worker.MineCoal(*coalB);
		}
	}
	Order *newOrder = new Order();
	if (coalA->amount > sellCoalA.amount)
	{

	}
}