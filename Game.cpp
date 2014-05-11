#include "Game.h"
#include "mainwindow.h"
#include <QMessageBox>


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
    for(int i=0; i<numberOfMines; i++)
    {
        this->mines.push_back(new AI());
    }
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

bool Game::PlayTurn(double _salary)
{
    for(int i =0; i<this->mines.size(); i++)
    {
        this->GetMarket()->AddOffer(this->mines[i]->SellOffer());
    }
    this->GetPlayer()->SetSalary(_salary);
  //  this->GetPlayer()->SetExtraction();
  //  this->GetPlayer()->SetSell();
  //  this->GetPlayer()->GetMine()->MineCoal();

    this->date++;
    if(this->date>=this->gameLenght)
        this->EndGame();
}

int Game::GetDate()
{
    return this->date;
}

double Game::Completed()
{
    return (double)(100*this->date/this->gameLenght);
}

void Game::EndGame()
{
    QMessageBox *gameEnd = new QMessageBox();
    gameEnd->about(0,"KONIEC", "wygrales");
}
