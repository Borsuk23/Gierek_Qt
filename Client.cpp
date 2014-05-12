#include "Client.h"


Client::Client()
{
    this->name="trololo";
}
Client::Client(int _difficulty)
{
    this->name="trololo";
    this->avarageOrder= new Order();
    this->avarageOrder->GetCoalA()->SetPrice(600-100*_difficulty);
    this->avarageOrder->GetCoalB()->SetPrice(800-100*_difficulty);
}

Order* Client::MakeOrder(int _date)
{

}

QString Client::GetName()
{
    return this->name;
}
