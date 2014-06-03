#include "Game.h"
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
    this->player = new Player(_name, _difficulty);

    for(int i=0; i<numberOfMines; i++)
    {
        this->mines.push_back(new AI());
    }

    for(int i=0; i<5; i++)
    {
        this->clients.push_back(new Ironworks(_difficulty));
    }
    for(int i=0; i<5; i++)
    {
        this->clients.push_back(new PowerStation(_difficulty));
    }
    for(int i=0; i<50; i++)
    {
        this->clients.push_back(new CoalDeposit(_difficulty));
    }
    for(int i=0; i<10; i++)
    {
        this->clients.push_back(new HeatingPlant(_difficulty));
    }

    this->market = new Market();
    for(int i =0; i<this->mines.size(); i++)
    {
        this->GetMarket()->AddOffer(this->mines.at(i)->SellOffer());
    }
    for(int i=0; i<this->clients.size(); i++)
    {
        this->market->AddOrder(this->clients.at(i)->MakeOrder(this->date));
    }

}

bool Game::PlayTurn(double _salary, CoalTypeA *_extractCoalA, CoalTypeB *_extractCoalB,CoalTypeA *_saleCoalA,CoalTypeB *_saleCoalB)
{
    //refresh Market
    delete this->market;
    this->market=new Market();
    for(int i =0; i<this->mines.size(); i++)
    {
        this->GetMarket()->AddOffer(this->mines.at(i)->SellOffer());
    }
    for(int i=0; i<this->clients.size(); i++)
    {
        this->market->AddOrder(this->clients.at(i)->MakeOrder(this->date));
    }


    this->GetPlayer()->SetSalary(_salary);
    this->GetPlayer()->SetExtraction(_extractCoalA, _extractCoalB);
    this->GetPlayer()->SetSell(_saleCoalA, _saleCoalB);
    this->GetPlayer()->AddPoint(this->GetPlayer()->GetMine()->PlayTurn(this->market));

    if(this->GetPlayer()->GetMine()->GetBudget()<=0)
    {
        return false;
    }
    this->date++;
    return true;
}

bool Game::EndGame()
{
    if(this->date>=this->gameLenght)
    {
        QMessageBox *gameEnd = new QMessageBox();
        gameEnd->about(0,"KONIEC", "Wygraleś! \nTwój wynik:"+QString::number(this->GetPlayer()->GetScore()));
        return true;
    }
    else
        return false;
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





