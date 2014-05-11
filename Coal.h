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
    void SetPrice(double _price);
    void SetAmount(double _amount);
    void Add(double _amount);
    void Substract(double _amount);
};

#endif // COAL_H
