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
    newOrder->GetCoalA()->SetAmount((this->averageOrder->GetCoalA()->GetAmount()*(1+(rand()%50-25)/100)));
    newOrder->GetCoalA()->SetPrice((this->averageOrder->GetCoalA()->GetPrice()*(1+(rand()%20-10)/100)));
    newOrder->GetCoalB()->SetAmount((this->averageOrder->GetCoalB()->GetAmount()*(1+(rand()%50-25)/100)));
    newOrder->GetCoalB()->SetPrice((this->averageOrder->GetCoalB()->GetPrice()*(1+(rand()%20-10)/100)));
    return newOrder;
}
