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
    newOrder->GetCoalA()->SetAmount((this->averageOrder->GetCoalA()->GetAmount()*(1+(rand()%50-25)/100)));
    newOrder->GetCoalA()->SetPrice((this->averageOrder->GetCoalA()->GetPrice()*(1+(rand()%20-10)/100)));
    newOrder->GetCoalB()->SetAmount((this->averageOrder->GetCoalB()->GetAmount()*(1+(rand()%50-25)/100)));
    newOrder->GetCoalB()->SetPrice((this->averageOrder->GetCoalB()->GetPrice()*(1+(rand()%20-10)/100)));
    return newOrder;
}
