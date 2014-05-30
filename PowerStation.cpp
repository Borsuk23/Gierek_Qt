#include "PowerStation.h"


PowerStation::PowerStation(): Client()
{

}

PowerStation::PowerStation(int _difficulty)
{
    this->name="Power Station";
    if(_difficulty==3)  //trudny
    {
        this->averageOrder = new Order(new CoalTypeA(600,450), new CoalTypeB(1000,400));
    }
    else if (_difficulty==2)    //średni
    {
        this->averageOrder = new Order(new CoalTypeA(800,500), new CoalTypeB(1500,450));
    }
    else    //łatwy (domyślnie)
    {
        this->averageOrder = new Order(new CoalTypeA(1000,550), new CoalTypeB(2000,500));
    }
}

Order* PowerStation::MakeOrder(int _date)
{
    Order *newOrder = new Order();
    newOrder->GetCoalA()->SetAmount(DataSeed::random(this->averageOrder->GetCoalA()->GetAmount(),25));
    newOrder->GetCoalA()->SetPrice(DataSeed::random(this->averageOrder->GetCoalA()->GetPrice(),10));
    newOrder->GetCoalB()->SetAmount(DataSeed::random(this->averageOrder->GetCoalB()->GetAmount(),25));
    newOrder->GetCoalB()->SetPrice(DataSeed::random(this->averageOrder->GetCoalB()->GetPrice(),10));
    return newOrder;
}
