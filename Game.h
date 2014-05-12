#ifndef GAME_H
#define GAME_H

#include "Market.h"
#include "Player.h"
#include "AI.h"
#include "Client.h"
#include <qvector.h>
#include <QWidget>


class Game
{
private:
    int date;
    int gameID;
    int gameDifficulty;
    int gameLenght;
    int numberOfMines;
    Market *market;
    Player *player;
    QList<AI*> mines;
    QList<Client*> clients;

public:
    Game();
    Game(int _difficulty, int _lenght, QString _name);
    bool PlayTurn();
    bool EndGame(QWidget *_mainWindow);
    int GetDate();
    double Completed();
    Player* GetPlayer();
    Market* GetMarket();
    QList<AI*> GetMines();
    QList<Client*> GetClients();



};

#endif //GAME_H
