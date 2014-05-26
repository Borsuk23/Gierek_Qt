#ifndef DATASEED_H
#define DATASEED_H
#include "CommonIncludes.h"

class DataSeed
{
public:
    DataSeed();
    QList<QString> ReadPlayersList();
    bool AddPlayer(QString _name);
    QString ReadPlayerStats(QString _name);
    bool UpdatePlayerStats(QString _name, bool _won, double _score);
};

#endif // DATASEED_H