#include "pch.h"
#include "Market.h"


Market::Market()
{
}

void Market::AddOrder(Order *newOrder)
{
	orderList.push_back(*newOrder);
}

Order Market::AccomplishTransaction(Order *playerOffer)
{
	Order *sold = new Order();
	
	//check if there's any coal type A for sell
	if (playerOffer->coalA != nullptr)
	{
		sold->coalA->price = playerOffer->coalA->price;
		sold->coalA->amount = 0;

		//if any other mine sells for lower price than it's first in row for comming transactions
		for (Order off : offerList)
		{
			if (off.coalA->price < playerOffer->coalA->price)
			{
				for (Order ord : orderList)
				{
					if (off.coalA->price<ord.coalA->price)
					{
						//when seller got more than client
						if (off.coalA->amount > ord.coalA->amount)
						{
							off.coalA->amount -= ord.coalA->amount;
							ord.coalA = nullptr;
						}
						//when sell offer is too small for client
						else
						{
							ord.coalA->amount -= off.coalA->amount;
							off.coalA->amount = 0;
						}
					}
				}
			}
		}
		//now it's player turn for selling coal
		for (auto ord : orderList)
		{
			if (playerOffer->coalA->price<ord.coalA->price)
			{
				//when seller got more than client
				if (playerOffer->coalA->amount > ord.coalA->amount)
				{
					playerOffer->coalA->amount -= ord.coalA->amount;
					sold->coalA->amount += ord.coalA->amount;
					ord.coalA = nullptr;
				}
				//when sell offer is too small for client
				else
				{
					ord.coalA->amount -= playerOffer->coalA->amount;
					sold->coalA->amount += playerOffer->coalA->amount;
					playerOffer->coalA->amount = 0;
				}
			}
		}
	}

	if (playerOffer->coalB != nullptr)
	{
		sold->coalB->price = playerOffer->coalB->price;
		sold->coalB->amount = 0;
		
		//if any other mine sells for lower price than it's first in row for comming transactions
		for (auto off : offerList)
		{
			if (off.coalB->price < playerOffer->coalB->price)
			{
				for (auto ord : orderList)
				{
					if (off.coalB->price<ord.coalB->price)
					{
						//when seller got more than client
						if (off.coalB->amount > ord.coalB->amount)
						{
							off.coalB->amount -= ord.coalB->amount;
							ord.coalB = nullptr;
						}
						//when sell offer is too small for client
						else
						{
							ord.coalB->amount -= off.coalB->amount;
							off.coalB->amount = 0;
						}
					}
				}
			}
		}
		//now it's player turn for selling coal
		for (auto ord : orderList)
		{
			if (playerOffer->coalB->price<ord.coalB->price)
			{
				//when seller got more than client
				if (playerOffer->coalB->amount > ord.coalB->amount)
				{
					playerOffer->coalB->amount -= ord.coalB->amount;
					sold->coalB->amount += ord.coalB->amount;
					ord.coalB = nullptr;
				}
				//when sell offer is too small for client
				else
				{
					ord.coalB->amount -= playerOffer->coalB->amount;
					sold->coalB->amount += playerOffer->coalB->amount;
					playerOffer->coalB->amount = 0;
				}
			}
		}
	}

	//then rest of the offers
	for (auto off : offerList)
	{
		for (auto ord : orderList)
		{
			if (off.coalA->price<ord.coalA->price)
			{
				//when seller got more than client
				if (off.coalA->amount > ord.coalA->amount)
				{
					off.coalA->amount -= ord.coalA->amount;
					ord.coalA = nullptr;
				}
				//when sell offer is too small for client
				else
				{
					ord.coalA->amount -= off.coalA->amount;
					off.coalA->amount = 0;
				}
			}
			if (off.coalB->price<ord.coalB->price)
			{
				//when seller got more than client
				if (off.coalB->amount > ord.coalB->amount)
				{
					off.coalB->amount -= ord.coalB->amount;
					ord.coalB = nullptr;
				}
				//when sell offer is too small for client
				else
				{
					ord.coalB->amount -= off.coalB->amount;
					off.coalB->amount = 0;
				}
			}
		}
	}
	return *sold;
}
