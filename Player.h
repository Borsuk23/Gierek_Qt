#pragma once
#include "CommonIncludes.h"
#include "Mine.h"


class Player
{
private:
    QString name;
	double score;
    Mine *mine;
public:
	Player();
    Player(QString _name, int _difficulty=0);
    Mine* GetMine();
    QString GetName();
    double GetScore();
    void SetExtraction(CoalTypeA *_coalA, CoalTypeB *_coalB);
    void SetSell(CoalTypeA *_coalA, CoalTypeB *_coalB);
    void SetSalary(double _salary);
    void HireMiner();
    void NoticeMiner();

};

