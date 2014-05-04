#include "pch.h"
#include "Order.h"

Order::Order()
{
	this->coalA = nullptr;
	this->coalB = nullptr;
}
Order::Order(CoalTypeA *coalA, CoalTypeB *coalB)
{
	this->coalA = coalA;
	this->coalB = coalB;
}
