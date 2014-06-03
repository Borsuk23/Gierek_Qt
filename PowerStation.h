#pragma once
#include "Client.h"
/*!
 * \brief The PowerStation class klasa reprezentująca huty
 */
class PowerStation: public Client
{
public:
    /*!
     * \brief PowerStation domyślny konstruktor
     */
	PowerStation();
    /*!
     * \brief PowerStation konstruktor sparametryzowany zależny od trudności
     * \param _difficulty poziom trudności
     */
    PowerStation(int _difficulty);
    /*!
     * \brief MakeOrder składa zamówienie zależne od pory roku
     * \param _date obecna data
     * \return zamówienie na węgiel
     */
    Order* MakeOrder(int _date);
};
