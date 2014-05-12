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
Mine::Mine(int _difficulty)
{

}

QString Mine::GetName()
{
    return this->name;
}

double Mine::GetBudget()
{
    return this->budget;
}

double Mine::GetCurrentSalary()
{
    return this->salary;
}

double Mine::GetOverallSalary()
{
    return (this->miners.count()*this->salary);
}

void Mine::SetSalary(double _salary)
{
    this->salary=_salary;
}

QList<Miner*> Mine::GetMiners()
{
    return this->miners;
}

Storehouse* Mine::GetStorehouse()
{
    return this->storage;
}

void Mine::SetCoalAExtraction(double _amount)
{
    this->extractCoalA->SetAmount(_amount);
}

void Mine::SetCoalBExtraction(double _amount)
{
    this->extractCoalB->SetAmount(_amount);
}

void Mine::SetCoalASell(double _amount, double _price)
{
    this->sellCoalA->SetAmount(_amount);
    this->sellCoalA->SetPrice(_price);
}

void Mine::SetCoalBSell(double _amount, double _price)
{
    this->sellCoalB->SetAmount(_amount);
    this->sellCoalB->SetPrice(_price);
}

void Mine::SetBudget(double _budget)
{
    this->budget=_budget;
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

double Mine::GetMorale()
{
    double morale=0;

    for(int i=0; i<this->miners.count(); i++)
    {
        morale+=this->miners[i]->GetMorale();
    }
    morale/=(this->miners.count());

    return morale;
}


double Mine::CalculateExtraction(CoalTypeA const *_coalA)
{
    double extraction=0;
    for (int i=0; i<this->miners.count(); i++)
    {
        extraction+=this->miners[i]->GetEfficiency(_coalA);
    }
    return extraction;
}

double Mine::CalculateExtraction(CoalTypeB const *_coalB)
{
    double extraction=0;
    for (int i=0; i<this->miners.count(); i++)
    {
        extraction+=this->miners[i]->GetEfficiency(_coalB);
    }
    return extraction;
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

bool Mine::PaySalary()
{
	this->budget -= miners.size()*salary;
	if (budget < 0)
	{
		budget = 0;
		//endgame!
	}
}
Order* Mine::PlaceOnMarket()
{

}




