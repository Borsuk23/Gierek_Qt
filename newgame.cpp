#include "newgame.h"
#include "ui_newgame.h"
#include "newplayer.h"
#include <QMessageBox>

NewGame::NewGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewGame)
{
    ui->setupUi(this);
    this->players=DataSeed::ReadPlayersList();
    this->ui->playerComboBox->addItem("<<Choose player>>");
    for(int i=0; i<this->players.size(); i++)
    {
        this->ui->playerComboBox->addItem(players.at(i));
    }
    this->ui->playerComboBox->addItem("<<Create new player>>");
    this->ui->playerComboBox->setCurrentIndex(1);
}


NewGame::~NewGame()
{
    delete ui;
}

void NewGame::on_buttonBox_accepted()
{
    if(ui->playerComboBox->currentText()=="<<Choose player>>")
    {
        QMessageBox *warning = new QMessageBox();
        warning->about(this,"Warning!", "Choose the player first!");
        delete warning;
    }else
    {
        if(ui->easyRadioButton->isChecked())
        {
            this->game= new Game(1,ui->lenghtComboBox->currentText().toInt(),ui->playerComboBox->currentText());
        }
        else if (ui->mediumRadioButton->isChecked())
        {
            this->game= new Game(2,ui->lenghtComboBox->currentText().toInt(),ui->playerComboBox->currentText());
        }
        else if (ui->hardRadioButton->isChecked())
        {
            this->game= new Game(3,ui->lenghtComboBox->currentText().toInt(),ui->playerComboBox->currentText());
        }
        else
        {
            this->game= new Game(1,ui->lenghtComboBox->currentText().toInt(),ui->playerComboBox->currentText());
        }
        this->accept();
    }



}

void NewGame::on_playerComboBox_activated(const QString &arg1)
{
    if(arg1=="<<Create new player>>")
    {
        NewPlayer *createPlayer = new NewPlayer(this);
        createPlayer->exec();
        this->ui->playerComboBox->setInsertPolicy(QComboBox::InsertBeforeCurrent);
        this->ui->playerComboBox->insertItem(this->ui->playerComboBox->currentIndex(),createPlayer->playerName);

    }
}
