#ifndef COALTYPEA_H
#define COALTYPEA_H

#include "Coal.h"

/*!
 * \brief The CoalTypeA class węgiel typu A
 */
class CoalTypeA: public Coal
{
public:
    /*!
     * \brief CoalTypeA domyślny konstruktor
     * wywołuje konstruktor klasy bazowej
     */
    CoalTypeA();
    /*!
     * \brief CoalTypeA konstruktor sparametryzowany
     * wywołuje konstruktor klasy bazowej
     * \param _amount ilosć
     * \param _price cena
     */
    CoalTypeA(double _amount, double _price);
};

#endif //COALTYPEA_H
