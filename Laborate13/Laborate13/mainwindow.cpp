#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QMessageBox>
#include <QDialog>
#include <QFileDialog>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); 
    connect(ui->pb_OpenModal, &QPushButton::clicked, this, &MainWindow::OpenModalDialog);
    connect(ui->pb_OpenNotModal, &QPushButton::clicked, this, &MainWindow::OpenNotModalDialog);
    this->Connected = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OpenModalDialog(){
    QMessageBox *modalWindow = new QMessageBox(this);
    modalWindow->setModal(true);
    modalWindow->setText("Critical Error...");
    modalWindow->show();
}

void MainWindow::OpenNotModalDialog(){
    QDialog *notmodalWindow = new QDialog(this);
    QLabel *label = new QLabel(notmodalWindow);
    label->setText(QFileDialog::getOpenFileName());
    label->show();
    notmodalWindow->show();
}

void MainWindow::on_pushButton_clicked()
{
    if (this->Connected){
        disconnect(ui->pb_OpenModal, &QPushButton::clicked, this, &MainWindow::OpenModalDialog);
        disconnect(ui->pb_OpenNotModal, &QPushButton::clicked, this, &MainWindow::OpenNotModalDialog);
        ui->pushButton->setText("Підключити");
        ui->pushButton->show();
        this->Connected = false;
    }
    else {
        connect(ui->pb_OpenModal, &QPushButton::clicked, this, &MainWindow::OpenModalDialog);
        connect(ui->pb_OpenNotModal, &QPushButton::clicked, this, &MainWindow::OpenNotModalDialog);
        ui->pushButton->setText("Відключити");
        ui->pushButton->show();
        this->Connected = true;
    }
}

