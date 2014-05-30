#ifndef DATASEED_H
#define DATASEED_H
#include "CommonIncludes.h"
#include <QFile>
#include <QTextStream>

class DataSeed
{
public:
    static QList<QString> ReadPlayersList();
    static bool AddPlayer(QString _name);
    static double random(double _base, int _difference);
};

#endif // DATASEED_H
