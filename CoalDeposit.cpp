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
