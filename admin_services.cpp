#include "admin_services.h"
#include "ui_admin_services.h"
#include "global.h"
#include <QFile>
#include <QMessageBox>
#include "mainwindow.h"
#include<QDir>
Admin_services::Admin_services(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin_services)
{
    ui->setupUi(this);
}

Admin_services::~Admin_services()
{
    delete ui;
}


void Admin_services::on_pushButton_admin_logout_clicked()
{
    close();
    MainWindow *w;
    w = new MainWindow(this);
    w->show();
}


void Admin_services::on_pushButton_admin_changefare_clicked()
{
    changefare = new change_taxi_fare(this);
    changefare->show();
}


void Admin_services::on_pushButton_admin_cabstatus_clicked()
{
    if(a.check_cab_status()==1){
        QDir dir=QDir::current();
        QString filePath=dir.filePath("Cab_status.txt");
        QFile MyFile(filePath);
        QTextStream out(&MyFile);
        if(!MyFile.open(QFile::WriteOnly | QFile::Text))
        {
            QMessageBox::warning(this,"title","File is not opened");
        }
        for(int i = 0;i < no_of_cabs; i++){
            if(a.cabs[i] == 1){
                out<< "Cab id = "<<i<<" is available. \n";
            }
            else
                out<< "Cab id = "<<i<<" is not available. \n";
        }
        MyFile.flush();
        MyFile.close();

        cab_status = new Cab_status(this);
        cab_status->show();
    }
    else{
        QMessageBox::information(NULL,"title","No cab is available");
    }
}


void Admin_services::on_pushButton_admin_canceledbookings_clicked()
{
        QDir dir=QDir::current();
        QString Path_cancelrec=dir.filePath("cancelledrecords.txt");
        QFile file(Path_cancelrec);
        if (!file.open(QFile::ReadOnly | QFile::Text)) {
            QMessageBox::warning(this, "Warning", "Cannot open the record for display: " + file.errorString());
            return;
        }

        QTextStream in(&file);
        QString text = in.readAll();
        file.close();

        QMessageBox::information(this, "***Cancelled Bookings***", text);
}


void Admin_services::on_pushButton_admin_customerrecord_clicked()
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

    QMessageBox::information(this, "***Customer Records***", text);

}

