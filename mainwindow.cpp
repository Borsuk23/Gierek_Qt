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
    this->coalA=new CoalTypeA();
    this->coalB=new CoalTypeB();
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
        msg->setText(game->GetPlayer()->GetName());
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
    this->game->PlayTurn();
    this->ui->dateDisplay->display(this->game->GetDate());
    this->ui->completeBar->setValue(this->game->Completed());
    this->refreshContent();
}

void MainWindow::refreshContent()
{
    //update Mine tab

    //coal extraction
    this->ui->coalAExtractionAmountLabel->setText(QString::number((double)(this->ui->coalExtractionSlider->maximum()-this->ui->coalExtractionSlider->value())/(this->ui->coalExtractionSlider->maximum())
                                                                  *(this->game->GetPlayer()->GetMine()->CalculateExtraction(this->coalA))
                                                                  ));

            //(QString::number((this->game->GetPlayer()->GetMine()->CalculateExtraction(this->game->GetPlayer()->GetMine()->extractCoalA)*(1-(this->ui->coalExtractionSlider->maximum()-value)/this->ui->coalExtractionSlider->maximum())))); //extraction *1-coalB%
    this->ui->coalBExtractionAmountLabel->setText(QString::number((double)(this->ui->coalExtractionSlider->value())/(this->ui->coalExtractionSlider->maximum())*
                                                                  (this->game->GetPlayer()->GetMine()->CalculateExtraction(this->coalB))
                                                                  ));

    //coal sale

    //storehouse

    this->ui->coalAStoredBar->setMaximum(this->game->GetPlayer()->GetMine()->GetStorehouse()->GetStorageAmount(this->coalA));
    this->ui->coalBStoredBar->setMaximum(this->game->GetPlayer()->GetMine()->GetStorehouse()->GetStorageAmount(this->coalB));
    this->ui->coalBStoredBar->setValue(this->game->GetPlayer()->GetMine()->GetStorehouse()->GetStoredCoal(this->coalA));
    this->ui->coalBStoredBar->setValue(this->game->GetPlayer()->GetMine()->GetStorehouse()->GetStoredCoal(this->coalB));
    //update HR tab

    //fill miners list
    QStandardItemModel *model = new QStandardItemModel();
    this->ui->minerList->setModel(model);
    for(int i=0; i<game->GetPlayer()->GetMine()->GetMiners().size();i++)
    {
        QStandardItem *item;
            item = new QStandardItem();
            item->setText(game->GetPlayer()->GetMine()->GetMiners()[i]->GetName());
            item->setEditable( false );
            model->appendRow( item );
    }

    this->ui->numberOfMinersLabel->setText(QString::number(this->game->GetPlayer()->GetMine()->GetMiners().size()));
    this->ui->overallSalaryLabel->setText(QString::number(this->game->GetPlayer()->GetMine()->GetOverallSalary()));
    this->ui->moraleLabel->setText(QString::number(this->game->GetPlayer()->GetMine()->GetMorale()));

    //update Market tab

    //fill opponent mines list
    model= new QStandardItemModel();
    ui->competitionList->setModel( model );
    for(int i=0; i<game->GetClients().size(); i++)
    {
        QStandardItem *item;
            item = new QStandardItem();
            item->setText(game->GetClients()[i]->GetName());
            item->setEditable( false );
            model->appendRow( item );
    }

    //fill orders list


    //update general information
    this->ui->budgetDisplayLabel->setText(QString::number(this->game->GetPlayer()->GetMine()->GetBudget()));
    this->ui->scoreDisplayLabel->setText(QString::number(this->game->GetPlayer()->GetScore()));
    this->ui->salarySlider->setValue(this->game->GetPlayer()->GetMine()->GetCurrentSalary());

    this->ui->windowPages->setCurrentWidget(this->ui->gamePage);
}

void MainWindow::on_salaryUpdateButton_clicked()
{
    this->game->GetPlayer()->GetMine()->SetSalary(this->ui->salarySlider->value());
    this->ui->overallSalaryLabel->setText(QString::number(this->game->GetPlayer()->GetMine()->GetOverallSalary()));
}

void MainWindow::on_coalExtractionSlider_valueChanged(int value)
{
    this->ui->coalAExtractionAmountLabel->setText(QString::number((double)(this->ui->coalExtractionSlider->maximum()-value)/(this->ui->coalExtractionSlider->maximum())*
                                                                  (this->game->GetPlayer()->GetMine()->CalculateExtraction(this->coalA))
                                                                  ));

            //(QString::number((this->game->GetPlayer()->GetMine()->CalculateExtraction(this->game->GetPlayer()->GetMine()->extractCoalA)*(1-(this->ui->coalExtractionSlider->maximum()-value)/this->ui->coalExtractionSlider->maximum())))); //extraction *1-coalB%
    this->ui->coalBExtractionAmountLabel->setText(QString::number((double)(value)/(this->ui->coalExtractionSlider->maximum())*
                                                                  (this->game->GetPlayer()->GetMine()->CalculateExtraction(this->coalB))
                                                                  ));

}

void MainWindow::on_upgradeStorehouseButton_clicked()
{
    if(this->ui->coalAStorageUpgrade->isChecked()==true)
    {
        this->game->GetPlayer()->GetMine()->SetBudget(this->game->GetPlayer()->GetMine()->GetStorehouse()->ExtendStorage(this->coalA, this->game->GetPlayer()->GetMine()->GetBudget()));
        this->ui->coalAStorageUpgrade->setChecked(false);
    }
    if(this->ui->coalBStorageUpgrade->isChecked()==true)
    {
        this->game->GetPlayer()->GetMine()->SetBudget(this->game->GetPlayer()->GetMine()->GetStorehouse()->ExtendStorage(this->coalB, this->game->GetPlayer()->GetMine()->GetBudget()));
        this->ui->coalBStorageUpgrade->setChecked(false);
    }
    this->ui->budgetDisplayLabel->setText(QString::number(this->game->GetPlayer()->GetMine()->GetBudget()));
}
