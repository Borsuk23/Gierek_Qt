#include "AI.h"


AI::AI()
{
    this->name="konkurencja:";
    this->avarageExtractCoalA=new CoalTypeA(8500,540);
    this->avarageExtractCoalB=new CoalTypeB(10000,420);
}

Order* AI::SellOffer()
{
    Order *newOrder = new Order();
    newOrder->GetCoalA()->SetAmount(DataSeed::random(this->avarageExtractCoalA->GetAmount(),25));
    newOrder->GetCoalA()->SetPrice(DataSeed::random(this->avarageExtractCoalA->GetPrice(),10));
    newOrder->GetCoalB()->SetAmount(DataSeed::random(this->avarageExtractCoalB->GetAmount(),25));
    newOrder->GetCoalB()->SetPrice(DataSeed::random(this->avarageExtractCoalB->GetPrice(),10));
    return newOrder;
}

QString AI::GetName()
{
    return this->name;
}
