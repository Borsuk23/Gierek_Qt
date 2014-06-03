#ifndef CLIENT_H
#define CLIENT_H

#include "CommonIncludes.h"
#include "Order.h"
/*!
 * \brief The Client class - nadrzędna klasa dostarczająca interfejs dla różnych typów klientów (polimorfizm)
 */
class Client
{
protected:
    QString name; //! imię
    Order *averageOrder;    //! przeciętne zamówienie
public:
    /*!
     * \brief Client domyślny konstruktor
     */
    Client();
    /*!
     * \brief Client konstruktor sparametryzowany
     * \param _difficulty zależnie od poziomu trudności inne wartości początkowe
     */
    Client(int _difficulty);
    /*!
     * \brief MakeOrder metoda tworząca zamówienie
     * \param _date zależnie od pory roku różna wielkość zamówienia
     * \return zwraca gotowe zamówienie na węgiel
     */
    virtual Order* MakeOrder(int _date) {return NULL;}
    /*!
     * \brief GetName metoda get dla name
     * \return nazwę
     */
    QString GetName();
};

#endif //CLIENT_H
