#include "Storehouse.h"


Storehouse::Storehouse()
{
    this->coalA = new CoalTypeA(10000,0);
    this->coalB = new CoalTypeB(5000,0);
	this->storageA = new CoalTypeA(50000, 0);
	this->storageB = new CoalTypeB(30000, 0);
    this->cost = 0.5;
}

Storehouse::Storehouse(int _difficulty)
{
    if(_difficulty==1){
        this->coalA = new CoalTypeA(10000,0);
        this->coalB = new CoalTypeB(5000,0);
        this->storageA = new CoalTypeA(50000, 0);
        this->storageB = new CoalTypeB(30000, 0);
        this->cost = 0.5;
    }else if(_difficulty==2){
        this->coalA = new CoalTypeA(4000,0);
        this->coalB = new CoalTypeB(2000,0);
        this->storageA = new CoalTypeA(40000, 0);
        this->storageB = new CoalTypeB(20000, 0);
        this->cost = 1;
    }else if(_difficulty==3){
        this->coalA = new CoalTypeA(0,0);
        this->coalB = new CoalTypeB(0,0);
        this->storageA = new CoalTypeA(30000, 0);
        this->storageB = new CoalTypeB(10000, 0);
        this->cost = 1.5;
    }

}

void Storehouse::StoreCoal(CoalTypeA *_coalA)
{
    if (_coalA->GetAmount() <= (this->storageA->GetAmount() - this->coalA->GetAmount()))
    {
        this->coalA->Add(_coalA->Substract(_coalA->GetAmount()));
    }
    else
    {
        this->coalA->Add(_coalA->Substract((this->storageA->GetAmount() - this->coalA->GetAmount())));
    }
}

/*!
 * \brief Storehouse::StoreCoal - składowanie węgla w magazynie
 * \param _coalB - podajemy ile węgla B chcemy zmagazynować
 * \return zwraca ilość węgla, która się nie zmieściła
 */
void Storehouse::StoreCoal(CoalTypeB *_coalB)
{
    if (_coalB->GetAmount() <= (this->storageB->GetAmount() - this->coalB->GetAmount()))
    {
        this->coalB->Add(_coalB->Substract(_coalB->GetAmount()));
    }
    else
    {
        this->coalB->Add(_coalB->Substract((this->storageB->GetAmount() - this->coalB->GetAmount())));
    }
}


/*!
 * \brief Storehouse::TakeCoal - zabranie węgla z magazynu
 * \param _coalA - podajemy ile węgla A chcemy
 * \return zwraca ilość która chcieliśmy lub która mamy w magazynie
 */
CoalTypeA* Storehouse::TakeCoal(CoalTypeA *_coalA)
{
    if (_coalA->GetAmount() < this->coalA->GetAmount())
    {
        this->coalA->Substract(coalA->GetAmount());
        return _coalA;
    }
    else
    {
        _coalA->SetAmount(this->coalA->GetAmount());
        this->coalA->SetAmount(0);
        return _coalA;
    }
}

/*!
 * \brief Storehouse::TakeCoal - zabranie węgla z magazynu
 * \param _coalB - podajemy ile węgla B chcemy
 * \return zwraca ilość która chcieliśmy lub która mamy w magazynie
 */
CoalTypeB* Storehouse::TakeCoal(CoalTypeB *_coalB)
{
    if (_coalB->GetAmount() < this->coalB->GetAmount())
    {
        this->coalB->Substract(coalB->GetAmount());
        return _coalB;
    }
    else
    {
        _coalB->SetAmount(this->coalB->GetAmount());
        this->coalB->SetAmount(0);
        return _coalB;
    }
}

/*!
 * \brief Storehouse::GetStorageCost wylicza koszt magazynowania
 * \return zwraca koszt składowania węgla
 */
double Storehouse::GetStorageCost()
{
	double amount = 0;
    amount += coalA->GetAmount();
    amount += coalB->GetAmount();
    return this->cost*amount;
}

/*!
 * \brief Storehouse::ExtendStorage rozbudowa magazynu
 * \param _coalA wybrany rodzaj węgla
 * \param _budget podany budżet gracza
 * \return budżet po rozbudowie
 */
double Storehouse::ExtendStorage(CoalTypeA const *_coalA, double _budget)
{
    if (_budget > 100000)
    {
        _budget -= 100000;
        storageA->Add(100000);
        return _budget;
    }
    else
        return _budget;
}

/*!
 * \brief Storehouse::ExtendStorage rozbudowa magazynu
 * \param _coalB wybrany rodzaj węgla
 * \param _budget podany budżet gracza
 * \return budżet po rozbudowie
 */
double Storehouse::ExtendStorage(CoalTypeB const *_coalB, double _budget)
{
    if (_budget > 100000)
    {
        _budget -= 100000;
        storageB->Add(100000);
        return _budget;
    }
    else
        return _budget;
}

/*!
 * \brief Storehouse::GetStorageAmount pojemność magazynu
 * \param _coalA typ węgla podany przez użytkownika
 * \return zwraca pojemność
 */
double Storehouse::GetStorageAmount(CoalTypeA const *_coalA)
{
    return this->storageA->GetAmount();
}

/*!
 * \brief Storehouse::GetStorageAmount pojemność magazynu
 * \param _coalA typ węgla podany przez użytkownika
 * \return zwraca pojemność
 */
double Storehouse::GetStorageAmount(CoalTypeB const *_coalA)
{
    return this->storageB->GetAmount();
}

/*!
 * \brief Storehouse::GetStoredCoal zmagazynowany węgiel
 * \param _coal typ węgla podany przez użytkownika
 * \return ilość zmagazynowanego węgla
 */
double Storehouse::GetStoredCoal(CoalTypeA const *_coal)
{
    return this->coalA->GetAmount();
}

/*!
 * \brief Storehouse::GetStoredCoal zmagazynowany węgiel
 * \param _coal typ węgla podany przez użytkownika
 * \return ilość zmagazynowanego węgla
 */
double Storehouse::GetStoredCoal(CoalTypeB const *_coal)
{
    return this->coalB->GetAmount();
}
