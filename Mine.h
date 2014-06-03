#pragma once
#include "Miner.h"
#include "Market.h"
#include "Order.h"
#include "Storehouse.h"
/*!
 * \brief The Mine class klasa odpowiadająca kopalni
 * zajmuje się wydobyciem węgla i obsługą kadry
 */
class Mine
{
private:
    QString name; //! nazwa
    double budget; //! budżet
    int salary; //! płaca
    QList<Miner*> miners; //! lista górników
    Storehouse *storage; //! magazyn
    CoalTypeA *extractCoalA;    //! wydobycie węgla typu A
    CoalTypeB *extractCoalB; //! wydobycie węgla typu B
    CoalTypeA *sellCoalA; //! sprzedaż węgla typu A
    CoalTypeB *sellCoalB; //! sprzedaż węgla typu B
public:
    /*!
     * \brief Mine domyślny kontruktor
     */
    Mine();
    /*!
     * \brief Mine konstruktor sparametryzowany zależny od poziomu trudności
     * \param _difficulty poziom trudności
     */
    Mine(int _difficulty);
    /*!
     * \brief GetName
     * \return zwraca nazwę
     */
    QString GetName();
    /*!
     * \brief GetBudget
     * \return zwraca budżet
     */
    double GetBudget();
    /*!
     * \brief GetCurrentSalary
     * \return zwraca obecną płacę
     */
    double GetCurrentSalary();
    /*!
     * \brief GetOverallSalary
     * \return zwraca skumulowaną płacę wszystkich pracowników
     */
    double GetOverallSalary();
    /*!
     * \brief SetSalary ustala wartość płacy
     * \param _salary nowa płaca
     */
    void SetSalary(double _salary);
    /*!
     * \brief GetMiners
     * \return zwraca listę górników
     */
    QList<Miner*> GetMiners();
    /*!
     * \brief GetStorehouse
     * \return instację magazynu
     */
    Storehouse* GetStorehouse();
    /*!
     * \brief SetCoalAExtraction określa wydobycie węgla typu A
     * \param _amount żądana ilość
     */
    void SetCoalAExtraction(double _amount);
    /*!
     * \brief SetCoalBExtraction określa wydobycie węgla typu B
     * \param _amount żądana ilość
     */
    void SetCoalBExtraction(double _amount);
    /*!
     * \brief SetCoalASell określa sprzedaż węgla typu A
     * \param _amount żądana ilość
     * \param _price żądana cena
     */
    void SetCoalASell(double _amount, double _price);
    /*!
     * \brief SetCoalBSell określa sprzedaż węgla typu B
     * \param _amount żądana ilość
     * \param _price żądana cena
     */
    void SetCoalBSell(double _amount, double _price);
    /*!
     * \brief SetBudget ustala budżet kopalni
     * \param _budget budżet
     */
    void SetBudget(double _budget);
    /*!
     * \brief CheckCrew sprawdzenie załogi
     * przegląd górników pod kątem wypowiedzeń
     */
    void CheckCrew();
    /*!
     * \brief GetMorale
     * \return średnie morale górników
     */
    double GetMorale();
    /*!
     * \brief CalculateExtraction liczy możliwe wydobycie
     * \param coal rodzaj węgla
     * \return ilość możliwą do wydobycia
     */
    double CalculateExtraction(CoalTypeA const *coal);
    /*!
     * \brief CalculateExtraction liczy możliwe wydobycie
     * \param coal rodzaj węgla
     * \return ilość możliwą do wydobycia
     */
    double CalculateExtraction(CoalTypeB const *coal);
    /*!
     * \brief HireWorker zatrudnienie nowego pracownika
     */
    void HireWorker();
    /*!
     * \brief NoticeWorker redukcja etatu
     */
    void NoticeWorker();
    /*!
     * \brief MineCoal wydobywa węgiel
     * \param _coalA węgiel do wydobycia typ A
     * \param _coalB węgiel do wydobycia typ B
     */
    void MineCoal(CoalTypeA *_coalA, CoalTypeB *_coalB);
    /*!
     * \brief PaySalary wypłaca wynagrodzenie
     * \return czy udało się wypłacić
     */
    bool PaySalary();
    /*!
     * \brief PayStorageCost opłaca koszt składowania węgla
     * \return czy udało się opłacić
     */
    bool PayStorageCost();
    /*!
     * \brief Mine::PlayTurn funkcja odpowiadająca za comiesięczną pracę kopalni wg ustaleń gracza
     * \param _market przyjmuje rynek z którym współpracuje
     * \return czy udało się pomyślnie rozegrać miesiąc
     */
    double PlayTurn(Market *_market);

};

