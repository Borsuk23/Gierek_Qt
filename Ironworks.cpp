#include "Ironworks.h"
#include "CoalTypeA.h"
#include "CoalTypeB.h"
#include "CommonIncludes.h"


Ironworks::Ironworks(): Client()
{

}

Ironworks::Ironworks(int _difficulty)
{
    this->name="Ironworks";
    if(_difficulty==3)  //trudny
    {
        this->averageOrder = new Order(new CoalTypeA(600,400), new CoalTypeB(1000,300));
    }
    else if (_difficulty==2)    //średni
    {
        this->averageOrder = new Order(new CoalTypeA(800,450), new CoalTypeB(1500,350));
    }
    else    //łatwy (domyślnie)
    {
        this->averageOrder = new Order(new CoalTypeA(1000,500), new CoalTypeB(2000,400));
    }
}

Order* Ironworks::MakeOrder(int _date)
{
    Order *newOrder = new Order();
    newOrder->GetCoalA()->SetAmount(DataSeed::random(this->averageOrder->GetCoalA()->GetAmount(),25));
    newOrder->GetCoalA()->SetPrice(DataSeed::random(this->averageOrder->GetCoalA()->GetPrice(),10));
    newOrder->GetCoalB()->SetAmount(DataSeed::random(this->averageOrder->GetCoalB()->GetAmount(),25));
    newOrder->GetCoalB()->SetPrice(DataSeed::random(this->averageOrder->GetCoalB()->GetPrice(),10));
    return newOrder;
}
