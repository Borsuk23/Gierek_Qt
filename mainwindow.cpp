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

void MainWindow::showStartPage()
{
    this->ui->windowPages->setCurrentWidget(this->ui->blankPage);
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
    if(this->game!=NULL)
    {
        msg->setText(this->game->GetPlayer()->GetName());
        msg->show();
        delete this->game;
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
    this->game->PlayTurn(this->ui->salaryLabel->text().toDouble(),
                         new CoalTypeA(this->ui->coalAExtractionAmountLabel->text().toDouble(),0),
                         new CoalTypeB(this->ui->coalBExtractionAmountLabel->text().toDouble(),0),
                         new CoalTypeA(this->ui->coalASaleAmountLabel->text().toDouble(),this->ui->coalAPriceInput->text().toDouble()),
                         new CoalTypeB(this->ui->coalBSaleAmountLabel->text().toDouble(),this->ui->coalBPriceInput->text().toDouble()));
    this->refreshContent();
    if(this->game->EndGame())
        showStartPage();
}

void MainWindow::refreshContent()
{
    /*!
     *  odświeżanie zakładki Mine
     */
    //coal extraction
    this->ui->coalAExtractionAmountLabel->setText(QString::number((double)(this->ui->coalExtractionSlider->maximum()-this->ui->coalExtractionSlider->value())/(this->ui->coalExtractionSlider->maximum())
                                                                  *(this->game->GetPlayer()->GetMine()->CalculateExtraction(this->coalA))
                                                                  ));

    //(QString::number((this->game->GetPlayer()->GetMine()->CalculateExtraction(this->game->GetPlayer()->GetMine()->extractCoalA)*(1-(this->ui->coalExtractionSlider->maximum()-value)/this->ui->coalExtractionSlider->maximum())))); //extraction *1-coalB%
    this->ui->coalBExtractionAmountLabel->setText(QString::number((double)(this->ui->coalExtractionSlider->value())/(this->ui->coalExtractionSlider->maximum())*
                                                                  (this->game->GetPlayer()->GetMine()->CalculateExtraction(this->coalB))
                                                                  ));

    //coal sale
    this->ui->coalASaleAmountLabel->setText(QString::number((double)(this->ui->coalASaleAmountBar->value()*this->ui->coalAExtractionAmountLabel->text().toDouble()/100)));
    this->ui->coalBSaleAmountLabel->setText(QString::number((double)(this->ui->coalBSaleAmountBar->value()*this->ui->coalBExtractionAmountLabel->text().toDouble()/100)));

    //storehouse

    this->ui->coalAStoredBar->setMaximum(this->game->GetPlayer()->GetMine()->GetStorehouse()->GetStorageAmount(this->coalA));
    this->ui->coalBStoredBar->setMaximum(this->game->GetPlayer()->GetMine()->GetStorehouse()->GetStorageAmount(this->coalB));
    this->ui->coalAStoredBar->setValue(this->game->GetPlayer()->GetMine()->GetStorehouse()->GetStoredCoal(this->coalA));
    this->ui->coalBStoredBar->setValue(this->game->GetPlayer()->GetMine()->GetStorehouse()->GetStoredCoal(this->coalB));
    this->ui->coalAStoredLabel->setText(QString::number(this->game->GetPlayer()->GetMine()->GetStorehouse()->GetStoredCoal(this->coalA)));
    this->ui->coalBStoredLabel->setText(QString::number(this->game->GetPlayer()->GetMine()->GetStorehouse()->GetStoredCoal(this->coalB)));

    this->ui->storageCostLabel->setText(QString::number(this->game->GetPlayer()->GetMine()->GetStorehouse()->GetStorageCost()));


    /*! \brief odświeżanie zakładki HR
     *
     */

    /*! wypełnienie listy górników */
    QStandardItemModel *model = new QStandardItemModel();
    this->ui->minerList->setModel(model);
    for(int i=0; i<game->GetPlayer()->GetMine()->GetMiners().size();i++)
    {
        QStandardItem *item;
            item = new QStandardItem();
            QString minerData = game->GetPlayer()->GetMine()->GetMiners()[i]->GetName();
            minerData.append("  wydajność: ");
            minerData.append(QString::number(game->GetPlayer()->GetMine()->GetMiners()[i]->GetEfficiency(this->coalA)));
            minerData.append("/");
            minerData.append(QString::number(game->GetPlayer()->GetMine()->GetMiners()[i]->GetEfficiency(this->coalB)));
            minerData.append("  morale: ");
            minerData.append(QString::number(game->GetPlayer()->GetMine()->GetMiners()[i]->GetMorale()));
            item->setText(minerData);
            item->setEditable( false );
            model->appendRow( item );
    }

    this->ui->numberOfMinersLabel->setText(QString::number(this->game->GetPlayer()->GetMine()->GetMiners().size()));
    this->ui->overallSalaryLabel->setText(QString::number(this->game->GetPlayer()->GetMine()->GetOverallSalary()));
    this->ui->moraleLabel->setText(QString::number(this->game->GetPlayer()->GetMine()->GetMorale()));

    /*! \brief odświeżanie zakładki Market
     *
     */

    /*! wypełnienie listy zamówień */
    model= new QStandardItemModel();
    ui->ordersList->setModel( model );
    for(int i=0; i<game->GetMarket()->GetOrdersList().size(); i++)
    {
        QStandardItem *item;
            item = new QStandardItem();
            QString orderDetails = game->GetClients().at(i)->GetName();
            orderDetails.append("   ");
            orderDetails.append(QString::number(game->GetMarket()->GetOrdersList().at(i)->GetCoalA()->GetAmount()));
            orderDetails.append("/");
            orderDetails.append(QString::number(game->GetMarket()->GetOrdersList().at(i)->GetCoalA()->GetPrice()));
            orderDetails.append("$  &  ");
            orderDetails.append(QString::number(game->GetMarket()->GetOrdersList().at(i)->GetCoalB()->GetAmount()));
            orderDetails.append("/");
            orderDetails.append(QString::number(game->GetMarket()->GetOrdersList().at(i)->GetCoalB()->GetPrice()));
            orderDetails.append("$");
            item->setText(orderDetails);
            item->setEditable( false );
            model->appendRow( item );
    }

    /*! wypełnienie listy ofert */
    model= new QStandardItemModel();
    ui->competitionList->setModel(model);
    for(int i=0; i<game->GetMarket()->GetOffersList().size(); i++)
    {
        QStandardItem *item;
            item = new QStandardItem();
            QString offerDetails = game->GetMines().at(i)->GetName();
            offerDetails.append("   ");
            offerDetails.append(QString::number(game->GetMarket()->GetOffersList().at(i)->GetCoalA()->GetAmount()));
            offerDetails.append("/");
            offerDetails.append(QString::number(game->GetMarket()->GetOffersList().at(i)->GetCoalA()->GetPrice()));
            offerDetails.append("$  &  ");
            offerDetails.append(QString::number(game->GetMarket()->GetOffersList().at(i)->GetCoalB()->GetAmount()));
            offerDetails.append("/");
            offerDetails.append(QString::number(game->GetMarket()->GetOffersList().at(i)->GetCoalB()->GetPrice()));
            offerDetails.append("$");
            item->setText(offerDetails);
            item->setEditable( false );
            model->appendRow( item );
    }

    /*! wypełnienie podsumowania sprzedaży*/

    this->ui->coalAAveragePrice->setText(QString::number(this->game->GetMarket()->GetStats()->GetCoalA()->GetPrice()));
    this->ui->coalBAveragePrice->setText(QString::number(this->game->GetMarket()->GetStats()->GetCoalB()->GetPrice()));
    this->ui->coalASoldAmount->setText(QString::number(this->game->GetMarket()->GetStats()->GetCoalA()->GetAmount()));
    this->ui->coalBSoldAmount->setText(QString::number(this->game->GetMarket()->GetStats()->GetCoalB()->GetAmount()));

    /*! \brief odświeżanie ogólnych informacji
     *
     */

    this->ui->budgetDisplayLabel->setText(QString::number(this->game->GetPlayer()->GetMine()->GetBudget()/1000000)+"M");
    this->ui->scoreDisplayLabel->setText(QString::number(this->game->GetPlayer()->GetScore()));
    this->ui->salarySlider->setValue(this->game->GetPlayer()->GetMine()->GetCurrentSalary());


    this->ui->dateDisplay->display(this->game->GetDate());
    this->ui->completeBar->setValue(this->game->Completed());
    this->ui->monthLabel->setText(QString::number(this->game->GetDate()%12+1));

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

    this->ui->coalASaleAmountLabel->setText(QString::number(this->ui->coalAExtractionAmountLabel->text().toDouble()*this->ui->coalASaleAmountBar->value()/100));
    this->ui->coalBSaleAmountLabel->setText(QString::number(this->ui->coalBExtractionAmountLabel->text().toDouble()*this->ui->coalBSaleAmountBar->value()/100));
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
    refreshContent();
}

void MainWindow::on_coalASaleAmountBar_valueChanged(int value)
{
    this->ui->coalASaleAmountLabel->setText(QString::number(this->ui->coalAExtractionAmountLabel->text().toDouble()*value/100));
}

void MainWindow::on_coalBSaleAmountBar_valueChanged(int value)
{
    this->ui->coalBSaleAmountLabel->setText(QString::number(this->ui->coalBExtractionAmountLabel->text().toDouble()*value/100));
}

void MainWindow::on_hireWorkerButton_clicked()
{
    this->game->GetPlayer()->HireMiner();
    refreshContent();
}
