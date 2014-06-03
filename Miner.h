#pragma once
#include "CoalTypeA.h"
#include "CoalTypeB.h"
#include "CommonIncludes.h"
/*!
 * \brief The Miner class klasa reprezentująca górnika
 */
class Miner
{
private :
    QString name;   //! imię
    int experience; //! doświadczenie
    double morale;  //! morale
public:
    /*!
     * \brief Miner domyślny konstruktor
     */
	Miner();
    /*!
     * \brief Miner konstruktor sparametryzowany
     * \param _name imię
     */
    Miner(QString _name);
    /*!
     * \brief GetName
     * \return imię
     */
    QString GetName();
    /*!
     * \brief GetMorale
     * \return  morale
     */
    double GetMorale();
    /*!
     * \brief MineCoal wydobywa węgiel
     * \param _coal typ węgla do wydobycia
     */
    void MineCoal(CoalTypeA *_coal);
    /*!
     * \brief MineCoal wydobywa węgiel
     * \param _coal typ węgla do wydobycia
     */
    void MineCoal(CoalTypeB *_coal);
    /*!
     * \brief GetEfficiency oblicza wydajność pracy
     * \param _coal typ węgla
     * \return ilość węgla, który może zostać wydobyty
     */
    double GetEfficiency(CoalTypeA const *_coal);
    /*!
     * \brief GetEfficiency oblicza wydajność pracy
     * \param _coal typ węgla
     * \return ilość węgla, który może zostać wydobyty
     */
    double GetEfficiency(CoalTypeB const *_coal);
    /*!
     * \brief Strike test na strajk
     * \return czy strajkuje?
     */
	bool Strike();
    /*!
     * \brief Dismissal test na wypowiedzenie pracy
     * \return czy wypowiada prace?
     */
	bool Dismissal();
    /*!
     * \brief MoraleUpdate uaktualnia morale pracownika
     * \param _salary obecna płaca
     * \return obecne morale
     */
    double MoraleUpdate(double _salary);
};

