#ifndef COALDEPOSIT_H
#define COALDEPOSIT_H

#include "Client.h"

/*!
 * \brief The CoalDeposit class klasa reprezentująca składy węgla
 * sezonowe zmiany zamówień
 */
class CoalDeposit: public Client
{
public:
    /*!
     * \brief CoalDeposit konstruktor domyślny
     */
	CoalDeposit();
    /*!
     * \brief CoalDeposit konstruktor sparametryzowany
     * \param _difficulty zależnie od poziomu trudności
     */
    CoalDeposit(int _difficulty);
    /*!
     * \brief MakeOrder składa zamówienie zależne od pory roku
     * \param _date obecna data
     * \return zamówienie na węgiel
     */
    Order* MakeOrder(int _date);
};

#endif //COALDEPOSIT_H
