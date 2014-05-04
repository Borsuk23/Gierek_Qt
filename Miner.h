#pragma once
#include "CoalTypeA.h"
#include "CoalTypeB.h"
class Miner
{
public:
	std::string name;
	int experience;
	double morale;
public:
	Miner();
	Miner(std::string name);
	void MineCoal(CoalTypeA coal);
	void MineCoal(CoalTypeB coal);
	double GetEfficiency(CoalTypeA *coal);
	double GetEfficiency(CoalTypeB *coal);
	bool Strike();
	bool Dismissal();
	double MoraleUpdate(double salary);
};

