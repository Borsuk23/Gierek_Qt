#include "pch.h"
#include "Miner.h"


Miner::Miner()
{
}

Miner::Miner(std::string name)
{
	this->name = name;
	this->experience = rand() % 100;
	this->morale = 100;
}

void Miner::MineCoal(CoalTypeA coal)
{
	if (!Strike())
	{
		coal.amount += (1 + experience * 0, 02) * 100;
	}
}

void Miner::MineCoal(CoalTypeB coal)
{
	if (!Strike())
	{
		coal.amount += (1 + experience * 0, 03) * 160;
	}
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

double Miner::GetEfficiency(CoalTypeA *coal)
{
	return (1 + experience * 0, 02) * 100;
}

	
double Miner::GetEfficiency(CoalTypeB *coal)
{
	return (1 + experience * 0, 03) * 160;
}

double Miner::MoraleUpdate(double salary)
{
	return 100;
}
