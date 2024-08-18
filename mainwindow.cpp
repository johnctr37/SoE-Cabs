#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QPixmap"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pic(":/resources/img/main-window.jpg");
    ui->label_pic->setPixmap(pic.scaled(1000,400));
 }

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_admin_clicked()
{
    hide();
    admin = new Admin(this);
    admin->show();
    //QMessageBox::about(this,"mytitle","hello");
}


void MainWindow::on_pushButton_customer_clicked()
{
    hide();
    customer = new Customer(this);
    customer->show();
    //QMessageBox::about(this,"mytitle","hellocus");
}

