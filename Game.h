#ifndef GAME_H
#define GAME_H

#include "Market.h"
#include "Player.h"
#include "AI.h"
#include "Client.h"
#include "Ironworks.h"
#include "PowerStation.h"
#include "CoalDeposit.h"
#include "HeatingPlant.h"
#include <QWidget>

/*!
 * \brief The Game class klasa reprezentująca instację gry
 * odpowiada za prowadzenie rozgrywki
 * przetwarza polecenia użytkownika
 */
class Game
{
private:
    int date; //! czas gry
    int gameID; //! id gry
    int gameDifficulty; //! poziom trudności
    int gameLenght; //!wybrana długość gry
    int numberOfMines;  //!ilość konkurencyjnych kopalni
    Market *market; //!rynek
    Player *player; //!gracz
    QList<AI*> mines;   //!konkurencyjne kopalnie
    QList<Client*> clients; //!klienci

public:
    /*!
     * \brief Game domyślny konstruktor
     */
    Game();
    /*!
     * \brief Game konstruktor sparametryzowany
     * \param _difficulty poziom trudności
     * \param _lenght długość gry
     * \param _name imię gracza
     */
    Game(int _difficulty, int _lenght, QString _name);
    /*!
     * \brief PlayTurn zagranie tury
     * \param _salary ustawiona płaca
     * \param _extractCoalA ustawione wydobycie węgla typu A
     * \param _extractCoalB ustawione wydobycie węgla typu B
     * \param _saleCoalA ustawiona sprzedaż węgla typu A
     * \param _saleCoalB ustawiona sprzedaż węgla typu B
     * \return czy udało się zagrać turę
     */
    bool PlayTurn(double _salary, CoalTypeA *_extractCoalA, CoalTypeB *_extractCoalB,CoalTypeA *_saleCoalA,CoalTypeB *_saleCoalB);
    /*!
     * \brief EndGame sprawdza czy gra dobiegła końca
     * \return czy koniec gry
     */
    bool EndGame();
    /*!
     * \brief GetDate
     * \return obecną datę
     */
    int GetDate();
    /*!
     * \brief Completed sprawdza ukończenie gry
     * \return procent ukończenia gry
     */
    double Completed();
    /*!
     * \brief GetPlayer
     * \return instancję gracza
     */
    Player* GetPlayer();
    /*!
     * \brief GetMarket
     * \return instację rynku
     */
    Market* GetMarket();
    /*!
     * \brief GetMines
     * \return listę konkurencyjnych kopalni
     */
    QList<AI*> GetMines();
    /*!
     * \brief GetClients
     * \return listę klientów
     */
    QList<Client*> GetClients();
};

#endif //GAME_H
