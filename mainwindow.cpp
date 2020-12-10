#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    screenText = new InputScreen(ui->label, ui->resultLabel);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_zeroButton_clicked()
{
    screenText->showInput(ui->zeroButton);
}

void MainWindow::on_oneButton_clicked()
{
    screenText->showInput(ui->oneButton);
}

void MainWindow::on_twoButton_clicked()
{
    screenText->showInput(ui->twoButton);
}

void MainWindow::on_threeButton_clicked()
{
    screenText->showInput(ui->threeButton);
}

void MainWindow::on_fourButton_clicked()
{
    screenText->showInput(ui->fourButton);
}

void MainWindow::on_fiveButton_clicked()
{
    screenText->showInput(ui->fiveButton);
}

void MainWindow::on_sixButton_clicked()
{
    screenText->showInput(ui->sixButton);
}

void MainWindow::on_sevenButton_clicked()
{
    screenText->showInput(ui->sevenButton);
}

void MainWindow::on_eightButton_clicked()
{
    screenText->showInput(ui->eightButton);
}

void MainWindow::on_nineButton_clicked()
{
    screenText->showInput(ui->nineButton);
}

void MainWindow::on_sumButton_clicked()
{
    screenText->showInput(ui->sumButton);
}

void MainWindow::on_subButton_clicked()
{
    screenText->showInput(ui->subButton);
}

void MainWindow::on_mulButton_clicked()
{
    screenText->showInput(ui->mulButton);
}

void MainWindow::on_divButton_clicked()
{
    screenText->showInput(ui->divButton);
}

void MainWindow::on_clearButton_clicked()
{
    screenText->clearAllScreen();
}

void MainWindow::on_backspaceButton_clicked()
{
    screenText->clearScreen();
}

void MainWindow::on_computeButton_clicked()
{
    screenText->showResult();
}

void MainWindow::on_dotButton_clicked()
{
    screenText->showInput(ui->dotButton);
}
