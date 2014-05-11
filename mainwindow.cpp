#include "mainwindow.h"
#include "newgame.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QStandardItem>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::MainWindow(QWidget *parent, Game *_game) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->game=_game;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_game_triggered()
{
    NewGame *popup = new NewGame();
    popup->show();

    this->game = new Game(3,4,"Zenon");



    QStandardItemModel *model = new QStandardItemModel();
        ui->competitionList->setModel( model );
        for(int i=0; i<game->GetMarket()->clients.size(); i++)
        {
            QStandardItem *item;
                item = new QStandardItem();
                item->setText(game->GetMarket()->clients[i]->name);
                item->setEditable( false );
                model->appendRow( item );
        }

}

void MainWindow::on_actionExit_triggered()
{
    QMessageBox *msg=new QMessageBox();
    if(game!=NULL)
    {
        msg->setText(QString::number(game->GetGameID()));
        msg->show();
        delete game;
    }
    else
    {
        msg->setText("pusto");
        msg->show();
    }
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox *msg = new QMessageBox();
    msg->about(this,"Gierek","Prosta gra symulująca kopalnię");
}
