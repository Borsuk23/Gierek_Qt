#ifndef MARKET_H
#define MARKET_H


#include "Client.h"
#include "Order.h"
#include <QVector>

/*!
 * \brief The Market class klasa reprezentująca rynek
 * realizuje transakcje - pozwala na sprzedaż i kupno węgla
 */
class Market
{
private:
    QList<Order*> orderList; //! lista zamówień węgla
    QList<Order*> offerList; //! lista ofert sprzedaży węgla
    Order *stats;   //! statystyki rynku
public:
    /*!
     * \brief Market konstruktor domyślny
     */
    Market();
    /*!
     * \brief GetOrdersList
     * \return listę zamówień
     */
    QList<Order*> GetOrdersList();
    /*!
     * \brief GetOffersList
     * \return liste ofert
     */
    QList<Order*> GetOffersList();
    /*!
     * \brief AddOrder dodaje zamówienie
     * \param _order zamówienie do dodania
     */
    void AddOrder(Order *_order = new Order());
    /*!
     * \brief AddOffer dodaje ofertę sprzedaży
     * \param _offer oferta do dodania
     */
    void AddOffer(Order *_offer = new Order());
    /*!
     * \brief AccomplishTransaction realizuje transakcję sprzedaży węgla oferowanego przez gracza
     * \param offer oferta gracza
     * \return niesprzedany węgiel
     */
    Order* AccomplishTransaction(Order *offer);
    /*!
     * \brief GetStats
     * \return zwraca statystyki rynku
     */
    Order* GetStats();
};

#endif //MARKET_H
