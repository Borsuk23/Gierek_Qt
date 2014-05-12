#ifndef COAL_H
#define COAL_H

class Coal
{
protected:
    double amount;
    double price;
public:
    Coal();
    Coal(double _amount, double _price);
    double GetAmount();
    double GetPrice();
    void SetAmount(double _amount);
    void SetPrice(double _price);
    void Add(double _amount);
    double Substract(double _amount);
};

#endif // COAL_H
