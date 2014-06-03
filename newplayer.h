#ifndef NEWPLAYER_H
#define NEWPLAYER_H

#include <QDialog>
#include "CommonIncludes.h"

namespace Ui {
class NewPlayer;
}
/*!
 * \brief The NewPlayer class okno dodawnia nowego gracza
 */
class NewPlayer : public QDialog
{
    Q_OBJECT

public:
    explicit NewPlayer(QWidget *parent = 0);
    ~NewPlayer();
    QString playerName;

private slots:
    void on_buttonBox_accepted();

private:

    Ui::NewPlayer *ui;
};

#endif // NEWPLAYER_H
