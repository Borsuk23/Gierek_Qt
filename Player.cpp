#include "CommonIncludes.h"
#include "Player.h"


Player::Player()
{

}

Player::Player(QString _name, int _difficulty)
{
    this->name=_name;
    this->score=0;
    this->mine = new Mine();
}

Mine* Player::GetMine()
{
    return this->mine;
}


QString Player::GetName()
{

}

double Player::GetScore()
{

}

void Player::SetExtraction(CoalTypeA *_coalA, CoalTypeB *_coalB)
{

}

void Player::SetSell(CoalTypeA *_coalA, CoalTypeB *_coalB)
{

}

void Player::SetSalary(double _salary)
{
    this->mine->SetSalary(_salary);
}

bool Player::HireMiner()
{

}

bool Player::NoticeMiner()
{

}


