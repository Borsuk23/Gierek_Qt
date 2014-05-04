#pragma once
#include "Miner.h"
#include "Order.h"
#include "Storehouse.h"
class Mine
{
public:
	std::string name;
	double salary;
	double budget;
	std::vector<Miner> miners;
	Storehouse *storage;

	CoalTypeA extractCoalA;
	CoalTypeB extractCoalB;

	CoalTypeA sellCoalA;
	CoalTypeB sellCoalB;

public:
	Mine();
	void MineCoal();
	Order PlaceOnMarket();
	void PaySalary();
	void CheckCrew();
	CoalTypeA CalculateExtraction(CoalTypeA *coal);
	CoalTypeB CalculateExtraction(CoalTypeB *coal);


};

