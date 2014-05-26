#include "AI.h"


AI::AI()
{
    this->name="konkurencyjna kopalnia";
    this->avarageExtractCoalA=new CoalTypeA(1000,600);
    this->avarageExtractCoalB=new CoalTypeB(1000,800);
}

Order* AI::SellOffer()
{
    Order *newOrder = new Order();
    newOrder->SetCoalA(this->avarageExtractCoalA);
    newOrder->SetCoalB(this->avarageExtractCoalB);
    return newOrder;
}

QString AI::GetName()
{
    return this->name;
}
