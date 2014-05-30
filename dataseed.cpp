#include "dataseed.h"


QList<QString> DataSeed::ReadPlayersList()
{
    QList<QString> players;
    QFile inputFile("gierekPlayersLog.xml");
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QString temp;
       QTextStream in(&inputFile);
       while ( !in.atEnd() )
       {
          temp = in.readLine();
          if(temp.indexOf("<Player>")!=-1 && temp.indexOf("</Player>")!=-1)
          {
              temp.remove("<Player>");
              temp.remove("</Player>");
              players.append(temp);
          }
       }
       inputFile.close();
    }
    /*
    QList<QString> players;
    std::ifstream inStreamFile;
    inStreamFile.open("gierekPlayersLog.xml");
    if(!inStreamFile.good())
        return players;

    std::string temp="";
    QString subTemp;
    while(!inStreamFile.eof())
    {
        std::getline(inStreamFile, temp);
        subTemp.fromStdString(temp.c_str());
        if(subTemp.indexOf("<Player>")!=-1 && subTemp.indexOf("</Player>")!=-1)
        {
            subTemp.remove("<Player>");
            subTemp.remove("</Player>");
            players.append(subTemp);
        }
    }
    inStreamFile.close();
    */

 return players;
}

bool DataSeed::AddPlayer(QString _name)
{

}

double DataSeed::random(double _base, int _difference)
{
    double temp=rand()%(2*_difference);
    temp= (temp-_difference)/100;
    temp++;
    return _base*temp;

}
