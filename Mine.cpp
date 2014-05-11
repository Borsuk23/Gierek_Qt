#include "Mine.h"
#include "CommonIncludes.h"


Mine::Mine()
{
    this->name="moja kopalnia";
    this->salary=1000;
    this->budget=100000;
    this->storage= new Storehouse();
    this->extractCoalA = new CoalTypeA();
    this->extractCoalB = new CoalTypeB();
    this->sellCoalA = new CoalTypeA();
    this->sellCoalB = new CoalTypeB();

    for(int i=0; i<60;i++)
    {
       this->miners.push_back(new Miner());
    }

}


void Mine::PaySalary()
{/*
	this->budget -= miners.size()*salary;
	if (budget < 0)
	{
		budget = 0;
		//endgame!
	}
    */
}

void Mine::CheckCrew()
{
    /*for (std::vector<Miner>::iterator worker = miners.begin(); worker != miners.end(); ++worker)
	{
		if (!worker->Dismissal())
		{
			miners.erase(worker);
		}
	}
    */
}

void Mine::MineCoal()
{
    /*
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
    */
}
