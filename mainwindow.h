#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "banknotes.h"
#include "withdraw.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_butt1_clicked();

    void on_butt2_clicked();

    void on_butt3_clicked();

    void on_butt4_clicked();

    void on_butt5_clicked();

    void on_butt6_clicked();

    void on_butt7_clicked();

    void on_butt8_clicked();

    void on_butt9_clicked();

    void on_butt0_clicked();

    void on_buttWithdraw_clicked();

    void on_buttCancel_clicked();

    void on_loadButton_clicked();

private:
    Ui::MainWindow *ui;

    void showValueToDisplay(int value);
    Banknotes *banknotes;
    void loadBanknotes();
    int displayIndex;
    QString displayString;
    Withdraw *withraw;
    void clearAll(QString infoText);
};
#endif // MAINWINDOW_H
