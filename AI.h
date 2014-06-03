#ifndef AI_H
#define AI_H
#include "CommonIncludes.h"
#include "CoalTypeA.h"
#include "CoalTypeB.h"
#include "Order.h"

/*!
 * \brief The AI class odpowiada za symulowanie konkurencyjnych kopalni
 */
class AI
{
private:
    QString name; //! imię
    CoalTypeA *avarageExtractCoalA; //! przeciętne wydobycie węgla typu A
    CoalTypeB *avarageExtractCoalB; //! przeciętne wydobycie węgla typu B
public:
    /*!
     * \brief AI konstruktor domyślny
     */
	AI();
    /*!
     * \brief AI konstruktor sparametryzowany
     * \param _difficulty zawartość zależna od poziomu trudności
     */
    AI(int _difficulty);
    /*!
     * \brief GetName
     * \return nazwę
     */
    QString GetName();
    /*!
     * \brief SellOffer metoda tworzenia oferty sprzedaży
     * \return ofertę sprzedaży węgla
     */
    Order* SellOffer();
};

#endif //AI_H
