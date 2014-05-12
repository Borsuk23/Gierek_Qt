#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    explicit MainWindow(QWidget *parent = 0, Game *_game = 0);
    ~MainWindow();
    void refreshContent();

private slots:
    void on_actionNew_game_triggered();

    void on_actionExit_triggered();

    void on_actionAbout_triggered();

    void on_playTurnButton_clicked();

    void on_salaryUpdateButton_clicked();

    void on_coalExtractionSlider_valueChanged(int value);

    void on_upgradeStorehouseButton_clicked();

private:
    CoalTypeA *coalA=NULL;
    CoalTypeB *coalB=NULL;
    Game *game=NULL;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
