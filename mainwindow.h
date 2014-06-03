#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Game.h"

namespace Ui {
class MainWindow;
}
/*!
 * \brief The MainWindow class główne okno gry
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    explicit MainWindow(QWidget *parent = 0, Game *_game = 0);
    ~MainWindow();

    /*!
     * \brief odświeżanie okna
     *
     * metoda odświeżająca zawartość wszystkich składowych okna
     * uaktualnia niezbędne dane na podstawie modelu gry i jego składowych
     */
    void refreshContent();
    void showStartPage();

private slots:
    void on_actionNew_game_triggered();

    void on_actionExit_triggered();

    void on_actionAbout_triggered();

    void on_playTurnButton_clicked();

    void on_salaryUpdateButton_clicked();

    void on_coalExtractionSlider_valueChanged(int value);

    void on_upgradeStorehouseButton_clicked();


    void on_coalASaleAmountBar_valueChanged(int value);

    void on_coalBSaleAmountBar_valueChanged(int value);

    void on_hireWorkerButton_clicked();

    void on_noticeWorkerButton_clicked();

    void on_coalAStorageUpgrade_stateChanged(int arg1);

    void on_coalBStorageUpgrade_stateChanged(int arg1);

private:
    CoalTypeA *coalA=NULL;
    CoalTypeB *coalB=NULL;
    Game *game=NULL;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
