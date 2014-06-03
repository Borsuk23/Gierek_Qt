#pragma once
#include "CommonIncludes.h"
#include "Mine.h"

/*!
 * \brief The Player class klasa odpowiedzialna za działania gracza
 */
class Player
{
private:
    QString name; //! imię
    double score; //! wynik
    Mine *mine; //! kopalnia której jest właścicielem
public:
    /*!
     * \brief Player konstruktor domyślny
     */
	Player();
    /*!
     * \brief Player konstruktor sparametryzowany
     * \param _name imię
     * \param _difficulty poziom trudności
     */
    Player(QString _name, int _difficulty=0);
    /*!
     * \brief GetMine
     * \return instację kopalni
     */
    Mine* GetMine();
    /*!
     * \brief GetName
     * \return imię
     */
    QString GetName();
    /*!
     * \brief GetScore
     * \return wynik
     */
    double GetScore();
    /*!
     * \brief SetExtraction ustala wydobycie węgla (ilość)
     * \param _coalA węgiel typu A
     * \param _coalB węgiel typu B
     */
    void SetExtraction(CoalTypeA *_coalA, CoalTypeB *_coalB);
    /*!
     * \brief SetSell ustala sprzedaż węgla (ilość i cenę)
     * \param _coalA węgiel typu A
     * \param _coalB węgiel typu B
     */
    void SetSell(CoalTypeA *_coalA, CoalTypeB *_coalB);
    /*!
     * \brief SetSalary ustala płacą
     * \param _salary nowa płąca
     */
    void SetSalary(double _salary);
    /*!
     * \brief HireMiner zatrudnienie pracownika
     */
    void HireMiner();
    /*!
     * \brief NoticeMiner zwolnienie pracownika
     */
    void NoticeMiner();
    /*!
     * \brief AddPoint dodanie punktów do wyniku
     * \param _points liczba punktów
     */
    void AddPoint(double _points);
};

