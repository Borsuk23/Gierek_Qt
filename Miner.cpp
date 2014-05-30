#include "Miner.h"


Miner::Miner()
{
    this->name = "Janusz";
    this->experience = rand() % 100;
    this->morale = 100;
}

Miner::Miner(QString _name)
{
    this->name = _name;
	this->experience = rand() % 100;
	this->morale = 100;
}

QString Miner::GetName()
{
    return this->name;
}

double Miner::GetMorale()
{
    return this->morale;
}

void Miner::MineCoal(CoalTypeA *_coal)
{
	if (!Strike())
	{
        _coal->Add((1 + experience * 0.04) * 10);
	}
}

void Miner::MineCoal(CoalTypeB *_coal)
{
	if (!Strike())
	{
        _coal->Add((1 + experience * 0.03) * 8);
	}
}

double Miner::GetEfficiency(CoalTypeA const *_coal)
{
    return (1 + experience * 0.04) * 10;
}


double Miner::GetEfficiency(CoalTypeB const *_coal)
{
    return (1 + experience * 0.03) * 8;
}

bool Miner::Strike() 
{
    double check = (rand() % 100)*(rand() % 100)/100;
    if (check < this->morale)
		return false;
	else
		return true;
}

bool Miner::Dismissal()
{
    double check = (rand() % 100)*(rand() % 100)/100*(rand() % 100)/100;
    if (check < this->morale)
		return false;
	else
		return true;
}

double Miner::MoraleUpdate(double _salary)
{
    double update = 0;
    update = (_salary-5000)/200;
    if(_salary<1000)
    {
        update=-50;
    }
    this->morale+=update;

    if(this->morale<0)
        this->morale=0;
    if(this->morale>100)
        this->morale=100;

    return this->morale;
}
