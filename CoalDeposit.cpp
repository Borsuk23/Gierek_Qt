#include "CoalDeposit.h"


CoalDeposit::CoalDeposit():Client()
{

}

/*!
 * \brief CoalDeposit::CoalDeposit kontruktor
 * \param _difficulty w zależności od poziomu trudności inne typowe zamówienia
 */
CoalDeposit::CoalDeposit(int _difficulty)
{
    this->name="Coal Deposit";
    if(_difficulty==3)  //trudny
    {
        this->averageOrder = new Order(new CoalTypeA(200,400), new CoalTypeB(300,350));
    }
    else if (_difficulty==2)    //średni
    {
        this->averageOrder = new Order(new CoalTypeA(250,500), new CoalTypeB(350,40));
    }
    else    //łatwy (domyślnie)
    {
        this->averageOrder = new Order(new CoalTypeA(300,600), new CoalTypeB(400,450));
    }

}

Order* CoalDeposit::MakeOrder(int _date)
{
    Order *newOrder = new Order();
    double temp=0;
    if((_date%12+1)==1||(_date%12+1)==2||(_date%12+1)==3||(_date%12+1)==10||(_date%12+1)==11||(_date%12+1)==0)
    {
        double factor= rand()%50;
        temp=this->averageOrder->GetCoalA()->GetAmount();
        temp*=(1+((factor-25)/100));

        newOrder->GetCoalA()->SetAmount(temp);
        newOrder->GetCoalA()->SetPrice((this->averageOrder->GetCoalA()->GetPrice()*(1+(rand()%20-10)/100)));
        newOrder->GetCoalB()->SetAmount(2*(this->averageOrder->GetCoalB()->GetAmount()*(1+(rand()%50-25)/100)));
        newOrder->GetCoalB()->SetPrice((this->averageOrder->GetCoalB()->GetPrice()*(1+(rand()%20-10)/100)));
    }
    else
    {
        newOrder->GetCoalA()->SetAmount((this->averageOrder->GetCoalA()->GetAmount()*(1+(rand()%50-25)/100)));
        newOrder->GetCoalA()->SetPrice((this->averageOrder->GetCoalA()->GetPrice()*(1+(rand()%20-10)/100)));
        newOrder->GetCoalB()->SetAmount((this->averageOrder->GetCoalB()->GetAmount()*(1+(rand()%50-25)/100)));
        newOrder->GetCoalB()->SetPrice((this->averageOrder->GetCoalB()->GetPrice()*(1+(rand()%20-10)/100)));
    }
    return newOrder;
}
