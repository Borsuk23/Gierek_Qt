#include "newplayer.h"
#include "ui_newplayer.h"

NewPlayer::NewPlayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewPlayer)
{
    ui->setupUi(this);
}

NewPlayer::~NewPlayer()
{
    delete ui;
}

void NewPlayer::on_buttonBox_accepted()
{
    this->playerName=this->ui->lineEdit->text();
}
