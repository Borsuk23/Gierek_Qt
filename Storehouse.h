#pragma once
#include "CoalTypeA.h"
#include "CoalTypeB.h"
/*!
 * \brief The Storehouse class klasa reprezentująca magazyn węgla
 */
class Storehouse
{
private:
    double cost; //!koszt jednostkowy składowania węgla
    CoalTypeA *storageA;    //! pojemność magazynu (węgiel typu A)
    CoalTypeB *storageB;    //! pojemność magazynu (węgiel typu B)
    CoalTypeA *coalA; //! składowany węgiel typu A
    CoalTypeB *coalB; //! składowany węgiel typu B
public:
    /*!
     * \brief Storehouse konstruktor domyślny
     */
    Storehouse();
    /*!
     * \brief Storehouse konstruktor sparametryzowany
     * \param _difficulty poziom trudności
     */
    Storehouse(int _difficulty);
    /*!
     * \brief StoreCoal składuje węgiel
     * \param _coalA węgiel typu A do składowania
     */
    void StoreCoal(CoalTypeA *_coalA);
    /*!
     * \brief StoreCoal składuje węgiel
     * \param _coalB węgiel typu B do składowania
     */
    void StoreCoal(CoalTypeB *_coalB);
    /*!
     * \brief TakeCoal pobiera węgiel ze składu
     * \param _coalA ilość węgla typu A jaką chcemy zabrać
     * \return ile udało się nam zabrać
     */
    CoalTypeA* TakeCoal(CoalTypeA *_coalA);
    /*!
     * \brief TakeCoal pobiera węgiel ze składu
     * \param coalB ilość węgla typu B jaką chcemy zabrać
     * \return ile udało się nam zabrać
     */
    CoalTypeB* TakeCoal(CoalTypeB *_coalB);
    /*!
     * \brief GetStorageCost
     * \return koszt składowania węgla
     */
	double GetStorageCost();
    /*!
     * \brief ExtendStorage rozbudowa magazynu
     * \param _coalA rodzaj węgla
     * \param _budget budżet kopalni
     * \return  ile pozostało pieniędzy
     */
    double ExtendStorage(CoalTypeA const *_coalA, double _budget);
    /*!
     * \brief ExtendStorage rozbudowa magazynu
     * \param _coalB rodzaj węgla
     * \param _budget budżet kopalni
     * \return  ile pozostało pieniędzy
     */
    double ExtendStorage(CoalTypeB const *_coalB, double _budget);
    /*!
     * \brief GetStorageAmount
     * \param _coalA rodzaj węgla
     * \return pojemność magazynu
     */
    double GetStorageAmount(CoalTypeA const *_coalA);
    /*!
     * \brief GetStorageAmount
     * \param _coalB rodzaj węgla
     * \return pojemność magazynu
     */
    double GetStorageAmount(CoalTypeB const *_coalB);
    /*!
     * \brief GetStoredCoal
     * \param _coalA rodzaj węgla
     * \return ilość składowanego węgla
     */
    double GetStoredCoal(CoalTypeA const *_coalA);
    /*!
     * \brief GetStoredCoal
     * \param _coalB rodzaj węgla
     * \return ilość składowanego węgla
     */
    double GetStoredCoal(CoalTypeB const *_coalB);
};

