#ifndef COALTYPEB_H
#define COALTYPEB_H

#include "Coal.h"

/*!
 * \brief The CoalTypeB class węgiel typu B
 */
class CoalTypeB: public Coal
{
public:
    /*!
     * \brief CoalTypeB domyślny konstruktor
     * wywołuje konstruktor klasy bazowej
     */
	CoalTypeB();
    /*!
     * \brief CoalTypeB konstruktor sparametryzowany
     * wywołuje konstruktor klasy bazowej
     * \param _amount ilosć
     * \param _price cena
     */
	CoalTypeB(double amount, double price);
};

#endif //COALTYPEB_H
