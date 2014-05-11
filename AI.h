#ifndef AI_H
#define AI_H
#include "CommonIncludes.h"
#include "CoalTypeA.h"
#include "CoalTypeB.h"
#include "Order.h"

class AI
{
private:
    QString name;
    CoalTypeA *avarageExtractCoalA;
    CoalTypeB *avarageExtractCoalB;
public:
	AI();
    Order* SellOffer();
};

#endif //AI_H
