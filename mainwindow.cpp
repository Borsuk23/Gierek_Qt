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
    this->ui->windowPages->setCurrentWidget(this->ui->blankPage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_game_triggered()
{
    NewGame *popup = new NewGame();

    if( popup->exec() == QDialog::Accepted )
    {
        this->game=popup->game;
        this->refreshContent();
    }
    else if (popup->exec()==QDialog::Rejected)
    {

    }
}

void MainWindow::on_actionExit_triggered()
{
    QMessageBox *msg=new QMessageBox();
    if(game!=NULL)
    {
        msg->setText(game->GetPlayer()->name);
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

void MainWindow::on_playTurnButton_clicked()
{
    this->game->PlayTurn(this->ui->salarySlider->value());
    this->ui->dateDisplay->display(this->game->GetDate());
    this->ui->completeBar->setValue(this->game->Completed());
}

void MainWindow::refreshContent()
{
    //update Mine tab

    //update HR tab

    //fill miners list
    QStandardItemModel *model = new QStandardItemModel();
    ui->minerList->setModel(model);
    for(int i=0; i<game->GetPlayer()->GetMine()->miners.size();i++)
    {
        QStandardItem *item;
            item = new QStandardItem();
            item->setText(game->GetPlayer()->GetMine()->miners[i]->name);
            item->setEditable( false );
            model->appendRow( item );
    }

    //update Market tab

    //fill opponent mines list
    model= new QStandardItemModel();
    ui->competitionList->setModel( model );
    for(int i=0; i<game->GetMarket()->clients.size(); i++)
    {
        QStandardItem *item;
            item = new QStandardItem();
            item->setText(game->GetMarket()->clients[i]->GetName());
            item->setEditable( false );
            model->appendRow( item );
    }

    //fill orders list


    //update general information
    this->ui->budgetDisplayLabel->setText(QString::number(this->game->GetPlayer()->GetMine()->budget));
    this->ui->scoreDisplayLabel->setText(QString::number(this->game->GetPlayer()->score));
    this->ui->salarySlider->setValue(this->game->GetPlayer()->mine->salary);

    this->ui->windowPages->setCurrentWidget(this->ui->gamePage);
}
