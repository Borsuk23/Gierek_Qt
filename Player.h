#pragma once
#include "CommonIncludes.h"
#include "Mine.h"


class Player
{
public:
    QString name;
	double score;
    Mine *mine = NULL;
public:
	Player();
    Player(QString _name, int _difficulty=0);
    Mine* GetMine();
    void SetExtraction(CoalTypeA _coalA, CoalTypeB _coalB);
    void SetSell(CoalTypeA _coalA, CoalTypeB _coalB);
    void SetSalary(int _salary);
    void HireMiner();
    void NoticeMiner();
    double CalculateScore();

};

