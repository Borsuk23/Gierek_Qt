#pragma once
#include "CoalTypeA.h"
#include "CoalTypeB.h"
#include "CommonIncludes.h"

class Miner
{
private :
    QString name;
	int experience;
	double morale;
public:
	Miner();
    Miner(QString _name);
    QString GetName();
    double GetMorale();
    void MineCoal(CoalTypeA *_coal);
    void MineCoal(CoalTypeB *_coal);
    double GetEfficiency(CoalTypeA const *_coal);
    double GetEfficiency(CoalTypeB const *_coal);
	bool Strike();
	bool Dismissal();
    double MoraleUpdate(double _salary);
};

