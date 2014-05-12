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
    this->market = new Market();
    for(int i=0; i<numberOfMines; i++)
    {
        this->mines.push_back(new AI());
    }

    for(int i=0; i<numberOfMines; i++)
    {
        this->clients.push_back(new Client());
    }
}

bool Game::PlayTurn( )
{
    for(int i =0; i<this->mines.size(); i++)
    {
        this->GetMarket()->AddOffer(this->mines[i]->SellOffer());
    }
    //this->GetPlayer()->SetSalary();
  //  this->GetPlayer()->SetExtraction(double _coalA, double _coalB);
  //  this->GetPlayer()->SetSell();
  //  this->GetPlayer()->GetMine()->MineCoal();

    this->date++;
    return true;
}

bool Game::EndGame(QWidget *_mainWindow)
{
    QMessageBox *gameEnd = new QMessageBox();
    gameEnd->about(0,"KONIEC", "wygrales");
    return true;
}

int Game::GetDate()
{
    return this->date;
}

double Game::Completed()
{
    return (double)(100*this->date/this->gameLenght);
}

Player* Game::GetPlayer()
{
   return this->player;
}

Market* Game::GetMarket()
{
    return this->market;
}

QList<AI*> Game::GetMines()
{
    return this->mines;
}

QList<Client*> Game::GetClients()
{
    return this->clients;
}





