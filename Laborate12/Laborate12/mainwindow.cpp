#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "abiturient.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->label->setText(ui->lineEdit->text());
}


void MainWindow::on_pb2_clicked()
{
    ui->lbl2->setNum(ui->lineEdit_1->text().toFloat() + ui->lineEdit_2->text().toDouble());
}


void MainWindow::on_Exit_clicked()
{
    QApplication::exit();
}


void MainWindow::on_Abi_Button_clicked()
{
    Abiturient *abi = new Abiturient(ui->le_id->text().toInt(), ui->le_lname->text().toStdString(),
                                     ui->le_name->text().toStdString(), ui->le_fname->text().toStdString(),
                                     ui->le_address->text().toStdString(), ui->le_phone->text().toStdString(),
                                     ui->le_sp->text().toDouble());
    ui->Abit_lbl->setText(QString::fromStdString(abi->toString()));
    delete abi;
}

