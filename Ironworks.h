#pragma once
#include "Client.h"
/*!
 * \brief The Ironworks class klasa reprezentująca huty
 */
class Ironworks: public Client
{
public:
    /*!
     * \brief Ironworks domyślny konstruktor
     */
	Ironworks();
    /*!
     * \brief Ironworks konstruktor sparametryzowany zależny od trudności
     * \param _difficulty poziom trudności
     */
    Ironworks(int _difficulty);
    /*!
     * \brief MakeOrder składa zamówienie zależne od pory roku
     * \param _date obecna data
     * \return zamówienie na węgiel
     */
    Order* MakeOrder(int _date);
};

