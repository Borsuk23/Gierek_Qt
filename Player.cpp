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

void Player::SetSalary(int _salary)
{
    this->mine->salary=_salary;
}
Mine* Player::GetMine()
{
    return this->mine;
}
