#include "Mine.h"
#include <QMessageBox>

#include "CommonIncludes.h"


Mine::Mine()
{
    this->name="Moja kopalnia";
    this->salary=1000;
    this->budget=1000000;
    this->storage= new Storehouse();
    this->extractCoalA = new CoalTypeA();
    this->extractCoalB = new CoalTypeB();
    this->sellCoalA = new CoalTypeA(5000,500);
    this->sellCoalB = new CoalTypeB(4000,400);

    for(int i=0; i<50;i++)
    {
       HireWorker();
    }
}
Mine::Mine(int _difficulty)
{
    this->name="Moja kopalnia";
    this->salary=1000;
    this->budget=1000000+(2-_difficulty)*250000;
    this->storage= new Storehouse(_difficulty);
    this->extractCoalA = new CoalTypeA();
    this->extractCoalB = new CoalTypeB();
    this->sellCoalA = new CoalTypeA(5000,500);
    this->sellCoalB = new CoalTypeB(4000,400);

    for(int i=0; i<((6-_difficulty)*10);i++)
    {
       HireWorker();
    }
}

QString Mine::GetName()
{
    return this->name;
}

double Mine::GetBudget()
{
    return this->budget;
}

double Mine::GetCurrentSalary()
{
    return this->salary;
}

double Mine::GetOverallSalary()
{
    return (this->miners.count()*this->salary);
}

void Mine::SetSalary(double _salary)
{
    this->salary=_salary;
}

QList<Miner*> Mine::GetMiners()
{
    return this->miners;
}

Storehouse* Mine::GetStorehouse()
{
    return this->storage;
}

void Mine::SetCoalAExtraction(double _amount)
{
    this->extractCoalA->SetAmount(_amount);
}

void Mine::SetCoalBExtraction(double _amount)
{
    this->extractCoalB->SetAmount(_amount);
}

void Mine::SetCoalASell(double _amount, double _price)
{
    this->sellCoalA->SetAmount(_amount);
    this->sellCoalA->SetPrice(_price);
}

void Mine::SetCoalBSell(double _amount, double _price)
{
    this->sellCoalB->SetAmount(_amount);
    this->sellCoalB->SetPrice(_price);
}

void Mine::SetBudget(double _budget)
{
    this->budget=_budget;
}

void Mine::CheckCrew()
{
    for (int i=0; i<miners.size(); i++)
    {
        if (!miners.at(i)->Dismissal())
        {
            miners.removeAt(i);
        }
    }

}

double Mine::GetMorale()
{
    double morale=0;

    for(int i=0; i<this->miners.count(); i++)
    {
        morale+=this->miners[i]->GetMorale();
    }
    morale/=(this->miners.count());

    return morale;
}


double Mine::CalculateExtraction(CoalTypeA const *_coalA)
{
    double extraction=0;
    for (int i=0; i<this->miners.count(); i++)
    {
        extraction+=this->miners[i]->GetEfficiency(_coalA);
    }
    return extraction;
}

double Mine::CalculateExtraction(CoalTypeB const *_coalB)
{
    double extraction=0;
    for (int i=0; i<this->miners.count(); i++)
    {
        extraction+=this->miners[i]->GetEfficiency(_coalB);
    }
    return extraction;
}
void Mine::HireWorker()
{
    QList<QString> names;
    names << "Zenon" << "Michał" << "Kazimierz" << "Piotr" << "Paweł" <<"Radek" <<"Łukasz" << "Andrzej" << "Rafał" << "Jakub"<<"Wojciech"<<"Józef";

    this->miners.append(new Miner(names.at(rand()%names.size())));
}

void Mine::MineCoal(CoalTypeA *_coalA, CoalTypeB *_coalB)
{

    for(int i=0; i<miners.size();i++)
    {
        if (_coalA->GetAmount() < extractCoalA->GetAmount())
        {
            miners.at(i)->MineCoal(_coalA);

        }
        else
        {
            miners.at(i)->MineCoal(_coalB);
        }
    }
}

bool Mine::PaySalary()
{
	this->budget -= miners.size()*salary;
	if (budget < 0)
	{
		budget = 0;
        return false;
	}
    return true;
}

bool Mine::PayStorageCost()
{
    this->budget-=this->storage->GetStorageCost();
    if(this->budget<0)
    {
        this->budget=0;
        return false;
    }
    else
        return true;
}

/*!
 * \brief Mine::PlayTurn funkcja odpowiadająca za comiesięczną pracę kopalni wg ustaleń gracza
 * \param _market przyjmuje rynek z którym współpracuje
 * \return czy udało się pomyślnie rozegrać miesiąc
 */
bool Mine::PlayTurn(Market *_market)
{
    CoalTypeA *coalA = new CoalTypeA();
    CoalTypeB *coalB = new CoalTypeB();
    Order *coal= new Order();

    double earned=0;

    coal->GetCoalA()->SetPrice(this->sellCoalA->GetPrice());
    coal->GetCoalB()->SetPrice(this->sellCoalB->GetPrice());

    //wydobicie węgla
    MineCoal(coalA, coalB);

    //wydobyto za mało
    if(coalA->GetAmount()<this->sellCoalA->GetAmount())
    {
        coalA->Add(this->storage->TakeCoal(new CoalTypeA(this->sellCoalA->GetAmount()-coalA->GetAmount(),0))->GetAmount());
        coal->GetCoalA()->Add(coalA->Substract(coalA->GetAmount()));
    }
    else //wydobyto wiecej
    {
        coal->GetCoalA()->Add(coalA->Substract(this->sellCoalA->GetAmount()));
        this->storage->StoreCoal(coalA);
    }
    if(coalB->GetAmount()<this->sellCoalB->GetAmount())
    {
        coalB->Add(this->storage->TakeCoal(new CoalTypeA(this->sellCoalB->GetAmount()-coalB->GetAmount(),0))->GetAmount());
        coal->GetCoalB()->Add(coalB->Substract(coalB->GetAmount()));
    }
    else
    {
        coal->GetCoalB()->Add(coalB->Substract(this->sellCoalB->GetAmount()));
        this->storage->StoreCoal(coalB);
    }

    //prognozowane zarobki
    earned+=coal->GetCoalA()->GetAmount()*coal->GetCoalA()->GetPrice();
    earned+=coal->GetCoalB()->GetAmount()*coal->GetCoalB()->GetPrice();

    coal=_market->AccomplishTransaction(coal);

    //korekta zarobków i magazynowanie nadwyżek
    if(coal->GetCoalA()->GetAmount()>0)
    {
        earned-=coal->GetCoalA()->GetAmount()*coal->GetCoalA()->GetPrice();
        this->storage->StoreCoal(coal->GetCoalA());
    }
    if(coal->GetCoalB()->GetAmount()>0)
    {
        earned-=coal->GetCoalB()->GetAmount()*coal->GetCoalB()->GetPrice();
        this->storage->StoreCoal(coal->GetCoalB());
    }

    //przelew zysków
    this->budget+=earned;


    if(PaySalary()&&PayStorageCost())
    {/*
        QMessageBox *endTurnMessageBox = new QMessageBox();
        QString endTurnMessage("Podsumowanie miesiąca: ");
        endTurnMessage.append("sprzedano węgla: ");
        endTurnMessage.append(QString::number(this->sellCoalA->GetAmount()));
        endTurnMessageBox->setText();*/
        delete coalA;
        delete coalB;
        delete coal;
        return true;
    }
    //wyswietlic komunikat z tura!
    else
    {
        delete coalA;
        delete coalB;
        delete coal;
        return false;
    }

}


