#include "customer_services.h"
#include "ui_customer_services.h"
#include "mainwindow.h"
#include "global.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include<QDir>

Customer_services::Customer_services(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Customer_services)
{
    ui->setupUi(this);
}

Customer_services::~Customer_services()
{
    delete ui;
}

void Customer_services::on_pushButton_customer_booking_clicked()
{
    if(a.check_cab_status()==1){
           book = new bookingdestopt(this);
           book->show();
    }
    else{
        close();
        QMessageBox::information(NULL,"title","Cab is not available cannot proceed further");
        Customer_services *customer_services;
        customer_services = new Customer_services(this);
        customer_services->show();
    }
}


void Customer_services::on_pushButton_customer_cabstatus_clicked()
{
    QDir dir=QDir::current();
    QString filePath=dir.filePath("Cab_status.txt");
        QFile file(filePath);
        if (!file.open(QFile::WriteOnly | QFile::Text))
        QMessageBox::warning(this,"Warning","File not open");
        QTextStream out(&file);
        for(int i = 0;i < no_of_cabs; i++){
            if(a.cabs[i] == 1){
                out<< "Cab id = "<<i<<" is available. \n";
            }
            else
                out<< "Cab id = "<<i<<" is not available. \n";
        }
        file.flush();
        file.close();

        cab_status = new Cab_status(this);
        cab_status->show();

}


void Customer_services::on_pushButton_customer_updatestatus_clicked()
{
    int check = 0;
    for(int i=0;i<no_of_cabs;i++){
        if(a.cabs[i] == 1){
            check++;
        }
    }
    if(check == 5){
        QMessageBox::warning(this,"Status","No cabs booked, book a cab first");
    }
    else{
    close();
    update_cab_status = new Update_cab_status(this);
    update_cab_status->show();
    }
}


void Customer_services::on_pushButton_customer_logout_clicked()
{
    close();
    MainWindow *w;
    w = new MainWindow(this);
    w->show();
}


void Customer_services::on_pushButton_customer_travelrecord_clicked()
{
    QDir dir=QDir::current();
    QString filePath=dir.filePath("BookingRecords.txt");
    QFile custfile(filePath);
    if (!custfile.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open the record for display:  " + custfile.errorString());
        return;
    }
    QTextStream in(&custfile);
    QString text = in.readAll();
    custfile.close();

    QMessageBox::information(this, "***Travel Records***", text);
}

