#include "Game.h"


Game::Game()
{
}

Game::Game(int _difficulty, int _lenght, QString _name)
{
    this->date = 0;
	this->gameID = 1;
    this->gameDifficulty = _difficulty;
    this->gameLenght = _lenght;
    this->numberOfMines = _difficulty * 10;
    this->player = new Player(_name);
    this->market = new Market(this->gameDifficulty);
   // for(int i=0; i<numberOfMines; i++)
  //  {
   //     this->mines.push_back(new AI());
 //   }
}

int Game::GetGameID()
{
    return this->gameID;
}

Player* Game::GetPlayer()
{
   return this->player;
}

Market* Game::GetMarket()
{
    return this->market;
}
