#pragma once
#include "Client.h"
/*!
 * \brief The HeatingPlant class klasa reprezentująca ciepłownie
 * sezonowe zmiany wartości zamówień
 */
class HeatingPlant: public Client
{
public:
    /*!
     * \brief HeatingPlant domyślny konstruktor
     */
	HeatingPlant();
    /*!
     * \brief HeatingPlant konstruktor sparametryzowany zależny od trudności
     * \param _difficulty poziom trudności
     */
    HeatingPlant(int _difficulty);
    /*!
     * \brief MakeOrder składa zamówienie zależne od pory roku
     * \param _date obecna data
     * \return zamówienie na węgiel
     */
    Order* MakeOrder(int _date);
};

