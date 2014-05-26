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
    QString GetName();
    Order* SellOffer();
};

#endif //AI_H
