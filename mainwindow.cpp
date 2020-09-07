#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "banknotes.h"
#include "withdraw.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    setFixedSize(width(), height());
    setWindowTitle("ATM");
    QPalette lcdPalete;
    lcdPalete.setColor(QPalette::Normal, QPalette::WindowText, Qt::green);
    lcdPalete.setColor(QPalette::Normal, QPalette::Window, Qt::black);
    ui->display->setAutoFillBackground(true);
    ui->display->setPalette(lcdPalete);

    displayIndex = 0;
    banknotes = new Banknotes();
    loadBanknotes();
    ui->load10->setFocus();
    withraw = new Withdraw();
    displayString = "0";
}

MainWindow::~MainWindow()
{
    delete banknotes;
    delete withraw;
    delete ui;
}

void MainWindow::on_butt1_clicked()
{
    showValueToDisplay(1);
}

void MainWindow::on_butt2_clicked()
{
    showValueToDisplay(2);
}

void MainWindow::on_butt3_clicked()
{
    showValueToDisplay(3);
}

void MainWindow::on_butt4_clicked()
{
    showValueToDisplay(4);
}

void MainWindow::on_butt5_clicked()
{
    showValueToDisplay(5);
}

void MainWindow::on_butt6_clicked()
{
    showValueToDisplay(6);
}

void MainWindow::on_butt7_clicked()
{
    showValueToDisplay(7);
}

void MainWindow::on_butt8_clicked()
{
    showValueToDisplay(8);
}

void MainWindow::on_butt9_clicked()
{
    showValueToDisplay(9);
}

void MainWindow::on_butt0_clicked()
{
    showValueToDisplay(0);
}

void MainWindow::on_buttWithdraw_clicked()
{
    int currentValue = ui->display->value();

    if (currentValue < 10) {
        ui->infoText->setText("Min withdraw: 10lv.!");
        ui->display->display(10);
        return;
    }

    QMap<int, int> givedBanknotes = withraw->getWithdraw(banknotes, currentValue);
    
    if (givedBanknotes.isEmpty()) {
        clearAll("ATM error!");
    	return;
    }

    ui->gived10->setText(QString::number(givedBanknotes[10]));
    ui->gived20->setText(QString::number(givedBanknotes[20]));
    ui->gived50->setText(QString::number(givedBanknotes[50]));
    ui->gived100->setText(QString::number(givedBanknotes[100]));
    
    ui->display->display(0);
    displayIndex = 0;
    displayString = "0";
    loadBanknotes();
}

void MainWindow::on_buttCancel_clicked()
{
    clearAll("Min withdraw: 10lv., max withdraw: 9990lv.");
}

void MainWindow::showValueToDisplay(int value)
{
    if (displayIndex < 3) {
        displayString.insert(displayString.size() - 1, QString::number(value));
        ui->display->display(displayString);

        if (ui->display->value() > 9990) {
            ui->infoText->setText("Max withdraw: 9990lv.!");
            ui->display->display(9990);
        }
    }

    displayIndex++;
}

void MainWindow::loadBanknotes()
{
    QMap<int, int> banknotesMap = banknotes->getBanknotes();
    ui->loaded10->setText(QString::number(banknotesMap[10]));
    ui->loaded20->setText(QString::number(banknotesMap[20]));
    ui->loaded50->setText(QString::number(banknotesMap[50]));
    ui->loaded100->setText(QString::number(banknotesMap[100]));
    ui->total->setText(QString::number(banknotes->getTotal()));
}

void MainWindow::clearAll(QString infoText)
{
    ui->infoText->setText(infoText);
    ui->gived10->setText(QString::number(0));
    ui->gived20->setText(QString::number(0));
    ui->gived50->setText(QString::number(0));
    ui->gived100->setText(QString::number(0));
    ui->display->display(0);
    displayIndex = 0;
    displayString = "0";
}

void MainWindow::on_loadButton_clicked()
{
    QMap<int, int> banknotesForLoad;
    banknotesForLoad[10] = ui->load10->value();
    banknotesForLoad[20] = ui->load20->value();
    banknotesForLoad[50] = ui->load50->value();
    banknotesForLoad[100] = ui->load100->value();
    banknotes->setBanknotes(banknotesForLoad);
    loadBanknotes();
    ui->load10->setValue(0);
    ui->load20->setValue(0);
    ui->load50->setValue(0);
    ui->load100->setValue(0);
}
