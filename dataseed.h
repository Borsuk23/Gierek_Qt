#ifndef DATASEED_H
#define DATASEED_H
#include "CommonIncludes.h"
#include <QFile>
#include <QTextStream>
/*!
 * \brief The DataSeed class klasa zapewniająca statyczne metody do odczytu danych
 */
class DataSeed
{
public:
    static QList<QString> ReadPlayersList();
    static bool AddPlayer(QString _name);
    static double random(double _base, int _difference);
};

#endif // DATASEED_H
