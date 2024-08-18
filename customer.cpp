#include "customer.h"
#include "ui_customer.h"
#include "QMessageBox"
#include "mainwindow.h"
#include "global.h"
#include "QPixmap"

Customer::Customer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Customer)
{
    ui->setupUi(this);
    QPixmap pic(":/resources/img/customer.jpg");
    ui->label_customer->setPixmap(pic.scaled(500,400));
}

Customer::~Customer()
{
    delete ui;
}

void Customer::on_pushButton_customer_login_clicked()
{
    QString username = ui->lineEdit_customer_username->text();
    QString password = ui->lineEdit_customer_password->text();

    if(username == "customer" && password == "customer"){
      hide();
      customer_services = new Customer_services(this);
      customer_services->show();
      //QMessageBox::about(this,"Status","Logged in");
    }
    else{
      QMessageBox::about(this,"Status","Wrong credentials");
    }
}


void Customer::on_pushButton_customer_back_clicked()
{
    close();
    MainWindow *w;
    w = new MainWindow(this);
    w->show();
}


