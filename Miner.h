#pragma once
#include "CoalTypeA.h"
#include "CoalTypeB.h"
#include "CommonIncludes.h"

class Miner
{
public:
    QString name;
	int experience;
	double morale;
public:
	Miner();
    Miner(QString name);
	void MineCoal(CoalTypeA coal);
	void MineCoal(CoalTypeB coal);
	double GetEfficiency(CoalTypeA *coal);
	double GetEfficiency(CoalTypeB *coal);
	bool Strike();
	bool Dismissal();
	double MoraleUpdate(double salary);
};

