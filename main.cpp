#include "mainwindow.h"
#include "Game.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game *game = NULL;
    MainWindow w(0, game);
    w.show();
    return a.exec();
}
