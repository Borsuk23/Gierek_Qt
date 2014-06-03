#include "CommonIncludes.h"
#include "Player.h"


Player::Player()
{

}

Player::Player(QString _name, int _difficulty)
{
    this->name=_name;
    this->score=0;
    this->mine = new Mine(_difficulty);
}

Mine* Player::GetMine()
{
    return this->mine;
}


QString Player::GetName()
{
    return this->name;
}

double Player::GetScore()
{
    return this->score;
}

void Player::SetExtraction(CoalTypeA *_coalA, CoalTypeB *_coalB)
{
    this->mine->SetCoalAExtraction(_coalA->GetAmount());
    this->mine->SetCoalBExtraction(_coalB->GetAmount());
}

void Player::SetSell(CoalTypeA *_coalA, CoalTypeB *_coalB)
{
    this->mine->SetCoalASell(_coalA->GetAmount(), _coalA->GetPrice());
    this->mine->SetCoalBSell(_coalB->GetAmount(), _coalB->GetPrice());
}

void Player::SetSalary(double _salary)
{
    this->mine->SetSalary(_salary);
}

void Player::HireMiner()
{
    this->mine->HireWorker();
}

void Player::NoticeMiner()
{
    this->mine->NoticeWorker();
}

void Player::AddPoint(double _points)
{
    if(_points>0)
    {
        this->score+=_points;
    }
}

