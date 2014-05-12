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
        //_coal.amount += (1 + experience * 0, 02) * 100;
	}
}

void Miner::MineCoal(CoalTypeB *_coal)
{
	if (!Strike())
	{
        //_coal.amount += (1 + experience * 0, 03) * 160;
	}
}

double Miner::GetEfficiency(CoalTypeA const *_coal)
{
    return (1 + experience * 0, 02) * 100;
}


double Miner::GetEfficiency(CoalTypeB const *_coal)
{
    return (1 + experience * 0, 03) * 160;
}

bool Miner::Strike() 
{
	double check = (rand() % 100)*(rand() % 100)*(rand() % 100);
	if (check < morale)
		return false;
	else
		return true;
}

bool Miner::Dismissal()
{
	double check = (rand() % 90)*(rand() % 90)*(rand() % 90);
	if (check < morale)
		return false;
	else
		return true;
}

double Miner::MoraleUpdate(double _salary)
{
	return 100;
}
