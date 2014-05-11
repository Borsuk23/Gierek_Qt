#pragma once
#include "Market.h"
#include "Player.h"
#include "AI.h"
#include <qvector.h>
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
    QVector<AI*> mines;
public:
    Game();
    Game(int _difficulty, int _lenght, QString _name);
    void PlayTurn();
    void EndGame();
    int GetGameID();
    Player* GetPlayer();
    Market* GetMarket();

};

