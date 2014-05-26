#include "Client.h"


Client::Client()
{
    this->name="trololo";
    this->averageOrder= new Order(new CoalTypeA(1000,600),new CoalTypeB(1000,400));
}
Client::Client(int _difficulty)
{

}

QString Client::GetName()
{
    return this->name;
}

