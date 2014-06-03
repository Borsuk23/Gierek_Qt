#ifndef COAL_H
#define COAL_H

/*!
 * \brief The Coal class klasa nadrzędna dla rodzajów węgla
 */
class Coal
{
protected:
    double amount; //! ilość
    double price; //! cena
public:
    /*!
     * \brief Coal domyślny konstruktor (inicjuje 0 wszystkie pola)
     */
    Coal();
    /*!
     * \brief Coal konstruktor sparametryzowany
     * \param _amount ilość węgla
     * \param _price cena węgla
     */
    Coal(double _amount, double _price);
    /*!
     * \brief GetAmount
     * \return zwraca ilość węgla
     */
    double GetAmount();
    /*!
     * \brief GetPrice
     * \return zwraca cenę węgla
     */
    double GetPrice();
    /*!
     * \brief SetAmount ustawia ilość węgla
     * \param _amount zadana ilość węgla
     */
    void SetAmount(double _amount);
    /*!
     * \brief SetPrice ustawia cena węgla
     * \param _price zadana cena węgla
     */
    void SetPrice(double _price);
    /*!
     * \brief Add dodaje do istniejącego węgla
     * \param _amount ilość do dodania
     */
    void Add(double _amount);
    /*!
     * \brief Substract zabiera z istniejącego węgla
     * \param _amount ilość którą chcemy pobrać
     * \return ilość którą udało się zabrać
     */
    double Substract(double _amount);
};

#endif // COAL_H
