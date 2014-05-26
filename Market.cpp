#include "Market.h"


Market::Market()
{

    this->stats=new Order();
}
QList<Order*> Market::GetOrdersList()
{
    return this->orderList;
}

QList<Order*> Market::GetOffersList()
{
    return this->offerList;
}

void Market::AddOrder(Order *newOrder)
{
    this->orderList.push_back(newOrder);
}
void Market::AddOffer(Order *newOffer)
{
    this->offerList.push_back(newOffer);
}

Order* Market::GetStats()
{
    return this->stats;
}

Order* Market::AccomplishTransaction(Order *_playerOffer)
{
    Order *leftCoal = new Order();
    leftCoal->GetCoalA()->SetPrice(_playerOffer->GetCoalA()->GetPrice());
    leftCoal->GetCoalA()->SetAmount(_playerOffer->GetCoalA()->GetAmount());
    leftCoal->GetCoalB()->SetPrice(_playerOffer->GetCoalB()->GetPrice());
    leftCoal->GetCoalB()->SetAmount(_playerOffer->GetCoalB()->GetAmount());

    double amountA=0;
    double priceA=0;
    double amountB=0;
    double priceB=0;

	//check if there's any coal type A for sell
    if (_playerOffer->GetCoalA()->GetAmount()>0)
    {
		//if any other mine sells for lower price than it's first in row for comming transactions
        for (int i=0; i<this->offerList.size(); i++)
		{
            if (this->offerList.at(i)->GetCoalA()->GetPrice()< _playerOffer->GetCoalA()->GetPrice())
			{
                for (int j=0; j<this->orderList.size();j++)
				{
                    if (offerList.at(i)->GetCoalA()->GetPrice()<orderList.at(j)->GetCoalA()->GetPrice() && offerList.at(i)->GetCoalA()->GetAmount()>0)
					{
						//when seller got more than client
                        if (offerList.at(i)->GetCoalA()->GetAmount() > orderList.at(j)->GetCoalA()->GetAmount())
						{
                            amountA+=orderList.at(j)->GetCoalA()->GetAmount();
                            priceA+=offerList.at(i)->GetCoalA()->GetPrice()*orderList.at(j)->GetCoalA()->GetAmount();
                            offerList.at(i)->GetCoalA()->Substract(orderList.at(j)->GetCoalA()->Substract(orderList.at(j)->GetCoalA()->GetAmount()));
						}
						//when sell offer is too small for client
						else
						{
                            amountA+=offerList.at(i)->GetCoalA()->GetAmount();
                            priceA+=offerList.at(i)->GetCoalA()->GetPrice()*offerList.at(i)->GetCoalA()->GetAmount();
                            orderList.at(j)->GetCoalA()->Substract(offerList.at(i)->GetCoalA()->Substract(offerList.at(i)->GetCoalA()->GetAmount()));
						}
					}
				}
			}
		}
		//now it's player turn for selling coal
        for (int j=0; j<this->orderList.size();j++)
		{
            if (_playerOffer->GetCoalA()->GetPrice()<orderList.at(j)->GetCoalA()->GetPrice() && _playerOffer->GetCoalA()->GetAmount()>0)
			{
				//when seller got more than client
                if (_playerOffer->GetCoalA()->GetAmount() > orderList.at(j)->GetCoalA()->GetAmount())
				{
                    amountA+=orderList.at(j)->GetCoalA()->GetAmount();
                    priceA+=_playerOffer->GetCoalA()->GetPrice()*orderList.at(j)->GetCoalA()->GetAmount();
                    leftCoal->GetCoalA()->Substract(orderList.at(j)->GetCoalA()->GetAmount());
                    _playerOffer->GetCoalA()->Substract(orderList.at(j)->GetCoalA()->Substract(orderList.at(j)->GetCoalA()->GetAmount()));
				}
				//when sell offer is too small for client
				else
				{
                    amountA+=_playerOffer->GetCoalA()->GetAmount();
                    priceA+=_playerOffer->GetCoalA()->GetPrice()*_playerOffer->GetCoalA()->GetAmount();
                    leftCoal->GetCoalA()->Substract(_playerOffer->GetCoalA()->GetAmount());
                    orderList.at(j)->GetCoalA()->Substract(_playerOffer->GetCoalA()->Substract(_playerOffer->GetCoalA()->GetAmount()));
				}
			}
		}
	}

    if (_playerOffer->GetCoalB()->GetAmount()>0)
       {
           //if any other mine sells for lower price than it's first in row for comming transactions
           for (int i=0; i<this->offerList.size(); i++)
           {
               if (this->offerList.at(i)->GetCoalB()->GetPrice()< _playerOffer->GetCoalB()->GetPrice())
               {
                   for (int j=0; j<this->orderList.size();j++)
                   {
                       if (offerList.at(i)->GetCoalB()->GetPrice()<orderList.at(j)->GetCoalB()->GetPrice() && offerList.at(i)->GetCoalB()->GetAmount()>0)
                       {
                           //when seller got more than client
                           if (offerList.at(i)->GetCoalB()->GetAmount() > orderList.at(j)->GetCoalB()->GetAmount())
                           {
                               amountB+=orderList.at(j)->GetCoalB()->GetAmount();
                               priceB+=offerList.at(i)->GetCoalB()->GetPrice()*orderList.at(j)->GetCoalB()->GetAmount();
                               offerList.at(i)->GetCoalB()->Substract(orderList.at(j)->GetCoalB()->Substract(orderList.at(j)->GetCoalB()->GetAmount()));
                           }
                           //when sell offer is too small for client
                           else
                           {
                               amountB+=offerList.at(i)->GetCoalB()->GetAmount();
                               priceB+=offerList.at(i)->GetCoalB()->GetPrice()*offerList.at(i)->GetCoalB()->GetAmount();
                               orderList.at(j)->GetCoalB()->Substract(offerList.at(i)->GetCoalB()->Substract(offerList.at(i)->GetCoalB()->GetAmount()));
                           }
                       }
                   }
               }
           }
           //now it's player turn for selling coal
           for (int j=0; j<this->orderList.size();j++)
           {
               if (_playerOffer->GetCoalB()->GetPrice()<orderList.at(j)->GetCoalB()->GetPrice() && _playerOffer->GetCoalB()->GetAmount()>0)
               {
                   //when seller got more than client
                   if (_playerOffer->GetCoalB()->GetAmount() > orderList.at(j)->GetCoalB()->GetAmount())
                   {
                       amountB+=orderList.at(j)->GetCoalB()->GetAmount();
                       priceB+=_playerOffer->GetCoalB()->GetPrice()*orderList.at(j)->GetCoalB()->GetAmount();
                       leftCoal->GetCoalB()->Substract(orderList.at(j)->GetCoalB()->GetAmount());
                       _playerOffer->GetCoalB()->Substract(orderList.at(j)->GetCoalB()->Substract(orderList.at(j)->GetCoalB()->GetAmount()));
                   }
                   //when sell offer is too small for client
                   else
                   {
                       amountB+=_playerOffer->GetCoalB()->GetAmount();
                       priceB+=_playerOffer->GetCoalB()->GetPrice()*_playerOffer->GetCoalB()->GetAmount();
                       leftCoal->GetCoalB()->Substract(_playerOffer->GetCoalB()->GetAmount());
                       orderList.at(j)->GetCoalB()->Substract(_playerOffer->GetCoalB()->Substract(_playerOffer->GetCoalB()->GetAmount()));
                   }
               }
           }
       }

	//then rest of the offers
    for (int i=0; i<this->offerList.size(); i++)
	{
        for (int j=0; j<this->orderList.size();j++)
		{
            if (offerList.at(i)->GetCoalA()->GetPrice()<orderList.at(j)->GetCoalA()->GetPrice() && offerList.at(i)->GetCoalA()->GetAmount()>0)
            {
                //when seller got more than client
                if (offerList.at(i)->GetCoalA()->GetAmount() > orderList.at(j)->GetCoalA()->GetAmount())
                {
                    amountA+=orderList.at(j)->GetCoalA()->GetAmount();
                    priceA+=offerList.at(i)->GetCoalA()->GetPrice()*orderList.at(j)->GetCoalA()->GetAmount();
                    offerList.at(i)->GetCoalA()->Substract(orderList.at(j)->GetCoalA()->Substract(orderList.at(j)->GetCoalA()->GetAmount()));
                }
                //when sell offer is too small for client
                else
                {
                    amountA+=offerList.at(i)->GetCoalA()->GetAmount();
                    priceA+=offerList.at(i)->GetCoalA()->GetPrice()*offerList.at(i)->GetCoalA()->GetAmount();
                    orderList.at(j)->GetCoalA()->Substract(offerList.at(i)->GetCoalA()->Substract(offerList.at(i)->GetCoalA()->GetAmount()));
                }
			}
            if (offerList.at(i)->GetCoalB()->GetPrice()<orderList.at(j)->GetCoalB()->GetPrice() && offerList.at(i)->GetCoalB()->GetAmount()>0)
            {
                //when seller got more than client
                if (offerList.at(i)->GetCoalB()->GetAmount() > orderList.at(j)->GetCoalB()->GetAmount())
                {
                    amountB+=orderList.at(j)->GetCoalB()->GetAmount();
                    priceB+=offerList.at(i)->GetCoalB()->GetPrice()*orderList.at(j)->GetCoalB()->GetAmount();
                    offerList.at(i)->GetCoalB()->Substract(orderList.at(j)->GetCoalB()->Substract(orderList.at(j)->GetCoalB()->GetAmount()));
                }
                //when sell offer is too small for client
                else
                {
                    amountB+=offerList.at(i)->GetCoalB()->GetAmount();
                    priceB+=offerList.at(i)->GetCoalB()->GetPrice()*offerList.at(i)->GetCoalB()->GetAmount();
                    orderList.at(j)->GetCoalB()->Substract(offerList.at(i)->GetCoalB()->Substract(offerList.at(i)->GetCoalB()->GetAmount()));
                }
            }
		}
	}

    this->stats->GetCoalA()->SetAmount(amountA);
    this->stats->GetCoalA()->SetPrice(priceA/amountA);
    this->stats->GetCoalB()->SetAmount(amountB);
    this->stats->GetCoalB()->SetPrice(priceB/amountB);
    return leftCoal;
}
