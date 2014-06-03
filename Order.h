#pragma once
#include "CoalTypeA.h"
#include "CoalTypeB.h"

/*!
 * \brief The Order class klasa reprezentująca zamówienie
 */
class Order
{
private:
    CoalTypeA *coalA; //! węgiel typu A
    CoalTypeB *coalB; //! węgiel typu B

public:
    /*!
     * \brief Order konstruktor domyślny
     */
	Order();
    /*!
     * \brief Order konstruktor sparametryzowany - przyjmuje zadane ilośći i ceny węgla
     * \param _coalA węgiel typu A
     * \param _coalB węgiel typu B
     */
    Order(CoalTypeA *_coalA, CoalTypeB *_coalB);
    /*!
     * \brief GetCoalA
     * \return węgiel typu A wchodzący w skład zamównienia
     */
    CoalTypeA* GetCoalA();
    /*!
     * \brief GetCoalB
     * \return węgiel typu B wchodzący w skład zamównienia
     */
    CoalTypeB* GetCoalB();
    /*!
     * \brief SetCoalA ustawia ilośc i cenę węgla typu A w zamówieniu
     * \param _coal zadany węgiel
     */
    void SetCoalA(CoalTypeA *_coal);
    /*!
     * \brief SetCoalB ustawia ilośc i cenę węgla typu B w zamówieniu
     * \param _coal zadany węgiel
     */
    void SetCoalB(CoalTypeB *_coal);

};

