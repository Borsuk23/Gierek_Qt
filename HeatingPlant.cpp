#include "HeatingPlant.h"


HeatingPlant::HeatingPlant():Client()
{

}

HeatingPlant::HeatingPlant(int _difficulty)
{

    this->name="Heating Plant";
    if(_difficulty==3)  //trudny
    {
        this->averageOrder = new Order(new CoalTypeA(4000,400), new CoalTypeB(4000,300));
    }
    else if (_difficulty==2)    //średni
    {
        this->averageOrder = new Order(new CoalTypeA(4500,500), new CoalTypeB(4500,350));
    }
    else    //łatwy (domyślnie)
    {
        this->averageOrder = new Order(new CoalTypeA(5000,600), new CoalTypeB(5000,400));
    }
}

Order* HeatingPlant::MakeOrder(int _date)
{
    Order *newOrder = new Order();
    if((_date%12+1)==1||(_date%12+1)==2||(_date%12+1)==3||(_date%12+1)==10||(_date%12+1)==11||(_date%12+1)==0)
    {
        newOrder->GetCoalA()->SetAmount(2*DataSeed::random(this->averageOrder->GetCoalA()->GetAmount(),25));
        newOrder->GetCoalA()->SetPrice(DataSeed::random(this->averageOrder->GetCoalA()->GetPrice(),10));
        newOrder->GetCoalB()->SetAmount(2*DataSeed::random(this->averageOrder->GetCoalB()->GetAmount(),25));
        newOrder->GetCoalB()->SetPrice(DataSeed::random(this->averageOrder->GetCoalB()->GetPrice(),10));
    }
    else
    {
        newOrder->GetCoalA()->SetAmount(DataSeed::random(this->averageOrder->GetCoalA()->GetAmount(),25));
        newOrder->GetCoalA()->SetPrice(DataSeed::random(this->averageOrder->GetCoalA()->GetPrice(),10));
        newOrder->GetCoalB()->SetAmount(DataSeed::random(this->averageOrder->GetCoalB()->GetAmount(),25));
        newOrder->GetCoalB()->SetPrice(DataSeed::random(this->averageOrder->GetCoalB()->GetPrice(),10));
    }
    return newOrder;
}
