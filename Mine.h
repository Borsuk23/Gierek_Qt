#pragma once
#include "Miner.h"
#include "Market.h"
#include "Order.h"
#include "Storehouse.h"
class Mine
{
private:
    QString name;
    double budget;
    int salary;
    QList<Miner*> miners;
    Storehouse *storage;
    CoalTypeA *extractCoalA;
    CoalTypeB *extractCoalB;
    CoalTypeA *sellCoalA;
    CoalTypeB *sellCoalB;
public:
    Mine();
    Mine(int _difficulty);
    QString GetName();
    double GetBudget();
    double GetCurrentSalary();
    double GetOverallSalary();
    void SetSalary(double _salary);
    QList<Miner*> GetMiners();
    Storehouse* GetStorehouse();
    void SetCoalAExtraction(double _amount);
    void SetCoalBExtraction(double _amount);
    void SetCoalASell(double _amount, double _price);
    void SetCoalBSell(double _amount, double _price);
    void SetBudget(double _budget);
    void CheckCrew();
    double GetMorale();
    double CalculateExtraction(CoalTypeA const *coal);
    double CalculateExtraction(CoalTypeB const *coal);
    void HireWorker();
    void MineCoal(CoalTypeA *_coalA, CoalTypeB *_coalB);
    bool PaySalary();
    bool PayStorageCost();
    bool PlayTurn(Market *_market);

};

