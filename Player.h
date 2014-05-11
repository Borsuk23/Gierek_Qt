#pragma once
#include "CommonIncludes.h"
#include "Mine.h"


class Player
{
public:
    QString name;
	double score;
    //Mine *mine = NULL;
public:
	Player();
    Player(QString _name, int _difficulty=0);

};

