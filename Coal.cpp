#include "Coal.h"


Coal::Coal()
{
    this->amount = 0;
    this->price = 0;
}

Coal::Coal(double _amount, double _price)
{
    this->amount = _amount;
    this->price = _price;
}

double Coal::GetAmount()
{
    return this->amount;
}

double Coal::GetPrice()
{
    return this->price;
}

void Coal::SetAmount(double _amount)
{
    if(_amount>=0)
    this->amount = _amount;
}

void Coal::SetPrice(double _price)
{
    if(_price>0)
    this->price = _price;
}


void Coal::Add(double _amount)
{
    if(_amount>=0)
        this->amount+=_amount;
}

double Coal::Substract(double _amount)
{
    if(_amount>0 && this->amount>=_amount)
    {
        this->amount-=_amount;
        return 0;
    }
    else if(_amount>0)
    {
        _amount-=this->amount;
        this->amount=0;
        return _amount;
    }
}
