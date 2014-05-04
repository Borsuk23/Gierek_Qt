#include "pch.h"
#include "CoalDeposit.h"


CoalDeposit::CoalDeposit()
{
}

Order CoalDeposit::MakeOrder()
{
	Order *newOrder = new Order;
	return *newOrder;
}
